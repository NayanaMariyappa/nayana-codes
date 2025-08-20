#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

int findSingleNumber(int *arr, int sz)
{
    int xor = 0;
    for (int i = 0; i < sz; i++) xor ^= arr[i];
    return xor;
}

int main(void)
{
    int arr[] = {6, 5, 6, 5, -1};
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    printArray(arr, sz);
    printf("The single number which is not repeated is %d\n", findSingleNumber(arr, sz));

    return 0;
}