
#include <stdio.h>
#include <stdlib.h>

void mySort(int *n, int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s - 1; j++)
        {
            if (*(n + j) > *(n + j + 1))
            {
                int temp = *(n + j);
                *(n + j) = *(n + j + 1);
                *(n + j + 1) = temp;
            }
        }
    }

}

int* numberGame(int *nums, int numSize, int *returnSize)
{
    int *arr = malloc(numSize * sizeof(int));
    if (arr == NULL)
        return NULL;

    *returnSize = numSize;
    mySort(nums, numSize);

    for (int i = 0; i < numSize; i += 2)
    {
        arr[i] = nums[i + 1];
        arr[i + 1] = nums[i];
    }

    return arr;
}

int main(void)
{
    int nums[4] = {5, 4, 2, 3};
    int *arr;
    int sz = sizeof(nums) / sizeof(nums[0]);
    int retSz;

    if (sz%2 !=0 )
    {
        printf("Array must have event set of elements for this game.\n");
        return -1;
    }
    arr = numberGame(nums, sz, &retSz);

    if (!arr)
    {
        printf("Ran out of memory, aborting!");
        return -1;
    }

    printf("Minimum number game output:\n");
    for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}