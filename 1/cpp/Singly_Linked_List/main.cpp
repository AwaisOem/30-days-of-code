#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T Value;
    Node<T> * Next;
    Node(T value) : Value(value), Next(NULL) {}
};

template <typename T>
class LinkedList
{
private:
    int m_count;
    void utilSort(Node<T>*head)
    {
        if(head->Next==NULL){
            Head = head;
            return;
        }
        utilSort(head->Next); 
        head->Next =NULL;
        Node<T> * temp = Head;
        if(temp->Value > head->Value){
            Head = head;
            Head->Next = temp;
        }else{
            Node<T> * prev= temp;
            while(temp!=NULL && temp->Value <= head->Value){
                prev = temp;
                temp =temp->Next;
            }
            head->Next = prev->Next;
            prev->Next = head;
        }
    }
public:
    Node<T> * Head , * Tail;


    void Sort(){if(Head!=NULL)utilSort(Head);}


    LinkedList() : m_count(0), Head(NULL), Tail(NULL) {}


    Node<T> * Get(int index)
    {
        if(index < 0 || index > m_count)
            return NULL;

        Node<T> * node = Head;

        for(int i = 0; i < index; ++i)
        {
            node = node->Next;
        }

        return node;
    }


    void InsertHead(T val)
    {
        Node<T> * node = new Node<T>(val);

        node->Next = Head;

        Head = node;

        if(m_count == 0)
            Tail = Head;

        m_count++;
    }


    void InsertTail(T val)
    {
        if(m_count == 0)
        {
            InsertHead(val);
            return;
        }

        Node<T> * node = new Node<T>(val);

        Tail->Next = node;

        Tail = node;

        m_count++;
    }


    void Insert(int index, T val)
    {
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

        Node<T> * prevNode = Head;

        for(int i = 0; i < index - 1; ++i)
        {
            prevNode = prevNode->Next;
        }

        Node<T> * nextNode = prevNode->Next;

        Node<T> * node = new Node<T>(val);

        node->Next = nextNode;
        prevNode->Next = node;

        m_count++;
    }


    int Search(T val)
    {
        if(m_count == 0)
            return -1;

        int index = 0;

        Node<T> * node = Head;

        while(node->Value != val)
        {
            index++;
            node = node->Next;

            if(node == NULL)
            {
                return -1;
            }
        }

        return index;
    }


    void RemoveHead()
    {
        if(m_count == 0)
            return;

        Node<T> * node = Head;

        Head = Head->Next;

        delete node;

        m_count--;
    }


    void RemoveTail()
    {
        if(m_count == 0)
            return;

        if(m_count == 1)
        {
            RemoveHead();
            return;
        }

        Node<T> * prevNode = Head;

        Node<T> * node = Head->Next;

        while(node->Next != NULL)
        {
            prevNode = prevNode->Next;
            node = node->Next;
        }

        prevNode->Next = NULL;
        Tail = prevNode;

        delete node;

        m_count--;
    }


    void Remove(int index)
    {
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

        Node<T> * prevNode = Head;

        for(int i = 0; i < index - 1; ++i)
        {
            prevNode = prevNode->Next;
        }

        Node<T> * node = prevNode->Next;

        Node<T> * nextNode = node->Next;

        prevNode->Next = nextNode;

        delete node;

        m_count--;
    }


    int Count()
    {
        return m_count;
    }
    void PrintList()
    {
        Node<T> * node = Head;

        while(node != NULL)
        {
            std::cout << node->Value << " -> ";
            node = node->Next;
        }

        std::cout << "NULL" << std::endl;
    }
};
int main()
{
    LinkedList<int> linkedList = LinkedList<int>();

    linkedList.InsertHead(43);

    linkedList.InsertHead(34);

    linkedList.InsertTail(15);

    linkedList.InsertTail(44);

    cout << "First Printed:" << endl;
    linkedList.PrintList();
    cout << endl;

    linkedList.Insert(4, 100);

    linkedList.Insert(3, 48);

    linkedList.Insert(0, 22);

    cout << "Second Printed:" << endl;
    linkedList.PrintList();
    cout << endl;

    linkedList.Sort();
    cout << "Third Printed:" << endl;
    linkedList.PrintList();
    cout << endl;

    cout << "Get value of the second index:" << endl;
    Node<int> * get = linkedList.Get(2);
    if(get != NULL)
        cout << get->Value;
    else
        cout << "not found";
    cout << endl << endl;

    cout << "The position of value 15:" << endl;
    int srch = linkedList.Search(15);
    cout << srch << endl << endl;

    cout << "Remove the first element:" << endl;
    linkedList.Remove(0);
    linkedList.PrintList();
    cout << endl;

    cout << "Remove the fifth element:" << endl;
    linkedList.Remove(4);
    linkedList.PrintList();
    cout << endl;

    cout << "Remove the tenth element:" << endl;
    linkedList.Remove(9);
    linkedList.PrintList();
    cout << endl;
}