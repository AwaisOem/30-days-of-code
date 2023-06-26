#include <bits/stdc++.h>
using namespace std;
class BinaryHeap
{
    vector<int> vect;
    int heapSize;
    int p(int i) { return i>>1; } // i/2
    int l(int i) { return i<<1; } // i*2
    int r(int i) { return (i<<1)+1; } // i*2+1
    void ShiftUp(int index){
    if (index == 1)
        return;

    if (vect[index] > vect[p(index)])
    {
        swap(vect[index], vect[p(index)]);

        ShiftUp(p(index));
    }
}
    void ShiftDown(int i){
    if(i > heapSize)
        return;

    int swapId = i;

    if (l(i) <= heapSize && vect[i] < vect[l(i)])
        swapId = l(i);

    if (r(i) <= heapSize && vect[swapId] < vect[r(i)])
        swapId = r(i);

    if (swapId != i)
    {
        swap(vect[i], vect[swapId]);

        ShiftDown(swapId);
    }
}
public:
    BinaryHeap(){
        vect.clear();
        vect.push_back(-1);
        heapSize = 0;
    }
    bool IsEmpty(){return heapSize == 0;}
    void Insert(int key){
        if (heapSize + 1 >= (int)vect.size())
            vect.push_back(0);
        vect[++heapSize] = key;
        ShiftUp(heapSize);
    }
    int ExtractMax(){
        int maxVal = vect[1];
        swap(vect[1], vect[heapSize--]);
        vect.pop_back();
        ShiftDown(1);
        return maxVal;
    }
    int GetMax(){return vect[1];}
};
main()
{
    cout << "Priority Queue" << endl;
    BinaryHeap * pq =  new BinaryHeap();
    cout << "Is queue empty? " << (pq->IsEmpty() ? "TRUE":"FALSE") << endl;

    pq->Insert(14);
    cout << "Insert 14 to queue" << endl;
    cout << "Is queue empty? " << (pq->IsEmpty() ? "TRUE":"FALSE") << endl;
    pq->Insert(53);
    pq->Insert(8);
    pq->Insert(32);
    cout << "Insert 53, 8 and 32 to queue"<< endl;
    cout << "GetMax() = "<< pq->GetMax() << endl;
    cout << "ExtractMax() = "<< pq->ExtractMax()<< endl;
    cout << "GetMax() = "<< pq->GetMax()<< endl;
}
