#include <iostream>
using namespace std;
class BSTNode
{
public:
    int Key , Height;
    BSTNode * Left, * Right,* Parent;
    BSTNode(int key = 0): Key(key) , Height(0) , Left(NULL), Right(NULL), Parent(NULL){}
};

class BST
{
    private:
        BSTNode * root;

    protected:
        
        BSTNode * Insert(BSTNode * node, int key)
        {
            if(node == NULL)
                node = new BSTNode(key);
            else if(node->Key < key)
            {
                node->Right = Insert(node->Right, key);
                node->Right->Parent = node;
            }
            else
            {
                node->Left = Insert(node->Left, key);
                node->Left->Parent = node;
            }
            return node;
        }
        void PrintTreeInOrder(BSTNode * node)
        {
            if(node == NULL)return;
            PrintTreeInOrder(node->Left);
            cout << node->Key << " ";
            PrintTreeInOrder(node->Right);
        }
        BSTNode * Search(BSTNode * node, int key)
        {
            if (node == NULL)return NULL;
            else if(node->Key == key)
                return node;
            else if(node->Key < key)
                return Search(node->Right, key);
            else
                return Search(node->Left, key);
        }
        int FindMin(BSTNode * node)
        {
            if(node == NULL)
                return -1;
            else if(node->Left == NULL)
                return node->Key;
            else
                return FindMin(node->Left);
        }
        int FindMax(BSTNode * node)
        {
            if(node == NULL)
                return -1;
            else if(node->Right == NULL)
                return node->Key;
            else
                return FindMax(node->Right);
        }
        int Successor(BSTNode * node)
        {
            if (node->Right != NULL)
                return FindMin(node->Right);
            else
            {
                BSTNode * parentNode = node->Parent;
                BSTNode * currentNode = node;
                while ((parentNode != NULL) && (currentNode == parentNode->Right))
                {
                    currentNode = parentNode;
                    parentNode = currentNode->Parent;
                }
                return parentNode == NULL ?
                    -1 :
                    parentNode->Key;
            }
        }
        int Predecessor(BSTNode * node)
        {
            if (node->Left != NULL)
            {
                return FindMax(node->Left);
            }
            else
            {
                BSTNode * parentNode = node->Parent;
                BSTNode * currentNode = node;
                while ((parentNode != NULL) &&
                    (currentNode == parentNode->Left))
                {
                    currentNode = parentNode;
                    parentNode = currentNode->Parent;
                }
                return parentNode == NULL ?
                    -1 :
                    parentNode->Key;
            }
        }
        BSTNode * Remove(BSTNode * node, int key)
        {
            if (node == NULL)
                return NULL;
            if (node->Key == key)
            {
                if (node->Left == NULL && node->Right == NULL)
                    node = NULL;
                else if (node->Left == NULL && node->Right != NULL)
                {
                    node->Right->Parent = node->Parent;

                    node = node->Right;
                }
                else if (node->Left != NULL && node->Right == NULL)
                {
                    node->Left->Parent = node->Parent;

                    node = node->Left;
                }
                else
                {
                    int successorKey = Successor(key);

                    node->Key = successorKey;

                    node->Right = Remove(node->Right, successorKey);
                }
            }
            else if (node->Key < key)
                node->Right = Remove(node->Right, key);
            else
                node->Left = Remove(node->Left, key);
            return node;
        }
    public:
        BST() : root(NULL){}
        void Insert(int key)
        {
            root = Insert(root, key);
        }
        void PrintTreeInOrder()
        {
            PrintTreeInOrder(root);
            cout << endl;
        }
        bool Search(int key)
        {
            BSTNode * result = Search(root, key);
            return result != NULL;
        }
        int FindMin()
        {
            return FindMin(root);
        }
        int FindMax()
        {
            return FindMax(root);
        }
        int Successor(int key)
        {
            BSTNode * keyNode = Search(root, key);
            return keyNode == NULL ? -1 :Successor(keyNode);
        }


        int Predecessor(int key)
        {
            BSTNode * keyNode = Search(root, key);
            return keyNode == NULL ? -1 : Predecessor(keyNode);
        }


        void Remove(int key)
        {
            root = Remove(root, key);
        }
};

class AVL : public BST
{
private:
    BSTNode * root;
public:
AVL() : root(NULL){}
private:
int GetHeight(BSTNode * node)
{
    return node == NULL ? -1 :node->Height;
}

BSTNode * RotateLeft(BSTNode * node)
{

    BSTNode * balancedNode = node->Right;

    balancedNode->Parent = node->Parent;

    node->Parent = balancedNode;

    node->Right = balancedNode->Left;

    if (balancedNode->Left != NULL)
        balancedNode->Left->Parent = node;

    balancedNode->Left = node;

    node->Height = max(
        GetHeight(node->Left),
        GetHeight(node->Right)) + 1;

    balancedNode->Height = max(
        GetHeight(balancedNode->Left),
        GetHeight(balancedNode->Right)) + 1;

    return balancedNode;
}

BSTNode * RotateRight(BSTNode * node)
{

    BSTNode * balancedNode = node->Left;

    balancedNode->Parent = node->Parent;

    node->Parent = balancedNode;

    node->Left = balancedNode->Right;

    if (balancedNode->Right != NULL)
        balancedNode->Right->Parent = node;

    balancedNode->Right = node;

    node->Height = max(
        GetHeight(node->Left),
        GetHeight(node->Right)) + 1;

    balancedNode->Height = max(
        GetHeight(balancedNode->Left),
        GetHeight(balancedNode->Right)) + 1;

    return balancedNode;
}

BSTNode * Insert(BSTNode * node, int key)
{
    if (node == NULL)
        node = new BSTNode(key);
    else if(node->Key < key)
    {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }
    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }

