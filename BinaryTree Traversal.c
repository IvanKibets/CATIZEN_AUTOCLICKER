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

    printf("Preorder traversal of the binary search tree: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the binary search tree: ");
    postorderTraversal(root);
    printf("\n");

    // Free the memory used by the tree
    freeTree(root);

    return 0;
}
