// Coded by MidhunMike
#include <stdio.h>
#include <stdlib.h>
// Node creation
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insert_begin();
void insert_last();
void insert_loc();
void delete_begin();
void delete_last();
void delete_loc();
void display();

// Main Function
void main()
{
    printf("1.Insert at beginning\n2.Insert at end\n3.Insert at any position\n4.Delete from beginning\n5.Delte from end\n6.Delete from any position\n7.Display\n8.Exit\n");
    int ch = 0;
    while (ch != 8)
    {
        printf("\nEnter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_begin();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_loc();
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_loc();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("invalid choice!please enter valid choice");
        }
    }
}

// Function to insert node at begin
void insert_begin()
{
    struct node *p;
    int value;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter the value :");
        scanf("%d", &value);
        if (head == NULL)
        {
            p->next = NULL;
            p->prev = NULL;
            p->data = value;
            head = p;
        }
        else
        {
            p->data = value;
            p->prev = NULL;
            p->next = head;
            head->prev = p;
            head = p;
        }
    }
}

// Function to insert node at end
void insert_last()
{
    struct node *p, *temp;
    int value;
    p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value :");
    scanf("%d", &value);
    if (head == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        p->data = value;
        head = p;
    }
    else
    {
        temp = head;
        p->data = value;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
        p->next = NULL;
    }
}

// Function to insert a node at any postion
void insert_loc()
{
    struct node *p, *q, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    int value, i, loc;
    if (p == NULL)
    {
        printf("Not Possible");
    }
    else
    {
        temp = head;
        printf("Enter the location to be inserted :");
        scanf("%d", &loc);
        printf("\nenter the value :");
        scanf("%d", &value);
        p->data = value;
        i = 1;
        while (i < loc - 1)
        {
            temp = temp->next;
            i++;
        }
        q = temp;
        if (temp == NULL)
        {
            printf("There are less number of elements");
        }
        else
        {
            p->next = q->next;
            p->prev = q;
            q->next = p;
            q->next->prev = p;
        }
    }
}

// Function to delete a node at begining
void delete_begin()
{
    struct node *p;
    if (head == NULL)
    {
        printf("Deleteion not possible\nList is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("First node deleted");
    }
    else
    {
        p = head;
        head = head->next;
        head->prev = NULL;
        free(p);
        printf("First node deleted");
    }
}

// Function to delete a node at end
void delete_last()
{
    struct node *p, *q;
    if (head == NULL)
    {
        printf("\nNot possible");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
        printf(" Last node is deleted");
    }
}

// Funtion to delete a node at location
void delete_loc()
{
    int i, loc;
    struct node *p, *q;
    printf("Enter the location :");
    scanf("%d", &loc);
    i = 1;
    p = head;
    while (i < loc - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    q->next->prev = p;
    printf(" node deleted");
    free(q);
}

// Function to Display the node
void display()
{
    struct node *p;
    printf("values are: ");
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}