#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int *arr, int sz)
{
    for (int i = 1; i < sz; i++)
    {
        int save = arr[i];
        int j = i - 1;

        while(j >=0 && save < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = save;
    }
}

int main(void)
{
    int arr[] = {3, 58, 0, 32, 45, 7};
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArray(arr, sz);
    insertionSort(arr, sz);
    printf("Array after sorting: ");
    printArray(arr, sz);

    return 0;
}