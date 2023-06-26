// Project: Doubly_Linked_List.cbp
// File   : main.cpp
#include <iostream>
using namespace std;
template <typename T>
class DoublyNode
{
    public:
        T Value;
        DoublyNode<T> * Previous;
        DoublyNode<T> * Next;
DoublyNode(T value)
    : Value(value), Previous(NULL), Next(NULL) {}
};
template <typename T>
class DoublyLinkedList
{
    private:
        int m_count;
    public:
        DoublyNode<T> * Head,  * Tail;
        DoublyLinkedList(): m_count(0), Head(NULL), Tail(NULL) {}
        DoublyNode<T> * Get(int index){
            if(index < 0 || index > m_count)
                return NULL;
            DoublyNode<T> * node = Head;
            for(int i = 0; i < index; ++i)
                node = node->Next;
            return node;
        }
        void InsertHead(T val){
            DoublyNode<T> * node = new DoublyNode<T>(val);
            node->Next = Head;
            if(Head != NULL)
                Head->Previous = node;
            Head = node;
            if(m_count == 0)
                Tail = Head;
            m_count++;
        }
        void InsertTail(T val){
            if(m_count == 0)
            {
                InsertHead(val);
                return;
            }
            DoublyNode<T> * node = new DoublyNode<T>(val);
            Tail->Next = node;
            node->Previous = Tail;
            Tail = node;
            m_count++;
        }
        void Insert(int index, T val){
            if(index < 0 || index > m_count)
                return;
            if(index == 0)
            {
                InsertHead(val);
                return;
            }
            else if(index == m_count)
            {
                InsertTail(val);
                return;
            }
            DoublyNode<T> * prevNode = Head;
            for(int i = 0; i < index - 1; ++i)
                prevNode = prevNode->Next;
            DoublyNode<T> * nextNode = prevNode->Next;
            DoublyNode<T> * node = new DoublyNode<T>(val);
            node->Next = nextNode;
            node->Previous = prevNode;
            prevNode->Next = node;
            nextNode->Previous = node;
            m_count++;
        }
        int Search(T val){
            if(m_count == 0)
                return -1;
            int index = 0;
            DoublyNode<T> * node = Head;
            while(node->Value != val)
            {
                index++;
                node = node->Next;
                if(node == NULL)
                    return -1;
            }
            return index;
        }
        void RemoveHead(){
            if(m_count == 0)
                return;
            DoublyNode<T> * node = Head;
            Head = Head->Next;
            delete node;
            if(Head != NULL)
                Head->Previous = NULL;
            m_count--;
        }
        void RemoveTail(){
            if(m_count == 0)
                return;
            if(m_count == 1)
            {
                RemoveHead();
                return;
            }
            DoublyNode<T> * node = Tail;
            Tail = Tail->Previous;
            Tail->Next = NULL;
            delete node;
            m_count--;
        }
        void Remove(int index){
            if(m_count == 0)
                return;
            if(index < 0 || index >= m_count)
                return;
            if(index == 0)
            {
                RemoveHead();
                return;
            }
            else if(index == m_count - 1)
            {
                RemoveTail();
                return;
            }
            DoublyNode<T> * prevNode = Head;
            for(int i = 0; i < index - 1; ++i)
                prevNode = prevNode->Next;
            DoublyNode<T> * node = prevNode->Next;
            DoublyNode<T> * nextNode = node->Next;
            prevNode->Next = nextNode;
            nextNode->Previous = prevNode;
            delete node;
            m_count--;
        }
        int Count(){return m_count;}
        void PrintList(){
            DoublyNode<T> * node = Head;

            while(node != NULL)
            {
                cout << node->Value << " -> ";
                node = node->Next;
            }
            cout << "NULL" << endl;
        }
        void PrintListBackward(){
            DoublyNode<T> * node = Tail;
            while(node != NULL)
            {
                cout << node->Value << " -> ";
                node = node->Previous;
            }
            cout << "NULL" << endl;
        }
};
main()
{
    DoublyLinkedList<int> linkedList = DoublyLinkedList<int>();
    // 43->NULL
    linkedList.InsertHead(43);
    // 43->76->NULL
    linkedList.InsertHead(76);
    // 15->43->76->NULL
    linkedList.InsertTail(15);
    // 44->15->43->76->NULL
    linkedList.InsertTail(44);
    cout << "First Printed:" << endl;
    linkedList.PrintListBackward();
    cout << endl;
    // 100->44->15->43->76->NULL
    linkedList.Insert(4, 100);
    // 100->44->48->15->43->76->NULL
    linkedList.Insert(3, 48);
    // 100->44->48->15->43->76->22->NULL
    linkedList.Insert(0, 22);
    cout << "Second Printed:" << endl;
    linkedList.PrintListBackward();
    cout << endl;
}
