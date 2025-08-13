#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef debug
#define QUEUE_CAPACITY  4
#else
#define QUEUE_CAPACITY 100
#endif

typedef struct queue {
    int data;
    struct queue *next;
} queue_t;

queue_t *front = NULL;
queue_t *rear = NULL;
int qSz = 0;

void printQueue(void)
{
    if (front == NULL || rear == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    queue_t *ptr = front;
    while(ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int queueSize()
{
    return qSz;
}

bool isEmpty(void)
{
    return qSz == 0 ? true : false;
}

bool isFull(void)
{    
    return qSz == QUEUE_CAPACITY;
}

queue_t *createNode(int data)
{
    queue_t *node = malloc(sizeof(queue_t));
    if (!node)
    {
        printf("Memory allocation failed in %s\n", __func__);
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

int enqueue(int data)
{
    if (isFull())
    {
        printf("The Queue is full. Aborting the enqueue\n");
        return -1;
    }

    queue_t *newNode = createNode(data);
    if (!newNode)
        return -1;

    if (isEmpty()) 
    {
        front = rear = newNode;
    }
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
    qSz++;

    return 0;
}

int dequeue(void)
{
    queue_t *ptrNode = front;
    int data = -1;

    if (isEmpty())
    {
        printf("The Queue is Empty. Aborting the dequeue\n");
        return -1;
    }

    data = front->data;
    front = front->next;
    free(ptrNode);
    qSz--;

    if (!qSz) rear = NULL;

    return data;
}

int peek(void)
{
    return front ? front->data : -1;
}

int getFront(void)
{
    return peek();
}

int getRear(void)
{
    return rear ? rear->data : -1;
}

void freeQueue(void)
{
    while(!isEmpty())
    {
        dequeue();
    }
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

    for (int i = 0; i < 3; i++) dequeue();

    printf("Queue after dequeue: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());
    printf("Rear: %d\n", getRear());
    printf("Front: %d\n", getFront());

err:
    freeQueue();
    return ret;
}