#include <stdio.h>

void printArr(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");    
}

void selectionSort(int arr[], int sz)
{
    int min;
    for (int i = 0; i < sz; i++)
    {
        min = i;
        for (int j = i + 1; j < sz; j++)
        {
            if (arr[j] < arr[min]) min = j;
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main(void)
{
    int arr[] = {64, 25, 12, 22, 11};
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArr(arr, sz);
    selectionSort(arr, sz);
    printf("Array after sorting: ");
    printArr(arr, sz);
    return 0;
}