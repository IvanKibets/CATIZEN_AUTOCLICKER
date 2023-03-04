// Coded by midhunMike
#include <stdio.h>

// Funtion to perform BinarySearch
int binarySearch(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

// Main Funtion
int main(void)
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d terms in ascending order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter the value to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, n, x);
    if (result == -1)
    {
        printf("Element is not present in array");
    }
    else
    {
        printf("Element is present at index %d", result);
    }

    return 0;
}
