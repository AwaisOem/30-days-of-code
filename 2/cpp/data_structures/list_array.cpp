
#include <iostream> /// for io operations
#include <array>   /// for std::array
#include <cassert> /// for assert
namespace data_structures {
namespace list_array {
    struct list {
        std::array<uint64_t, 50> data{}; // Array that implement list
        uint64_t top = 0; // Pointer to the last element
        bool isSorted = false; // indicator whether list is sorted or not
        uint64_t BinarySearch(const std::array<uint64_t, 50> &dataArr, const uint64_t &first, const uint64_t &last,
                              const uint64_t &val) {
            if (last < first) {
                return -1;
            }
            uint64_t mid = (first + last) / 2;
            // check whether current mid pointer value is equal to element or not
            if (dataArr[mid] == val)
                return mid;
                // if current mid value is greater than  element we have to search in first half
            else if (val < dataArr[mid])
                return (BinarySearch(dataArr, first, mid - 1, val));
                // if current mid value is greater than  element we have to search in second half
            else if (val > dataArr[mid])
                return (BinarySearch(dataArr, mid + 1, last, val));

            std::cerr << __func__ << ":" << __LINE__ << ": Undefined condition\n";
            return -1;
        }

        uint64_t LinearSearch(const std::array<uint64_t, 50> &dataArr, const uint64_t &val) const {
            for (uint64_t i = 0; i < top; i++) {
                if (dataArr[i] == val) {
                    return i; // element found at ith index
                }
            }
            return -1;
        }
        uint64_t search(const uint64_t &val) {
            uint64_t pos; // pos variable to store index value of element.
            if (isSorted) {
                pos = BinarySearch(data, 0, top - 1, val);
            } else {
                pos = LinearSearch(data, val);
            }
            if (pos != -1) {
                std::cout << "\nElement found at position : " << pos;
            } else {
                std::cout << "\nElement not found";
            }
            return pos;
        }
        void sort() {
            for (uint64_t i = 0; i < top; i++) {
                uint64_t min_idx = i; // Initialize the min variable
                for (uint64_t j = i + 1; j < top; j++) {
                    if (data[j] < data[min_idx]) {
                        min_idx = j; // update index accordingly
                    }
                }
                std::swap(data[min_idx], data[i]);
            }
            isSorted = true;
        }
        void insert(const uint64_t &val) {
            if (top == 49) {
                std::cout << "\nOverflow";
                return;
            }
            if (!isSorted) {
                data[top] = val;
                top++;
            } else {
                uint64_t pos = 0; // Initialize the index variable
                for (uint64_t i = 0; i < top - 1; i++) {
                    // check for the correct position
                    if (data[i] <= val && val <= data[i + 1]) {
                        pos = i + 1; // assign correct pos to the index var
                        break; // to get out from the loop
                    }
                }
                // if all elements are smaller than the element
                if (pos == 0) {
                    pos = top - 1;
                }
                // shift all element to make a room for new element
                for (uint64_t i = top; i > pos; i--) {
                    data[i] = data[i - 1];
                }
                top++; // Increment the value of top.
                data[pos] = val; // Assign the value to the correct index in the array
            }
        }

        void remove(const uint64_t &val) {
            uint64_t pos = search(val); // search the index of the value
            // if search returns -1, element does not present in the list
            if (pos == -1) {
                std::cout << "\n Element does not present in the list ";
                return;
            }
            std::cout << "\n" << data[pos] << " deleted"; // print the appropriate message
            // shift all the element 1 left to fill vacant space
            for (uint64_t i = pos; i < top; i++) {
                data[i] = data[i + 1];
            }
            top--; // decrement the top variable to maintain last index
        }
        void show() {
            // Going through each element in the list
            std::cout << '\n';
            for (uint64_t i = 0; i < top; i++) {
                std::cout << data[i] << " "; // print the element
            }
        }
    }; // structure list
} // namespace list_array
} // namespace data_structures
static void test() {
    data_structures::list_array::list L;

    // Insert testing
    L.insert(11);
    L.insert(12);
    assert(L.top == 2);
    L.insert(15);
    L.insert(10);
    L.insert(12);
    L.insert(20);
    L.insert(18);
    assert(L.top == 7);
    L.show(); // To print the array

    // Remove testing
    L.remove(12); // Remove Duplicate value in the list
    L.remove(15); // Remove the existing value in the list
    assert(L.top == 5);
    L.remove(50); // Try to remove the non-existing value in the list
    assert(L.top == 5);

    // LinearSearch testing
    assert(L.search(11) == 0); // search for the existing element
    assert(L.search(12) == 2);
    assert(L.search(50) == -1); // search for the non-existing element

    // Sort testing
    L.sort();
    assert(L.isSorted == true);
    L.show();

    // BinarySearch testing
    assert(L.search(11) == 1); // search for the existing element
    assert(L.search(12) == 2);
    assert(L.search(50) == -1); // search for the non-existing element
}
int main() {
    test(); // Execute the tests
    return 0;
}
