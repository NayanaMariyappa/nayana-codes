#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int twosCompliment(int n)
{
    return ~n + 1;
}

int main(void)
{
    int n = 96;

    printf("The 2's complement of %d is %d\n", n, twosCompliment(n));
    return 0;
}