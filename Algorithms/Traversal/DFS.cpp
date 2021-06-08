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
    void traverse();
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

void BST::traverse()
{

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

    b.traverse();

    return 0;
}