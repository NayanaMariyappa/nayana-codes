#include <stdio.h>
#include <stdbool.h>

#ifdef NAY_DEBUG
int debug = true;
#else
int debug = false;
#endif

#define NAY_PRINT(...) \
        {if (debug) printf(__VA_ARGS__);}

int missingNumber(int *a, int sz)
{
    int expectedSum = 0;
    int actualSum = 0;
    int n = sz + 1;
    int i = 0;

    for (i = 0; i < sz; i++) actualSum += a[i];
    expectedSum = n * (n + 1) / 2;
    NAY_PRINT("Expectes sum: %d actual sum: %d\n", expectedSum, actualSum);

    return expectedSum - actualSum;
}

int main(void)
{
    int arr[] = {1, 2, 3, 5};
    int mNum = missingNumber(arr, sizeof(arr) / sizeof(arr[0]));

    if (!mNum) { printf("There are no missing numbers in the array\n"); return -1;}
    printf("The missing number is %d\n", mNum); return 0;
    return 0;
}