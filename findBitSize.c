#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is64Bit(void)
{
    printf("sizeof unsigned long: %d sizeof int: %d\n", sizeof(unsigned long), sizeof(int));
    return !(sizeof(unsigned long) == sizeof(int));
}

int main(void)
{
    if (is64Bit()) printf("The system is 64 bits.\n");
    else printf("The system is 32 bits.\n");

    return 0;
}