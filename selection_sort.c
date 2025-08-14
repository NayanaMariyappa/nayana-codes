#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int s)
{
    for (int i = 0; i < s; i++) printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *arr, int i, int min)
{
    if (i == min) return;

    arr[i] ^= arr[min];
    arr[min] ^= arr[i];
    arr[i] ^= arr[min];
}

void selectionSort(int *arr, int s)
{
    for (int i = 0; i < s; i++)
    {
        int min = i;
        for (int j = i + 1; j < s; j++) if (arr[j] < arr[min]) min = j;
        swap(arr, i, min);
    }
}

int main(void)
{
    int arr[] = {3, 22, 5, 0, 9, 88, 76};
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArray(arr, sz);

    selectionSort(arr, sz);
    printf("Array after sorting: ");
    printArray(arr, sz);

    return 0;
}