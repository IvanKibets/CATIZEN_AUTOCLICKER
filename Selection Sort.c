// coded by midhunMike
#include <stdio.h>

// Function for selectionsort
void selection(int arr[], int n)
{
    int i, j, small;
    for (i = 0; i < n - 1; i++)
    {
        small = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[small])
                small = j;
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}

// Funtion for Display
void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

// Main Funtion
int main()
{
    int a[50], n;
    printf("Enter the limit: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before sorting array elements are - \n");
    printArr(a, n);
    selection(a, n);
    printf("\nAfter sorting array elements are - \n");
    printArr(a, n);
    return 0;
}