// Coded by MidhunMike
#include <stdlib.h>
#include <stdio.h>
#define max 6 // Size of Queue fixed 6
int queue[max];
int front = -1;
int rear = -1;

// Function to Enqueue an element to Queue
void enqueue()
{
    int x;
    printf("Enter the element which is to be inserted :");
    scanf("%d", &x);
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % max == front)
    {
        printf("Queue is overflow..");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = x;
    }
}

// Function to Dequeue an element from Queue
int dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is underflow..");
    }
    else if (front == rear)
    {
        printf("\nThe dequeued element is %d",
               queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nThe dequeued element is %d",
               queue[front]);
        front = (front + 1) % max;
    }
}

// Function to Display  element in Queue
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty..");
    }
    else
    {
        printf("\nElements in a Queue are :");
        for (i; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

// Main function
int main()
{
    printf("\nQueue Limit is fixed 6\n");
    printf("**********************\n");
    printf("\nPress 1: Insert an element");
    printf("\nPress 2: Delete an element");
    printf("\nPress 3: Display the elements");
    printf("\nPress 4: Exit");
    int choice, x;
    while (1)
    {
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice!!");
        }
    }
    return 0;
}