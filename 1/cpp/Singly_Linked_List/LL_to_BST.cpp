#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * left, *right;
    Node(int val):data(val) , left(NULL) , right(NULL){}
};

Node* insertInLL(Node*r , int val)
{
    if(r==NULL)return new Node(val);
    r->left  = insertInLL(r->left , val);
    return r;
}

void displayLL(Node*h){
    if(h==NULL)return;
    cout<<h->data<<" ";
    displayLL(h->left);
}

void displayTree(Node*h){
    if(h==NULL)return;
    displayTree(h->left);
    cout<<h->data<<" ";
    displayTree(h->right);
}
Node* findMid(Node*h , Node* end){
    Node *slow = h  , *fast= h;
    while(fast!=end && fast->left!=end){
        slow = slow->left;
        fast = fast->left->left;
    }
    return slow;
}
void Coversion(Node*h  ,Node*end , Node*&r){
    if(h==NULL || h==end) return;
    Node* temp = findMid(h , end);
    r = new Node(temp->data);
    Coversion(h , temp, r->left = NULL);
    Coversion(temp->left , end, r->right  = NULL);
}

auto main()->int
{
    Node * head  = new Node(2);
    head  = insertInLL(head, 4);
    head  = insertInLL(head , 6);
    head  = insertInLL(head , 8);
    head  = insertInLL(head ,10);
    displayLL(head);
    Node*root  = NULL;
    Coversion(head , NULL  , root);
    cout<<endl;
    displayTree(root);
    return EXIT_SUCCESS;   
}