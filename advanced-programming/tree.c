#define EXIT_PROGRAM 0
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree
{
    Node *root;
} Tree;
 
struct Node* createNode(int data)
{
    Node* temp = malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int data)
{
    if (node == NULL)
        return createNode(data);
 
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        printf("Value already exists\n");
 
    return node;
}

int main(void)
{
    int data;
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;

    do
    {
        scanf("%i", &data);

        if (data != EXIT_PROGRAM)
        {
            if (tree->root == NULL)
                tree->root = insert(tree->root, data);
            else
                insert(tree->root, data);
        }
    } while (data != EXIT_PROGRAM);
}