#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkIthBit(int n, int i)
{
    return (n & 0x1 << i);
}

bool isOdd(int n)
{
    return (n & 0x1);
}

bool isPowerOfTwo(int n)
{
    return (n & n-1) == 0;
}

int numSetBits(int n)
{
    int cnt = 0;
    while(n) { cnt++; n &= n - 1; }
    return cnt;
}

int setRightMostUnsetBit(int n)
{
    return n | (n + 1);
}

int resetRightMostSetBit(int n)
{
    return n & (n - 1);
}

void swapTwoNumbers(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main(void)
{
    int n = 5;
    int i = 2;

    if (checkIthBit(n, i)) printf("%dth bit of %d is set\n", n, i);
    else printf("%dth bit of %d is not set\n", n, i);

    if (isOdd(n)) printf("%d is the odd number.\n", n);
    else printf("%d is the even number.\n", n);

    if (isOdd(2)) printf("2 is the odd number.\n");
    else printf("2 is the even number.\n");
 
    if (isPowerOfTwo(n)) printf("%d is the power of 2.\n", n);
    else printf("%d is not the power of 2.\n");

    if (isPowerOfTwo(16)) printf("%d is the power of 2.\n", 16);
    else printf("16 is not the power of 2.\n");
 
    printf("The number of set bits in %d are: %d\n", n, numSetBits(n));

    printf("%d after setRightMostUnsetBit: %d\n", n, setRightMostUnsetBit(n));
    printf("%d after resetRightMostSetBit: %d\n", n, resetRightMostSetBit(n));

    int num1 = 5;
    int num2 = 4;
    printf("Before swapping: num1: %d, num2: %d\n", num1, num2);
    swapTwoNumbers(&num1, &num2);
    printf("Before swapping: num1: %d, num2: %d\n", num1, num2);
    return 0;
}