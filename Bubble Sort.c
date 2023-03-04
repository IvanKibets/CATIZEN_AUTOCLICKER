// Coded by MidhunMike
#include <stdio.h>

// Main function
void main()
{
    int a[20], n, flag;
    printf("Enter the limit : ");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp = a[j];
            if (a[j] > a[j + 1])
            {
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Bubble sort Result:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}