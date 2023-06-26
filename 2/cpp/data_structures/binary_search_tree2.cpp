#include<bits/stdc++.h>
using namespace std;
template <class T>
class binary_search_tree {
 private:
    struct bst_node {
        T value; /**< The value/key of the node. */
        unique_ptr<bst_node> left; /**< Pointer to left subtree. */
        unique_ptr<bst_node> right; /**< Pointer to right subtree. */
        explicit bst_node(T _value) {
            value = _value;
            left = nullptr;
            right = nullptr;
        }
    };
    unique_ptr<bst_node> root_; /**< Pointer to the root of the BST. */
    size_t size_ = 0; /**< Number of elements/nodes in the BST. */
    bool find_max(unique_ptr<bst_node>& node, T& ret_value) {
        if (!node) {
            return false;
        } else if (!node->right) {
            ret_value = node->value;
            return true;
        }
        return find_max(node->right, ret_value);
    }
    bool find_min(unique_ptr<bst_node>& node, T& ret_value) {
        if (!node) {
            return false;
        } else if (!node->left) {
            ret_value = node->value;
            return true;
        }

        return find_min(node->left, ret_value);
    }
    bool insert(unique_ptr<bst_node>& node, T new_value) {
        if (root_ == node && !root_) {
            root_ = unique_ptr<bst_node>(new bst_node(new_value));
            return true;
        }

        if (new_value < node->value) {
            if (!node->left) {
                node->left = unique_ptr<bst_node>(new bst_node(new_value));
                return true;
            } else {
                return insert(node->left, new_value);
            }
        } else if (new_value > node->value) {
            if (!node->right) {
                node->right =
                    unique_ptr<bst_node>(new bst_node(new_value));
                return true;
            } else {
                return insert(node->right, new_value);
            }
        } else {
            return false;
        }
    }
    bool remove(unique_ptr<bst_node>& parent,
                unique_ptr<bst_node>& node, T rm_value) {
        if (!node) {
            return false;
        }

        if (node->value == rm_value) {
            if (node->left && node->right) {
                T successor_node_value{};
                find_max(node->left, successor_node_value);
                remove(root_, root_, successor_node_value);
                node->value = successor_node_value;
                return true;
            } else if (node->left || node->right) {
                unique_ptr<bst_node>& non_null =
                    (node->left ? node->left : node->right);

                if (node == root_) {
                    root_ = move(non_null);
                } else if (rm_value < parent->value) {
                    parent->left = move(non_null);
                } else {
                    parent->right = move(non_null);
                }

                return true;
            } else {
                if (node == root_) {
                    root_.reset(nullptr);
                } else if (rm_value < parent->value) {
                    parent->left.reset(nullptr);
                } else {
                    parent->right.reset(nullptr);
                }

                return true;
            }
        } else if (rm_value < node->value) {
            return remove(node, node->left, rm_value);
        } else {
            return remove(node, node->right, rm_value);
        }
    }
    bool contains(unique_ptr<bst_node>& node, T value) {
        if (!node) {
            return false;
        }

        if (value < node->value) {
            return contains(node->left, value);
        } else if (value > node->value) {
            return contains(node->right, value);
        } else {
            return true;
        }
    }
    void traverse_inorder(function<void(T)> callback,
                          unique_ptr<bst_node>& node) {
        if (!node) {
            return;
        }

        traverse_inorder(callback, node->left);
        callback(node->value);
        traverse_inorder(callback, node->right);
    }
    void traverse_preorder(function<void(T)> callback,
                           unique_ptr<bst_node>& node) {
        if (!node) {
            return;
        }

        callback(node->value);
        traverse_preorder(callback, node->left);
        traverse_preorder(callback, node->right);
    }
    void traverse_postorder(function<void(T)> callback,
                            unique_ptr<bst_node>& node) {
        if (!node) {
            return;
        }

        traverse_postorder(callback, node->left);
        traverse_postorder(callback, node->right);
        callback(node->value);
    }

