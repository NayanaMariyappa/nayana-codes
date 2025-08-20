#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isLittleEndian(void)
{
    int n = 5;
    char *ptr = (char *)&n;
    return (*ptr == 5);
}

int main(void)
{
    if(isLittleEndian()) printf("The system is little endian.\n");
    else printf("The system is big endian.\n");

    return 0;
}