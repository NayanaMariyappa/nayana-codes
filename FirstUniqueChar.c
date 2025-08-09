/******************************************************************************

C program to find the first unique character in a string.
    * 
    * This program defines a function `firstUniqChar` that takes a string as input
    * and returns the index of the first unique character in that string. If no
    * unique character exists, it returns -1.
    *
    * The program uses a hash table to count occurrences of each character and
    * then checks for the first character with a count of 1.
    *
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_ALPHABETS_NUM 26

int get_hash(char s)
{
    int c = s - 'A';
    if (s >= 'a') c -= 32;
    return c;
}

void update_has_table(int *p, const char *s)
{
    int c = get_hash(*s);
    p[c]++;
}

bool find_has_table(int *p, const char *s)
{
    int c = get_hash(*s);
        
    return p[c] == 1 ? true : false; 
}

int firstUniqChar(char *s)
{
    bool found = false;
    int len = strlen(s);
    int c[MAX_ALPHABETS_NUM] = {0};
    int i;
    
    for (i = 0; i < len; i++) update_has_table(c, s + i);
    
    for (i = 0; i < len; i++)
    {
        found = find_has_table(c, s + i);
        if (found) break;
    }
    
    return found ? i : -1;
}

int main()
{
    char *str = "lletcod";
    printf("The first unique char of %s is in the index %d\n", str, firstUniqChar(str));

    return 0;
}