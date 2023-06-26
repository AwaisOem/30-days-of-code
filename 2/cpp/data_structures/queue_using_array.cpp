
#include<bits/stdc++.h>
using namespace std;
constexpr uint16_t max_size{10}; 
namespace data_structures {
namespace queue_using_array {
class Queue_Array {
 public:
    void enqueue(const int16_t&);  
    int dequeue();                 
    void display() const;          
 private:
    int8_t front{-1};                     
    int8_t rear{-1};                      
    array<int16_t, max_size> arr{};  
};
void Queue_Array::enqueue(const int16_t& ele) {
    if (rear == arr.size() - 1) {
        cout << "\nStack is full";
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        arr[rear] = ele;
    } else if (rear < arr.size()) {
        ++rear;
        arr[rear] = ele;
    }
}
int Queue_Array::dequeue() {
    int8_t d{0};
    if (front == -1) {
        cout << "\nstack is empty ";
        return 0;
    } else if (front == rear) {
        d = arr.at(front);
        front = rear = -1;
    } else {
        d = arr.at(front++);
    }

    return d;
}
void Queue_Array::display() const {
    if (front == -1) {
        cout << "\nStack is empty";
    } else {
        for (int16_t i{front}; i <= rear; ++i) cout << arr.at(i) << " ";
    }
}

}  // namespace queue_using_array
}  // namespace data_structures
auto main()->int{
    int op{0}, data{0};
    data_structures::queue_using_array::Queue_Array ob;

    cout << "\n1. enqueue(Insertion) ";
    cout << "\n2. dequeue(Deletion)";
    cout << "\n3. Display";
    cout << "\n4. Exit";
    while (true) {
        cout << "\nEnter your choice ";
        cin >> op;
        if (op == 1) {
            cout << "Enter data  ";
            cin >> data;
            ob.enqueue(data);
        } else if (op == 2) {
            data = ob.dequeue();
            cout << "\ndequeue element is:\t" << data;
        } else if (op == 3) {
            ob.display();
        } else if (op == 4) {
            exit(0);
        } else {
            cout << "\nWrong choice ";
        }
    }

    return 0;
}
