#include <cstddef>
#include <iostream>
#include "NodeT.h"

using namespace std;

class BST
{
private:
    NodeT* root;
    int pred(NodeT* r);
    int succ(NodeT* r);
    void preOrder(NodeT *r);
    void inOrder(NodeT* r);
    void postOrder(NodeT* r);
public:
    BST(/* args */);
    ~BST();
    void add(int data);
    bool search(int data);
    void remove(int data);
    int children(NodeT* r);
    void print(int x);
};

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
}

void BST::add(int data)
{
    NodeT* curr = root;
    NodeT* parent = NULL;
    
    while (curr != NULL)
    {
        parent = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
        
        if (parent == NULL)
            root = new NodeT(data);
        else
        {
            if (parent->getData() > data)
                parent->setLeft(new NodeT(data));
            else
                parent->setRight(new NodeT(data));
        }
    }
    
}

bool BST::search(int data)
{
    NodeT* curr = root;

    while(curr != NULL)
    {
        if (curr->getData() == data)
            return true;

        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
        
    return false;
}

int BST::children(NodeT* r)
{
    int count = 0;
    if (r->getLeft() != NULL)
        count++;
    if (r->getRight() != NULL)
        count++;

    return count;
}

void BST::remove(int data)
{
    NodeT* curr = root;
    NodeT* parent = NULL;

    while( curr != NULL && curr->getData() != data)
    {
        parent = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    if (curr == NULL)
        return;

    int c = children(curr);

    switch (c)
    {
    case 0:
        if (parent == NULL)
            root = NULL;
        else
        {
            if (parent->getData() > data)
                parent->setLeft(NULL);
            else
                parent->setRight(NULL);
        }
        
        break;
    case 1:
        if (parent == NULL)
        {
            if (curr->getLeft() != NULL)
                root = curr->getLeft();
            else
               root = curr->getRight();
        }
        else
        {
            if (parent->getData() > data)
            {
                if (curr->getLeft() != NULL)
                    parent->setLeft(curr->getLeft());
                else
                    parent->setLeft(curr->getRight());
            }
            else
            {
                if (curr->getLeft() != NULL)
                    parent->setRight(curr->getLeft());
                else
                    parent->setRight(curr->getRight());
            }
        }
        break;
    case 2:
        break;
    default:
        break;
    }
}

int BST::pred(NodeT* r)
{
    NodeT* curr= r->getLeft();
    while (curr->getRight() != NULL)
        curr = curr->getRight();

    return curr->getData();
}

int BST::succ(NodeT* r)
{
    NodeT* curr = r->getRight();
    while(curr->getLeft() != NULL)
        curr = curr->getLeft();

    return curr->getData();
}

void BST::preOrder(NodeT *r)
{
    if (r != NULL)
    {
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT* r)
{
    if (r != NULL)
    {
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT* r)
{
    
    if (r != NULL)
    {
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::print(int x)
{
    switch (x)
    {
    case 1:
        preOrder(root);
        break;
    case 2:
        inOrder(root);
        break;
    case 3:
        postOrder(root);
        break;
    default:
        break;
    }
}