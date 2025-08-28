#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

void sort012(int *arr, int sz)
{
    int cnt[3] = {0};

    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == 0) cnt[0]++;
        else if (arr[i] == 1) cnt[1]++;
        else if (arr[i] == 2) cnt[2]++;
    }
    while(cnt[0]) { *arr = 0; arr++; cnt[0]--; }
    while(cnt[1]) { *arr = 1; arr++; cnt[1]--; }
    while(cnt[2]) { *arr = 2; arr++; cnt[2]--; }
}

void sortSinglePass012(int *arr, int sz)
{
    int low = 0;
    int mid = 0;
    int high = sz - 1;

    while(mid <= high)
    {
        if (arr[mid] == 0)
        {
            // Swap low and mid
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;

            low++; mid++;
        }
        else if (arr[mid] == 1) mid++;
        else
        {
            // Swap high and mid
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = arr[mid];

            high--;
        }
    }
}

int main(void)
{
    int arr[] = {1, 2, 0, 2, 2, 1, 0, 1, 1, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArray(arr, sz);
    sort012(arr, sz);
    printf("Array after sorting: ");
    printArray(arr, sz);
    sortSinglePass012(arr, sz);
    printf("Array after sorting single pass: ");
    printArray(arr, sz);

    return 0;
}