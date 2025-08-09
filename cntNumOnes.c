#include <stdio.h>

int countNumOnes(int n)
{
    int count = 0;

    while (n)
    {
        count++;
        n &= n - 1;
    }

    return count;
}

int main(void)
{
    int num = 13;

    printf("The number of ones in %d is %d\n", num, countNumOnes(num));
    return 0;
}