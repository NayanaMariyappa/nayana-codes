#include <stdio.h>

void printArr(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[] = {64, 25, 12, 22, 11};
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArr(arr, sz);
    bubbleSort(arr, sz);
    printf("Array after sorting: ");
    printArr(arr, sz);
    return 0;
}