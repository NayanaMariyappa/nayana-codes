#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

int linearSearch(int *arr, int sz, int elem)
{
    int index = -1;

    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == elem) { index = i; break; }
    }
    return index;
}

int main(void)
{
    int arr[] = {78, 56, 8, -1, 22};
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Array: \n");
    printArray(arr, sz);

    for (int i = 0; i < sz; i++)
    {
        int elem = arr[i];
        int index = linearSearch(arr, sz, elem);
        if (index == -1) printf("The %d is not found in the array\n");
        else printf("The index of %d is %d\n", elem, index);
    }

    return 0;
}