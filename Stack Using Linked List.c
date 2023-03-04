// Coded by MidhunMike
#include <stdio.h>
#include <stdlib.h>
// Node is Created
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
void push(int);
void pop();
void display();

// Main Funtion
void main()
{
    int choice, value;
    printf("\n:: Stack using Linked List ::\n");
    printf("\n MENU \n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    while (1)
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
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

// Funtion to push an node to the list
void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct
                                           Node));
    newNode->data = value;
    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;
    top = newNode;
    printf("\nInsertion is Success!!!\n");
}

// Funtion to pop an node to the list
void pop()
{
    if (top == NULL)
        printf("\nStack is Empty!!!\n");
    else
    {
        struct Node *temp = top;
        printf("\nDeleted element: %d \n", temp->data);
        top = temp->next;
        free(temp);
    }
}

// Funtion to Display the list
void display()
{
    if (top == NULL)
        printf("\nStack is Empty!!!\n");
    else
    {
        struct Node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n", temp->data);
    }
}