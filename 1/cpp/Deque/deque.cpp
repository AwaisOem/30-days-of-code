#include <iostream>
using namespace std;
template <typename T>
class DoublyNode
{
    public:
        T Value;
        DoublyNode<T> * Previous , * Next;
        DoublyNode(T value): Value(value), Previous(NULL), Next(NULL) {}
};


template <typename T>
class Deque
{
private:
    int m_count;
    DoublyNode<T> * m_front;
    DoublyNode<T> * m_back;
public:
    Deque() : m_count(0), m_front(NULL), m_back(NULL) {}
    bool IsEmpty(){ return m_count <= 0;}
    T Front(){return m_front->Value;}
    T Back(){return m_back->Value;}
    void EnqueueFront(T val)
    {
        DoublyNode<T> * node = new DoublyNode<T>(val);
        node->Next = m_front;
        if(m_front != NULL)
            m_front->Previous = node;
        m_front = node;
        if(m_count == 0)
            m_back = m_front;
        m_count++;
    }
    void EnqueueBack(T val){
        if(m_count == 0)
        {
            EnqueueFront(val);
            return;
        }

        DoublyNode<T> * node = new DoublyNode<T>(val);
        m_back->Next = node;
        node->Previous = m_back;
        m_back = node;
        m_count++;
    }
    void DequeueFront(){
    if(m_count == 0)
        return;
    DoublyNode<T> * node = m_front;
    m_front = m_front->Next;
    delete node;
    if(m_front != NULL)
        m_front->Previous = NULL;

    m_count--;
}
    void DequeueBack(){
    if(m_count == 0)
        return;
    if(m_count == 1)
    {
        DequeueFront();
        return;
    }
    DoublyNode<T> * node = m_back;
    m_back = m_back->Previous;
    m_back->Next = NULL;
    delete node;
    m_count--;
}
};
main()
{
    Deque<int> deque = Deque<int>();
    // 26
    deque.EnqueueFront(26);
    // 26 - 78
    deque.EnqueueBack(78);
    // 26 - 78 - 44
    deque.EnqueueBack(44);
    // 91 - 26 - 78 - 44
    deque.EnqueueFront(91);
    // 35 - 91 - 26 - 78 - 44
    deque.EnqueueFront(35);
    // 35 - 91 - 26 - 78 - 44 - 12
    deque.EnqueueBack(12);
    while(!deque.IsEmpty())
    {
        cout << deque.Back() << " - ";
        deque.DequeueBack();
    }
}
