#include <algorithm>
#include <iostream>
#include <queue>

struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} node;
node *createNode(int data) {
    node *nn = new node();
    nn->data = data;
    nn->height = 0;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
int height(node *root) {
    if (root == NULL)
        return 0;
    return 1 + std::max(height(root->left), height(root->right));
}
int getBalance(node *root) { return height(root->left) - height(root->right); }
node *rightRotate(node *root) {
    node *t = root->left;
    node *u = t->right;
    t->right = root;
    root->left = u;
    return t;
}
node *leftRotate(node *root) {
    node *t = root->right;
    node *u = t->left;
    t->left = root;
    root->right = u;
    return t;
}
node *minValue(node *root) {
    if (root->left == NULL)
        return root;
    return minValue(root->left);
}
node *insert(node *root, int item) {
    node *nn = createNode(item);
    if (root == NULL)
        return nn;
    if (item < root->data)
        root->left = insert(root->left, item);
    else
        root->right = insert(root->right, item);
    int b = getBalance(root);
    if (b > 1) {
        if (getBalance(root->left) < 0)
            root->left = leftRotate(root->left);  // Left-Right Case
        return rightRotate(root);                 // Left-Left Case
    } else if (b < -1) {
        if (getBalance(root->right) > 0)
            root->right = rightRotate(root->right);  // Right-Left Case
        return leftRotate(root);                     // Right-Right Case
    }
    return root;
}
node *deleteNode(node *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (!root->right) {
            node *temp = root->left;
            delete (root);
            root = NULL;
            return temp;
        } else if (!root->left) {
            node *temp = root->right;
            delete (root);
            root = NULL;
            return temp;
        }
        node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void levelOrder(node *root) {
    std::queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        std::cout << root->data << " ";
        q.pop();
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
}
int main() {
    node *root = NULL;
    int i;
    for (i = 1; i <= 7; i++) root = insert(root, i);
    std::cout << "LevelOrder: ";
    levelOrder(root);
    root = deleteNode(root, 1);
    std::cout << "\nLevelOrder: ";
    levelOrder(root);
    root = deleteNode(root, 4);
    std::cout << "\nLevelOrder: ";
    levelOrder(root);
    return 0;
}