 public:
    binary_search_tree() {
        root_ = nullptr;
        size_ = 0;
    }
bool insert(T new_value) {
        bool result = insert(root_, new_value);
        if (result) {
            size_++;
        }
        return result;
    }
    bool remove(T rm_value) {
        bool result = remove(root_, root_, rm_value);
        if (result) {
            size_--;
        }
        return result;
    }
    bool contains(T value) { return contains(root_, value); }
    bool find_min(T& ret_value) { return find_min(root_, ret_value); }
    bool find_max(T& ret_value) { return find_max(root_, ret_value); }
    size_t size() { return size_; }
    vector<T> get_elements_inorder() {
        vector<T> result;
        traverse_inorder([&](T node_value) { result.push_back(node_value); },
                         root_);
        return result;
    }
    vector<T> get_elements_preorder() {
        vector<T> result;
        traverse_preorder([&](T node_value) { result.push_back(node_value); },
                          root_);
        return result;
    }
    vector<T> get_elements_postorder() {
        vector<T> result;
        traverse_postorder([&](T node_value) { result.push_back(node_value); },
                           root_);
        return result;
    }
};
static void test_insert() {
    cout << "Testing BST insert...";

    binary_search_tree<int> tree;
    bool res = tree.insert(5);
    int min = -1, max = -1;
    assert(res);
    assert(tree.find_max(max));
    assert(tree.find_min(min));
    assert(max == 5);
    assert(min == 5);
    assert(tree.size() == 1);

    tree.insert(4);
    tree.insert(3);
    tree.insert(6);
    assert(tree.find_max(max));
    assert(tree.find_min(min));
    assert(max == 6);
    assert(min == 3);
    assert(tree.size() == 4);

    bool fail_res = tree.insert(4);
    assert(!fail_res);
    assert(tree.size() == 4);

    cout << "ok" << endl;
}
static void test_remove() {
    cout << "Testing BST remove...";

    binary_search_tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);

    bool res = tree.remove(5);
    int min = -1, max = -1;
    assert(res);
    assert(tree.find_max(max));
    assert(tree.find_min(min));
    assert(max == 6);
    assert(min == 3);
    assert(tree.size() == 3);
    assert(tree.contains(5) == false);

    tree.remove(4);
    tree.remove(3);
    tree.remove(6);
    assert(tree.size() == 0);
    assert(tree.contains(6) == false);

    bool fail_res = tree.remove(5);
    assert(!fail_res);
    assert(tree.size() == 0);

    cout << "ok" << endl;
}
static void test_contains() {
    cout << "Testing BST contains...";

    binary_search_tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);

    assert(tree.contains(5));
    assert(tree.contains(4));
    assert(tree.contains(3));
    assert(tree.contains(6));
    assert(!tree.contains(999));

    cout << "ok" << endl;
}
static void test_find_min() {
    cout << "Testing BST find_min...";

    int min = 0;
    binary_search_tree<int> tree;
    assert(!tree.find_min(min));

    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);

    assert(tree.find_min(min));
    assert(min == 3);

    cout << "ok" << endl;
}
static void test_find_max() {
    cout << "Testing BST find_max...";

    int max = 0;
    binary_search_tree<int> tree;
    assert(!tree.find_max(max));

    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);

    assert(tree.find_max(max));
    assert(max == 6);

    cout << "ok" << endl;
}
static void test_get_elements_inorder() {
    cout << "Testing BST get_elements_inorder...";

    binary_search_tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);

    vector<int> expected = {3, 4, 5, 6};
    vector<int> actual = tree.get_elements_inorder();
    assert(actual == expected);

    cout << "ok" << endl;
}
static void test_get_elements_preorder() {
    cout << "Testing BST get_elements_preorder...";

    binary_search_tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);

    vector<int> expected = {5, 4, 3, 6};
    vector<int> actual = tree.get_elements_preorder();
    assert(actual == expected);

    cout << "ok" << endl;
}
static void test_get_elements_postorder() {
    cout << "Testing BST get_elements_postorder...";

    binary_search_tree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(6);

    vector<int> expected = {3, 4, 6, 5};
    vector<int> actual = tree.get_elements_postorder();
    assert(actual == expected);

    cout << "ok" << endl;
}

int main() {
    test_insert();
    test_remove();
    test_contains();
    test_find_max();
    test_find_min();
    test_get_elements_inorder();
    test_get_elements_preorder();
    test_get_elements_postorder();
}
