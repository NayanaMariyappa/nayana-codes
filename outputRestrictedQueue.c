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
    queue_t *qPtr = front;

    if (isEmpty())
    {
        printf("The Queue is Empty\n");
        return;
    }

    while(qPtr)
    {
        printf("%d ", qPtr->data);
        qPtr = qPtr->next;
    }
    printf("\n");
}

int queueSize(void)
{
    return qSize;
}

int getFront(void)
{
    if (isEmpty())
    {
        printf("The Queue is Empty\n");
        return -1;
    }

    return front->data;
}

int getRear(void)
{
    if (isEmpty())
    {
        printf("The Queue is Empty\n");
        return -1;
    }

    return rear->data;
}

int peek(void)
{
    return getFront();
}

int dequeueFront(void)
{
    if (isEmpty())
    {
        printf("The Queue is empty, cannot dequeue front\n");
        return -1;
    }

    queue_t *ptr = front;
    int data = front->data;

    front = front->next;
    if (!front) rear = NULL;
    free(ptr);
    qSize--;
    return data;
}

int enqueueFront(int data)
{    
    if (isFull())
    {
        printf("The Queue is full, cannot enqueue front\n");
        return -1;
    }

    queue_t *newNode = malloc(sizeof(queue_t));
    if (!newNode)
    {
        printf("Not enough memory, cannot enqueue front\n");
        return -1;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (!rear)
    {
        front = rear = newNode;
    }
    else
    {
        newNode->next = front;
        front = newNode;
    }
    qSize++;

    return 0;
}

int enqueueRear(int data)
{
    if (isFull())
    {
        printf("The Queue is full, cannot enqueue rear\n");
        return -1;
    }

    queue_t *newNode = malloc(sizeof(queue_t));
    if (!newNode)
    {
        printf("Not enough memory, cannot enqueue rear\n");
        return -1;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (!rear)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    qSize++;

    return 0;
}

void freeQueue(void)
{
    while (!isEmpty()) dequeueFront();
}

int main(void)
{
    int arr[] = {5, 89, 33, 29, 10};
    int ret = 0;

    printf("The Queue before the enqueue: ");
    printQueue();

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (enqueueRear(arr[i]) == -1)
        {
            printf("Queue is full, cannot enqueue %d\n", arr[i]);
            ret = -1;
            goto err;
        } 
    }
    
    printf("Queue after enqueue: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());

    dequeueFront();
    printf("Queue after dequeuefront: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());
    printf("Rear: %d\n", getRear());
    printf("Front: %d\n", getFront());

    enqueueFront(50);
    printf("Queue after enqueueFront: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());
    printf("Rear: %d\n", getRear());
    printf("Front: %d\n", getFront());

    enqueueRear(100);
    printf("Queue after enqueueFront: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());
    printf("Rear: %d\n", getRear());
    printf("Front: %d\n", getFront());

err:
    freeQueue();
    return ret;
}