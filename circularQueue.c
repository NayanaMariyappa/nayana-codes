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
    int front;
    int rear;
    int qSize;
} queue_t;

queue_t q = {.front = 0, .rear = -1, .qSize = 0};

bool isEmpty(void)
{
    return q.qSize == 0 ? true : false;
}

bool isFull(void)
{
    return q.qSize == QUEUE_CAPACITY ? true : false;
}

void printQueue(void)
{
    if (isEmpty())
    {
        printf("The Queue is empty\n");
        return;
    }

    for(int i = 0; i < q.qSize; i++) printf("%d ", q.data[(q.front + i) % QUEUE_CAPACITY]);
    printf("\n");
}

int getFront(void)
{
    return isEmpty() ? -1 : q.data[q.front];
}

int getRear(void)
{
    return isEmpty() ? -1 : q.data[q.rear];
}

int queueSize(void)
{
    return q.qSize;
}

int dequeue(void)
{
    if(isEmpty())
    {
        printf("The Queue is empty, aborting the dequeue\n");
        return -1;
    }

    int data = q.data[q.front];
    q.front = (q.front + 1 ) % QUEUE_CAPACITY;
    q.qSize--;

    return data;
}

void enqueue(int data)
{
    if (isFull()) 
    {
        printf("The Queue is full, writing to the front.\n");
        q.front = (q.front + 1) % QUEUE_CAPACITY;
        q.qSize--;
    }

    q.rear = (q.rear + 1) % QUEUE_CAPACITY;
    q.data[q.rear] = data;
    q.qSize++;
}

void freeQueue(void)
{
    while(!isEmpty()) dequeue();
}

int main(void)
{
    int arr[] = {5, 89, 33, 29, 10};

    printf("The Queue before the enqueue: ");
    printQueue();

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) enqueue(arr[i]);
    
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

    return 0;
}