
#include <cassert>   
#include <iostream>  
#include <queue>     
namespace data_structures {
namespace stack_using_queue {
struct Stack {
    std::queue<int64_t> main_q;       ///< stores the current state of the stack
    std::queue<int64_t> auxiliary_q;  ///< used to carry out intermediate
                                      ///< operations to implement stack
    uint32_t current_size = 0;        ///< stores the current size of the stack
    int top() { return main_q.front(); }

    void push(int val) {
        auxiliary_q.push(val);
        while (!main_q.empty()) {
            auxiliary_q.push(main_q.front());
            main_q.pop();
        }
        swap(main_q, auxiliary_q);
        current_size++;
    }
    void pop() {
        if (main_q.empty()) {
            return;
        }
        main_q.pop();
        current_size--;
    }
    int size() { return current_size; }
};
}  // namespace stack_using_queue
}  // namespace data_structures
static void test() {
    data_structures::stack_using_queue::Stack s;
    s.push(1);  /// insert an element into the stack
    s.push(2);  /// insert an element into the stack
    s.push(3);  /// insert an element into the stack

    assert(s.size() == 3);  /// size should be 3

    assert(s.top() == 3);  /// topmost element in the stack should be 3

    s.pop();               /// remove the topmost element from the stack
    assert(s.top() == 2);  /// topmost element in the stack should now be 2

    s.pop();  /// remove the topmost element from the stack
    assert(s.top() == 1);

    s.push(5);             /// insert an element into the stack
    assert(s.top() == 5);  /// topmost element in the stack should now be 5

    s.pop();               /// remove the topmost element from the stack
    assert(s.top() == 1);  /// topmost element in the stack should now be 1

    assert(s.size() == 1);  /// size should be 1
}
int main() {
    test();  // run
    return 0;
}
