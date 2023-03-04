// Coded by MidhunMike

#include <stdio.h>
#include <stdlib.h>
void read(int[10][10], int, int);
void display(int[10][10], int, int);
void add(int[10][10], int[10][10], int, int);
void subtraction(int[10][10], int[10][10], int, int);
void multiplication(int[10][10], int[10][10], int, int, int, int);
void transpose(int[10][10], int[10][10], int, int);

// Main Function
void main()
{
    int c, r, a[10][10], b[10][10], m, n;
    int ch;
    printf("Enter the no of rows and columns\n");
    scanf("%d%d", &r, &c);
    printf("Enter into first matrix\n");
    read(a, r, c);
    printf("Enter into second matrix\n");
    read(b, r, c);
    printf("Matrix A\n");
    display(a, r, c);
    printf("Matrix B\n");
    display(b, r, c);
    m = r;
    n = c;

    do
    {
        printf("\n1-add\n");
        printf("2-subtraction\n");
        printf("3-multiplication\n");
        printf("4-transpose\n");
        printf("5-exit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add(a, b, r, c);
            break;
        case 2:
            subtraction(a, b, r, c);
            break;
        case 3:
            multiplication(a, b, r, c, m, n);
            break;
        case 4:
            transpose(a, b, r, c);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\n\nwrong input\n\n");
            break;
        }
    } while (1);
}

// Function to read value to matrix
void read(int a[10][10], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to display value in funtion
void display(int a[10][10], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrix
void add(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, p[10][10];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            p[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("the resultant matrix is \n");
    display(p, r, c);
}

// Function to subtract two matrix
void subtraction(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, q[10][10];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            q[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("the resultant matrix is\n");
    display(q, r, c);
}

// Function to multiplication of two matrix
void multiplication(int a[10][10], int b[10][10], int r, int c, int m, int n)
{
    int i, j, k, res[10][10];
    if (c == m)
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                res[i][j] = 0;
                for (k = 0; k < c; k++)
                {
                    res[i][j] = a[i][k] * b[k][j];
                }
            }
        }
        printf("the resultant matrix is\n");
        display(res, r, c);
    }
    else
    {
        printf("the multiplication is not possible\n");
    }
}

// Function to transpose two matrix
void transpose(int a[10][10], int b[10][10], int r,
               int c)
{
    int i, j, s1[10][10], s2[10][10];
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            s1[i][j] = a[j][i];
            s2[i][j] = b[j][i];
        }
    }
    printf("transpose of A is\n");
    display(s1, r, c);
    printf("transpose of B is\n");
    display(s2, r, c);
}