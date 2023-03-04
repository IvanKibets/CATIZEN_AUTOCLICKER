// Coded by MidhunMike
#include <stdio.h>
#include <stdlib.h>
void enqueue();
void dequeue();
void display();
int queue[50];
int rear = -1;
int front = -1;
int n;

// Main Function
void main()
{
    int choice;
    printf("enter the size of queue :");
    scanf("%d", &n);
    do
    {
        printf("\n********QUEUE OPERATIONS********\n");
        printf("1.Enqueue element into queue\n2.Dequeue element from queue\n3.Display all elements\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid option\n");
        }
    } while (1);
}

// Function to enqueue an element to queue
void enqueue()
{
    int item;
    if (rear == n - 1)
    {
        printf("\nQueue Overflow\n");
    }
    else if (front == -1)
    {
        front = 0;
        printf("Enter the element to be inserted");
        scanf("%d", &item);
        rear = rear + 1;
        queue[rear] = item;
    }
    else
    {
        printf("Enter the element to be entered");
        scanf("%d", &item);
        rear = rear + 1;
        queue[rear] = item;
    }
}

// Function to Dequeue an element from queue
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\nElement delete from queue id %d\n", queue[front]);
        front = front + 1;
    }
}

// Function to Dispaly elements in the queue
void display()
{
    int i;
    if (front == -1)
    {
        printf("\nqueue is empty\n");
    }
    else
    {
        printf("\nQueue is:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}