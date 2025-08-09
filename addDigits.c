#include <stdio.h>

int addDigits(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum > 9 ? addDigits(sum) : sum;
}

int main(void)
{
    int num = 5;
    
    printf("Addition of digits of %d is %d\n", num, addDigits(num));
    return 0;
}