#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE_MAX 3

typedef struct stackElement {
    char *data[STACK_SIZE_MAX];
    unsigned int sz;
} stackElem, *pStack;

bool isStackEmpty(stackElem tos)
{
    return !tos.sz ? true : false;
}

bool isStackFull(stackElem tos)
{
    return tos.sz == STACK_SIZE_MAX ? true : false;
}

void printStack(stackElem tos)
{
    if (isStackEmpty(tos))
    {
        printf("Stack is empty\n");
        return ;
    }

    while (tos.sz)
    {
        printf("data:%s\n", tos.data[tos.sz - 1]);
        tos.sz--;
    }
}

void push(pStack tos, char *s)
{
    if (isStackFull(*tos))
    {
        printf("The stack is full, aborting the push of %s\n", s);
        return;
    }
    ++tos->sz;
    tos->data[tos->sz - 1] = malloc(strlen(s) + 1);
    strncpy(tos->data[tos->sz - 1], s, strlen(s) + 1);
}

void pop(pStack tos, char *s)
{
    if (isStackEmpty(*tos))
    {
        printf("The stack is empty, cannot pop\n");
        return;
    }

    if (strcmp(tos->data[tos->sz - 1], s) != 0)
    {
        printf("%s is either not at the top of the stack or not present in the stack\n", s);
        return;
    }

    free(tos->data[tos->sz - 1]);
    tos->sz--;
}

char* peek(stackElem tos)
{
    if (isStackEmpty(tos))
    {
        printf("The stack is empty; cannot peek into the top of the stack\n");
        return NULL;
    }

    return tos.data[tos.sz - 1];
}

int main(void)
{
    stackElem stack;
    stack.sz = 0;

    printStack(stack);
    push(&stack, "nayana");
    push(&stack, "mariyappa");
    push(&stack, "Greenage");
    printStack(stack);
    pop(&stack, "Greenage");
    printStack(stack);
    printf("The peek of the stack: %s\n", peek(stack));

    return 0;
}