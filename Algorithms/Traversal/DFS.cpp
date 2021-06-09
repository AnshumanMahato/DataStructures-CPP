#include <bits/stdc++.h>

struct node
{
    int value;
    node *left, *right;
};

class BST
{
private:
    node *root;
public:
    BST();
    ~BST();
    void insert(int);
    node* lookup(int);
    node* remove(int);
    void DFS(int);
    void traversePreorder(node*,std::vector<int>&);
    void traverseInorder(node*,std::vector<int>&);
    void traversePostorder(node*,std::vector<int>&);
};

BST::BST()
{
    this->root = NULL;
}

BST::~BST()
{
}

void BST::insert(int value)
{
    node *temp = new node;
    temp->value = value;
    temp->left = temp->right = NULL;

    if(root == NULL)
        root = temp;
    else
    {
        node *itr = root;
        while(true)
        {
            if(value > itr->value)
            {
                if(itr->right == NULL)
                {
                    itr->right = temp;
                    break;
                }
                else    
                    itr = itr->right;
            }

            else if (value < itr->value)
            {
                if(itr->left == NULL)
                {
                    itr->left = temp;
                    break;
                }
                else    
                    itr = itr->left;
            }
            
            else
            {
                delete temp;
                break;
            }
        }
    }
}

node* BST::lookup(int value)
{
    node *itr = root;
    while(itr != NULL)
    {
        if(value == itr->value)
            return itr;
        if(value > itr->value)    
            itr = itr->right;
        else if (itr->value < value)
            itr = itr->left;
    }

    return NULL;
}

node* BST::remove(int value)
{
    /*this is weird*/ 
}

void BST::traversePreorder(node* currentNode,std::vector<int>& list)
{
    list.push_back(currentNode->value);
    if(currentNode->left)
        traversePreorder(currentNode->left,list);
    if(currentNode->right)
        traversePreorder(currentNode->right,list);
}

void BST::traverseInorder(node* currentNode,std::vector<int>& list)
{
    if(currentNode->left)
        traverseInorder(currentNode->left,list);
    list.push_back(currentNode->value);
    if(currentNode->right)
        traverseInorder(currentNode->right,list);
}

void BST::traversePostorder(node* currentNode,std::vector<int>& list)
{
    if(currentNode->left)
        traversePostorder(currentNode->left,list);
    if(currentNode->right)
        traversePostorder(currentNode->right,list);
    list.push_back(currentNode->value);
}

void BST::DFS(int key)
{
    std::vector<int> list;

    if(key == 1)
        traversePreorder(root,list);
    if(key == 2)
        traverseInorder(root,list);
    if(key == 3)
        traversePostorder(root,list);

    for(int i = 0; i < list.size(); i++) 
        std::cout<<list[i]<<' ';

    std::cout<<std::endl;
}

int main()
{
    BST b;
    b.insert(9);
    b.insert(4);
    b.insert(6);
    b.insert(20);
    b.insert(170);
    b.insert(15);
    b.insert(1);

    b.DFS(1);
    b.DFS(2);
    b.DFS(3);

    return 0;
}