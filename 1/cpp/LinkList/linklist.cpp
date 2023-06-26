#include <iostream>
using namespace std;
class List
{
    private:
        int m_count;
        int * m_items;
    public:
    List(): m_count(0) {}
    int Get(int index)
    {
        if(index < 0 || index > m_count)
            return -1;
        return m_items[index];
    }
    void Insert(int index, int val)
    {
        if(index < 0 || index > m_count)
            return;
        int * oldArray = m_items;
        m_count++;
        m_items = new int[m_count];
        for(int i=0, j=0; i < m_count; ++i)
        {
            if(index == i)
            {
                m_items[i] = val;
            }
            else
            {
                m_items[i] = oldArray[j];
                ++j;
            }
        }
        delete [] oldArray;
    }

    int Search(int val)
    {
        for(int i=0; i < m_count; ++i)
            if(m_items[i] == val)
                return i;
        return -1;
    }
    void Remove(int index)
    {
        if(index < 0 || index > m_count)
            return;
        int * oldArray = m_items;
        m_count--;
        m_items = new int[m_count];
        for(int i=0, j=0; i < m_count; ++i, ++j)
        {
            if(index == j)++j;
            m_items[i] = oldArray[j];
        }
        delete [] oldArray;
    }
    int Count()
    {
        return m_count;
    }
    ~List()
    {
        delete[] m_items;
        m_items = NULL;
    }
};


int main()
{
    List list = List();
    list.Insert(0, 21);
    list.Insert(1, 47);
    list.Insert(2, 87);
    list.Insert(3, 35);
    list.Insert(4, 92);
    cout << "List elements:" << endl;
    for(int i = 0; i < list.Count(); ++i)
        cout << list.Get(i) << " ";
    cout << endl << endl;
    list.Insert(2, 25);
    list.Insert(2, 71);
    cout << "New List elements:" << endl;
    for(int i = 0; i < list.Count(); ++i)
        cout << list.Get(i) << " ";
    cout << endl << endl;
    cout << "Search element 71" << endl;
    int result = list.Search(71);
    if(result == -1)
        cout << "71 is not found";
    else
        cout << "71 is found at index " << result;
    cout << endl << endl;
    cout << "Remove element at index 2" << endl;
    list.Remove(2);
    cout << endl;
    cout << "New List elements:" << endl;
    for(int i = 0; i < list.Count(); ++i)
        cout << list.Get(i) << " ";
    cout << endl << endl;
    cout << "Search element 71 again" << endl;
    result = list.Search(71);
    if(result == -1)
        cout << "71 is not found";
    else
        cout << "71 is found at index " << result;
    cout << endl;
}