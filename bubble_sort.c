#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int s)
{
    for (int i = 0; i < s; i++) printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *arr, int i, int j)
{
    if (i == j) return;
    /* XOR for swapping is slow; good to use the temp
     * variable as compiler these days does the optimization
     * if temp var is used
     */
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int *arr, int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < s - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                swapped = true;
            }

        if (!swapped) break; // array is already sorted.
    }
}

int main(void)
{
    int arr[] = {6, 7, 88, 98, 2, 32};
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArray(arr, sz);
    bubbleSort(arr, sz);
    printf("Array after sorting: ");
    printArray(arr, sz);

    return 0;
}