#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

int binarySearch(int *arr, int sz, int elem)
{
    int left = 0;
    int right = sz - 1;
    int mid = -1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == elem) break;
        if (elem < arr[mid]) { right = mid - 1; continue; }
        else { left = mid + 1; continue; }
    }

    return mid;
}

int main(void)
{
    int arr[] = {-2, -1, 0, 5, 8, 98, 105};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int searchElement = arr[0];
    int index;

    printf("Array: ");
    printArray(arr, sz);
    
    for (int i = 0; i < sz; i++)
    {
        searchElement = arr[i];
        index = binarySearch(arr, sz, searchElement);
        if (index == -1)
            printf("%d is not found in the array\n");
        else
            printf("The index of %d is %d\n", searchElement, index);
    }

    return 0;
}