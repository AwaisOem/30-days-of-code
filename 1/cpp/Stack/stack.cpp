#include <iostream>
using namespace std;
template <typename T>
class Node
{public:
    T Value;
    Node<T> * Next;
    Node(T value): Value(value), Next(NULL) {}
};
template <typename T>
class Stack
{
private:
    int m_count;
    Node<T> * m_top;
public:
    Stack() : m_count(0), m_top(NULL) {}
    bool IsEmpty(){return m_count <= 0;}
    T Top(){
        return m_top->Value;
    }
    void Push(T val)
    {
        Node<T> * node = new Node<T>(val);
        node->Next = m_top;
        m_top = node;
        m_count++;
    }
    void Pop()
    {
        if(IsEmpty())return;
        Node<T> * node = m_top;
        m_top = m_top->Next;
        delete node;
        m_count--;
    }
};
int main()
{
    Stack<int> stackInt = Stack<int>();
    stackInt.Push(32);
    stackInt.Push(47);
    stackInt.Push(18);
    stackInt.Push(59);
    stackInt.Push(88);
    stackInt.Push(91);
    while(!stackInt.IsEmpty())
    {
        cout << stackInt.Top() << " - ";
        stackInt.Pop();
    }
}
