
void insert(Tree *tree, int data)
{
    insertNode(tree->root, data);
}

void insertNode(Node *node, int data)
{
    if (node == NULL)
    {
        node = malloc(sizeof(Node));
        node->left = node->right = NULL;
        node->data = data;
        printf("New value: %i\n", node->data);
        return;
    }

    if (data < node->data)
        insertNode(node->left, data);
    else if (data > node->data)
        insertNode(node->right, data);
    else
        printf("Value exists: %i\n", node->data);
}


    // Get root of tree
    Node *curr = tree->root;
    // Parent node to insert node when the right position is found
    Node *parent = NULL;

    if (curr == NULL)
        printf("Root is empty\n");

    // Search for right position for data
    while (curr != NULL)
    {
        if (data == curr->data)
            printf("Value already exists in tree\n");

        parent = curr;
        curr = (data < curr->data) ? curr->left : curr->right;
    }
    
    // Case 1: first value in empty tree
    if (parent == NULL)
    {
        curr = malloc(sizeof(Node));
        curr->left = curr->right = NULL;
        curr->data = data;

        printf("New value: %i\n", curr->data);
    }
    // Case 2: value is less than parent value
    else if (data < parent->data)
    {
        parent->left = malloc(sizeof(Node));
        parent->right = NULL;
        parent->data = data;
    }
    // Case 3: value is greater than parent value
    else if (data > parent->data)
    {
        parent->left = NULL;
        parent->right = malloc(sizeof(Node));
        parent->data = data;
    }
}