#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef debug
#define QUEUE_CAPACITY  5
#else
#define QUEUE_CAPACITY  100
#endif

typedef struct queue {
    int data;
    struct queue *next;
} queue_t;

queue_t *front = NULL;
queue_t *rear = NULL;
int qSize = 0;

bool isEmpty(void)
{
    return qSize == 0 ? true : false;
}

bool isFull(void)
{
    return qSize == QUEUE_CAPACITY ? true : false;
}

void printQueue(void)
{
    if (isEmpty())
    {
        printf("The Queue is empty");
        return;
    }

    queue_t *ptr = front;
    while(ptr)
    {
        printf("%d ");
        ptr = ptr->next;
    }
}

int getFront(void)
{
    if (isEmpty())
    {
        printf("The list is empty, cannot get front\n");
        return -1;
    }

    return front->data;
}

int getRear(void)
{
    if (isEmpty())
    {
        printf("The list is empty, cannot get rear\n");
        return -1;
    }

    return rear->data;
}

int queueSize(void)
{
    return qSize;
}

int dequeue(void)
{
    
}

void freeQeueue(void)
{
    while(!isEmpty()) dequeue();
}