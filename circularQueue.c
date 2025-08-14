#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef debug
#define QUEUE_CAPACITY  5
#else
#define QUEUE_CAPACITY  100
#endif

typedef struct queue {
    int data[QUEUE_CAPACITY];
    int *front;
    int *rear;
} queue_t;

queue_t q = {-1};
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
        printf("The Queue is empty\n");
        return;
    }

    for(int i = 0; i < QUEUE_CAPACITY; i++) printf("%d ", q.data[i]);
    printf("\n");
}

int getFront(void)
{
    if (isEmpty())
    {
        printf("The list is empty, cannot get front\n");
        return -1;
    }

    return *q.front;
}

int getRear(void)
{
    if (isEmpty())
    {
        printf("The list is empty, cannot get rear\n");
        return -1;
    }

    return *q.rear;
}

int queueSize(void)
{
    return qSize;
}

int dequeue(void)
{
    if(isEmpty())
    {
        printf("The Queue is empty, aborting the dequeue\n");
        return -1;
    }

    int data = *q.front;
    *q.front = -1; q.front++; qSize--;
    if (qSize == 0) q.rear = q.front = NULL;

    return data;
}

int enqueue(int data)
{
    if (isFull()) printf("The Queue is full, writing to the front.\n");

    if (qSize == 0) q.front = q.rear = q.data;
    else if (q.rear == q.data + QUEUE_CAPACITY) q.rear = q.data;
    *q.rear = data;
    q.rear++;
    if (qSize != QUEUE_CAPACITY) qSize++;
}

void freeQueue(void)
{
    while(!isEmpty()) dequeue();
}

int main(void)
{
    int arr[] = {5, 89, 33, 29, 10};
    int ret = 0;

    printf("The Queue before the enqueue: ");
    printQueue();

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (enqueue(arr[i]) == -1)
        {
            printf("Queue is full, cannot enqueue %d\n", arr[i]);
            ret = -1;
            goto err;
        } 
    }
    
    printf("Queue after enqueue: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());

    dequeue();
    printf("Queue after dequeue: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());
    printf("Rear: %d\n", getRear());
    printf("Front: %d\n", getFront());

    enqueue(50);
    printf("Queue after enqueue: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());
    printf("Rear: %d\n", getRear());
    printf("Front: %d\n", getFront());

    enqueue(100);
    printf("Queue after enqueue: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());
    printf("Rear: %d\n", getRear());
    printf("Front: %d\n", getFront());

err:
    freeQueue();
    return ret;
}