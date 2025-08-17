#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

typedef struct ret {
    int firstIndex;
    int secondIndex;
} ret_t;

void twoPointerSum(int *arr, int sz, int sum, ret_t *ret)
{
    int left = 0;
    int right = sz - 1;
    ret->firstIndex = -1;
    ret->secondIndex = -1;

    while (left < right)
    {
        int s = arr[left] + arr[right];
        if (s == sum)
        {
            ret->firstIndex = left;
            ret->secondIndex = right;
            break;
        }

        if (s > sum) right --;
        else left++;
    }

}

int main(void)
{
    int arr[] = {-8, 1, 4, 6,10,45};
    int sz = sizeof(arr) / sizeof(arr[0]);
    ret_t twoSumInd;
    int twoSum = arr[2] + arr[5];
    int ret = 0;

    printf("Array: ");
    printArray(arr, sz);
    twoPointerSum(arr, sz, twoSum, &twoSumInd);
    if (twoSumInd.firstIndex == -1 || twoSumInd.secondIndex == -1)
    {
        printf("The indices for twoSum of %d is not found\n", twoSum);
        ret = -1;
    }
    else printf("The two indices to get %d is %d & %d\n", twoSum, twoSumInd.firstIndex, twoSumInd.secondIndex);

    return ret;
}