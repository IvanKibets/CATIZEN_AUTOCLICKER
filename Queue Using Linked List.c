// Coded by MidhunMike
#include <stdio.h>
#include <stdlib.h>

// Node is created
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;
void insert(int);
void delete();
void display();

// Main Funtion
void main()
{
    int choice, value;
    printf("\n:: Queue Implementation using Linked List::\n");
    printf("\n MENU \n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}

// Function to Enqueue a node into the list
void insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nInsertion is Success!!!\n");
}

// Function to Dequeue a node from the list
void delete()
{
    if (front == NULL)
        printf("\nQueue is Empty!!!\n");
    else
    {
        struct Node *temp = front;
        front = front->next;
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
    }
}

// Funtion to Display
void display()
{
    if (front == NULL)
        printf("\nQueue is Empty!!!\n");
    else
    {
        struct Node *temp = front;
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n", temp->data);
    }
}