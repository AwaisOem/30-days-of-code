#include <iostream>
using namespace std;
#define TABLE_SIZE 7
class HashElement
{
    public:
        int Key;
        string Value;
        HashElement(int key, string value) :  Key (key) , Value(value){}
};

class HashTable
{
    private:
        int currentSize;
        HashElement **arr;
        HashElement * deletedElement;

        int HashFunction(int key)
        {
            return key % TABLE_SIZE;
        }
    public:
        HashTable()
        {
            // Initialize current size as 0
            currentSize = 0;

            // Initialize table
            arr = new HashElement * [TABLE_SIZE];
            for(int i = 0 ; i < TABLE_SIZE ; ++i)
                arr[i] = NULL;

            // Specify deleted node content
            deletedElement = new HashElement(-1, "");
        }

        void Insert(int key, string value)
        {
            // It's impossible to store a new element
            // if hash table doesn't have free space
            if (currentSize >= TABLE_SIZE)
                return;

            // Create a temporary element
            // to be inserted to hash table
            HashElement * temp =
                new HashElement(key, value);

            // Get hash key from hash function
            int hashIndex = HashFunction(key);

            // Find next free space
            // using linear probing
            while(arr[hashIndex] != NULL &&
                arr[hashIndex]->Key != key &&
                arr[hashIndex]->Key != -1)
            {
                ++hashIndex;
                hashIndex %= TABLE_SIZE;
            }

            // If there's new element to be inserted
            // then increase the current size
            if(arr[hashIndex] == NULL ||
                arr[hashIndex]->Key == -1)
            {
                ++currentSize;
                arr[hashIndex] = temp;
            }
        }

        string Search(int key)
        {
            // Get hash key from hash function
            int hashIndex = HashFunction(key);

            // Find the element with given key
            while(arr[hashIndex] != NULL &&
                arr[hashIndex]->Key != deletedElement->Key)
            {
                // If element is found
                // then return its value
                if(arr[hashIndex]->Key == key)
                    return arr[hashIndex]->Value;

                // Keep looking for the key
                // using linear probing
                ++hashIndex;
                hashIndex %= TABLE_SIZE;
            }

            //If not found return null
            return "";
        }

        void Remove(int key)
        {
            // Get hash key from hash function
            int hashIndex = HashFunction(key);

            // Find the element with given key
            while(arr[hashIndex] != NULL)
            {
                // If element is found
                // then mark the cell as deletedElement
                if(arr[hashIndex]->Key == key)
                {
                    arr[hashIndex] = deletedElement;

                    // Reduce size
                    --currentSize;

                    // No need to search anymore
                    return;
                }

                // Keep looking for the key
                // using linear probing
                ++hashIndex;
                hashIndex %= TABLE_SIZE;
            }

            // Note: if key is not found just do nothing
        }

        bool IsEmpty()
        {
            return currentSize == 0;
        }

        void PrintHashTable()
        {
            // Iterate through array
            for(int i = 0 ; i < currentSize; ++i)
            {
                // Just print the element
                // if it exist
                if(arr[i] != NULL && arr[i]->Key != -1)
                {
                    cout << "Cell: " << i;
                    cout << " Key: " << arr[i]->Key;
                    cout << " Value: " << arr[i]->Value;
                    cout << endl;
                }
            }
        }
};
int main()
{
    cout << "Hash Table - Open Addressing - Linear Probe";
    cout << endl;

    HashTable * hashTable = new HashTable();

    // Check if hash table is empty
    bool b = hashTable->IsEmpty();
    if(b)
        cout << "Hash table is empty";
    else
        cout << "Hash table is not empty";
    cout << endl;

    // Adding a data then
    // check if hash table is empty
    cout << "Adding a data" << endl;
    hashTable->Insert(434, "Dylan");
    b = hashTable->IsEmpty();
    if(b)
        cout << "Hash table is empty";
    else
        cout << "Hash table is not empty";
    cout << endl;

    // Adding others data
    hashTable->Insert(391, "Dominic");
    hashTable->Insert(806, "Adam");
    hashTable->Insert(117, "Lindsey");
    hashTable->Insert(548, "Cameron");
    hashTable->Insert(669, "Terry");
    hashTable->Insert(722, "Brynn");
    hashTable->Insert(276, "Jody");
    hashTable->Insert(953, "Frankie");
    hashTable->Insert(895, "Vanessa");

    // Print the table
    hashTable->PrintHashTable();

    // Search key 669
    // it should be found
    int key = 669;
    cout << "Search value for key ";
    cout << key << endl;
    string name = hashTable->Search(key);
    if(name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }
    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }
    cout << endl;

    // Remove key 669
    // then search the key
    // it should not be found
    cout << "Remove node of key ";
    cout << key << endl;
    hashTable->Remove(key);
    name = hashTable->Search(key);
    if(name != "")
    {
        cout << "Value for key " << key;
        cout << " is " << name;
    }
    else
    {
        cout << "Value for key " << key;
        cout << " is not found";
    }
    cout << endl;

    return 0;
}
