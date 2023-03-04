// Coded by MidhunMike
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the tree
struct Node *insertNode(struct Node *node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);

    return node;
}

// Function to search for a node in the tree
struct Node *searchNode(struct Node *node, int data)
{
    if (node == NULL || node->data == data)
        return node;

    if (data < node->data)
        return searchNode(node->left, data);
    else
        return searchNode(node->right, data);
}

// Function to delete a node from the tree
struct Node *deleteNode(struct Node *node, int data)
{
    if (node == NULL)
        return node;

    if (data < node->data)
        node->left = deleteNode(node->left, data);
    else if (data > node->data)
        node->right = deleteNode(node->right, data);
    else
    {
        if (node->left == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }

        struct Node *temp = node->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    return node;
}

// Function to print the tree in preorder traversal
void preorderTraversal(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

// Function to print the tree in inorder traversal
void inorderTraversal(struct Node *node)
{
    if (node != NULL)
    {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

// Function to print the tree in postorder traversal
void postorderTraversal(struct Node *node)
{
    if (node != NULL)
    {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%d ", node->data);
    }
}

// Function to free the memory of the tree
void freeTree(struct Node *node)
{
    if (node != NULL)
    {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

// Main function
int main()
{
    struct Node *root = NULL;

    int n;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    int data;
    printf("Enter the data for each node:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);

        root = insertNode(root, data);
    }

    printf("\nBinary tree created successfully!\n");

    // Testing search operation
    printf("\nEnter a value to search in the tree: ");
    scanf("%d", &data);
    struct Node *searchResult = searchNode(root, data);
    if (searchResult == NULL)
        printf("Node with value %d not found in the tree.\n", data);
    else
        printf("Node with value %d found in the tree.\n", data);

    // Testing delete operation
    printf("\nEnter a value to delete from the tree: ");
    scanf("%d", &data);
    root = deleteNode(root, data);
    printf("Node with value %d deleted from the tree.\n", data);

    // Printing the tree in different traversal orders
    printf("\nPreorder Traversal: ");
    preorderTraversal(root);

    printf("\nInorder Traversal: ");
    inorderTraversal(root);

    printf("\nPostorder Traversal: ");
    postorderTraversal(root);

    // Freeing the memory of the tree
    freeTree(root);

    return 0;
}