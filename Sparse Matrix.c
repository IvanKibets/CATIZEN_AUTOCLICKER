// Coded by MidhunMike
#include <stdio.h>
void read(int[10][10], int, int);
void display(int[10][10], int, int);
void sparse(int[10][10], int, int, int[20][3]);
void addsparse(int[20][3], int[20][3]);
void transpose(int[20][3], int[20][3]);

// Main Funtcion
void main()
{
    int i, j, a[10][10], b[10][10], m1, n1, m2, n2, s[20][3], t[20][3], s2[20][3], t2[20][3];
    printf("enter row and column of 1st matrix \n");
    scanf("%d%d", &m1, &n1);
    printf("enter 1st matrix \n");
    read(a, m1, n1);
    printf("*1st sparse matrix is*\n");
    display(a, m1, n1);
    printf("*Tuple representation of 1st sparse matrix is*\n");
    sparse(a, m1, n1, s);
    printf("enter row and column of 2nd matrix \n");
    scanf("%d%d", &m2, &n2);
    printf("enter the 2nd matrix \n");
    read(b, m2, n2);
    printf("*2nd sparse matrix is*\n");
    display(b, m2, n2);
    printf("*Tuple representation of 2nd sparse matrix is*\n");
    sparse(b, m2, n2, t);
    printf("*Transpose of tuple of 1st sparse matrix is*\n");
    transpose(s, s2);
    printf("*Transpose of tuple of 2nd sparse matrix is*\n");
    transpose(t, t2);
    addsparse(s, t);
}

// Function to read Matrix
void read(int a[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to Display Matrix
void display(int a[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d \t", a[i][j]);
        }
        printf("\n");
    }
}

// Funtion to change matrix to sparse
void sparse(int a[10][10], int m, int n, int s[20][3])
{
    int i, j, k = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }
    s[0][0] = m;
    s[0][1] = n;
    s[0][2] = k - 1;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }
}

// Function to add two sparse matrix
void addsparse(int s[20][3], int t[20][3])
{
    int r1, r2, c1, c2, a[20][3], m, n, k, i, j;
    r1 = s[0][0];
    c1 = s[0][1];
    r2 = t[0][0];
    c2 = t[0][1];
    if (r1 != r2 || c1 != c2)
    {
        printf("not applicable matrix");
    }
    else
        a[0][0] = s[0][0];
    a[0][1] = s[0][1];
    m = 1;
    n = 1;
    k = 1;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (s[m][0] == i && s[m][1] == j && t[n][0] == i &&
                t[n][1] == j)
            {
                a[k][0] = s[m][0];
                a[k][1] = s[m][1];
                a[k][2] = s[m][2] + t[n][2];
                m++;
                n++;
                k++;
            }
            else if (s[m][0] == i && s[m][1] == j)
            {
                a[k][0] = s[m][0];
                a[k][1] = s[m][1];
                a[k][2] = s[m][2];
                m++;
                k++;
            }
            else if (t[n][0] == i && t[n][1] == j)
            {
                a[k][0] = s[n][0];
                a[k][1] = s[n][1];
                a[k][2] = s[n][2];
                n++;
                k++;
            }
        }
    }
    a[0][2] = k - 1;
    printf("\n");
    printf("resultant tuple after addition : \n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Function to change sparse transpose
void transpose(int b1[][3], int b2[][3])
{
    int i, j, k, n;
    b2[0][0] = b1[0][1];
    b2[0][1] = b1[0][0];
    b2[0][2] = b1[0][2];
    k = 1;
    n = b1[0][2];
    for (i = 0; i < b1[0][1]; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == b1[j][1])
            {
                b2[k][0] = i;
                b2[k][1] = b1[j][0];
                b2[k][2] = b1[j][2];
                k++;
            }
        }
    }
    printf("\nrow\t\tcolumn\t\tvalue\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d\t\t%d\t\t%d\n", b2[i][0], b2[i][1], b2[i][2]);
    }
}
