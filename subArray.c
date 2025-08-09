#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* subArraySum(int *array, int arraySize, int target)
{
    int sum = 0;
    bool found = false;
    int *result = malloc(2 * sizeof(int));
    if (result == NULL) return NULL;
    int i;
    int j;

    for (j = 0; j < arraySize; j++)
    {
        for (i = j; i < arraySize; i++)
        {
            sum += array[i];
            if (sum > target) break;
            if (sum == target) { found = true; break; }
        }
        if (found) break;
        sum = 0;
    }

    if (found)
    {
        *result = j;
        *(result + 1) = i;
        return result;
    }
    else return NULL;
}

int main(void)
{
    int arr[] = {1, 2, 3, 7, 5};
    int target = 12;
    int *result = subArraySum(arr, sizeof(arr) / sizeof(arr[0]), target);

    if (!result) { printf("Could not find the sub array.\n"); return -1;}

    printf("The subarray is by summing the elements from %d to %d indeces of the array.\n", *result, *(result + 1));
    free(result);
    return 0;
}