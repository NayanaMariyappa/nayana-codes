#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

void threeGreatestCandidates(int *arr, int sz, int *ret)
{
    int max1 = arr[0];
    int max2 = arr[0];
    int max3 = arr[0];

    for (int i = 1; i < sz; i++)
    {
        if (arr[i] > max1) { max3 = max2; max2 = max1; max1 = arr[i];}
        else if (arr[i] > max2) { max3 = max2; max2 = arr[i]; }
        else if (arr[i] > max3) max3 = arr[i];
    }

    ret[0] = max1; ret[1] = max2; ret[2] = max3;
}

int main(void)
{
    int arr[] = {-10, -1, -3, 9, 7};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret[3] = {-1};

    printf("Array: ");
    printArray(arr, sz);
    threeGreatestCandidates(arr, sz, ret);
    printf("The three greatest candidates are %d, %d and %d\n", ret[0], ret[1], ret[2]);

    return 0;
}