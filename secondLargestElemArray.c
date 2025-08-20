#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

int findSecondLargest(int *arr, int sz)
{
    int largest = arr[0];
    int secondLargest = -1;

    for (int i = 1; i < sz; i++)
    {
        if (arr[i] > largest) { secondLargest = largest; largest = arr[i]; }
        else if (arr[i] < largest && arr[i] > secondLargest) secondLargest = arr[i];
    }

    return secondLargest;
}

int main(void)
{
    int arr[] = {7, 9, 8, 70, 3, 98};
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    printArray(arr, sz);
    printf("The second largest element in the array is %d\n", findSecondLargest(arr, sz));
    return 0;
}