    int balance = GetHeight(node->Left) - GetHeight(node->Right);

    if (balance == 2)
    {
        int balance2 =GetHeight(node->Left->Left) -GetHeight(node->Left->Right);

        if (balance2 == 1)
            node = RotateRight(node);
        else
        {
            node->Left = RotateLeft(node->Left);
            node = RotateRight(node);
        }
    }
    else if (balance == -2)
    {
        int balance2 = GetHeight(node->Right->Left) - GetHeight(node->Right->Right);
        if (balance2 == -1)
            node = RotateLeft(node);
        else
        {
            node->Right = RotateRight(node->Right);
            node = RotateLeft(node);
        }
    }

    node->Height = max(GetHeight(node->Left),GetHeight(node->Right)) + 1;
    return node;
}
BSTNode * Remove(BSTNode * node, int key)
{
    if (node == NULL)
        return NULL;

    if (node->Key == key)
    {
        if (node->Left == NULL && node->Right == NULL)
            node = NULL;
        else if (node->Left == NULL && node->Right != NULL)
        {
            node->Right->Parent = node->Parent;

            node = node->Right;
        }
        else if (node->Left != NULL && node->Right == NULL)
        {
            node->Left->Parent = node->Parent;

            node = node->Left;
        }
        else
        {
            int successorKey = Successor(key);

            node->Key = successorKey;

            node->Right = Remove(node->Right, successorKey);
        }
    }
    else if (node->Key < key)
        node->Right = Remove(node->Right, key);
    else
        node->Left = Remove(node->Left, key);

    if (node != NULL)
    {
        int balance =
            GetHeight(node->Left) - GetHeight(node->Right);

        if (balance == 2)
        {
            int balance2 =
                GetHeight(node->Left->Left) -
                GetHeight(node->Left->Right);

            if (balance2 == 1)
                node = RotateRight(node);
            else
            {
                node->Left = RotateLeft(node->Left);
                node = RotateRight(node);
            }
        }
        else if (balance == -2)
        {
            int balance2 =
                GetHeight(node->Right->Left) -
                GetHeight(node->Right->Right);

            if (balance2 == -1)
                node = RotateLeft(node);
            else{
                node->Right = RotateRight(node->Right);
                node = RotateLeft(node);
            }
        }

        node->Height = max(
            GetHeight(node->Left),
            GetHeight(node->Right)) + 1;

    }

    return node;
}
public:
void Insert(int v)
{
    root = Insert(root, v);
}
void print(){
    PrintTreeInOrder(root);
}
 int Successor(int key)
        {
            BSTNode * keyNode = Search(root, key);
            return keyNode == NULL ? -1 :BST::Successor(keyNode);
        }


int Predecessor(int key)
        {
            BSTNode * keyNode = Search(root, key);
            return keyNode == NULL ? -1 : BST::Predecessor(keyNode);
        }



void Remove(int v)
{
    root = Remove(root, v);
}
};
void testBST(){
   int keys[] = {23, 12, 31, 3, 15, 7, 29, 88, 53};
   BST * tree = new BST;
   for(const int& key : keys)
       tree->Insert(key);
   cout << "Binary Search Tree" << endl;
   cout << "Tree keys: ";
   tree->PrintTreeInOrder();
   cout << "Search key 31: " << (tree->Search(31) ? "found":"NOT found") << endl;
   cout << "Search key 18: " << (tree->Search(18) ? "found":"NOT found") << endl;
   cout << "Min. Key : " << tree->FindMin() << endl;
   cout << "Max. Key : " << tree->FindMax() << endl;
   cout << "Successor(31) = " << tree->Successor(31) << endl;
   cout << "Successor(15) = " << tree->Successor(15) << endl;
   cout << "Successor(88) = " << tree->Successor(88) << endl;
   cout << "Predecessor(12) = "<< tree->Predecessor(12) << endl;
   cout << "Predecessor(29) = "<< tree->Predecessor(29) << endl;
   cout << "Predecessor(3) = " << tree->Predecessor(3) << endl;
   cout << "Removing key 15" << endl;
   tree->Remove(15);
   cout << "Removing key 53" << endl;
   tree->Remove(53);
   cout << "Tree keys: ";
   tree->PrintTreeInOrder();
  delete tree;
}
void testAVL(){
    AVL * avlTree = new AVL;
    cout << "AVL Tree" << endl;
    avlTree->Insert(69);
    avlTree->Insert(62);
    avlTree->Insert(46);
    avlTree->Insert(32);
    avlTree->Insert(24);
    avlTree->Insert(13);
    avlTree->print();
    cout << "Successor(32) = " << avlTree->Successor(32) << endl;
    cout << "Successor(13) = " << avlTree->Successor(13) << endl;
    cout << "Successor(69) = " << avlTree->Successor(69) << endl;
    delete avlTree;
}
main(){
  testAVL();
}