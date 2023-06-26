#include <iostream>
using namespace std;
int main()
{
    int arrLength = 5;
    int * ptr = new int[arrLength] { 21, 47, 87, 35, 92 };
    cout << "Using pointer increment" << endl;
    cout << "Value\tAddress" << endl;
    while(*ptr)
    {
        cout << *ptr << "\t";
        cout << ptr << endl;
        ptr++;
    }
    cout << endl;
    ptr = ptr - 5;
    cout << "Using pointer index" << endl;
    cout << "Value\tAddress" << endl;
    for(int i = 0; i < arrLength; ++i)
    {
        cout << ptr[i] << "\t";
        cout << &ptr[i] << endl;
    }
    return 0;
}
