#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
        printf("The Queue is Empty\n");
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

int getFront(void)
{
    if (isEmpty())
    {
        printf("The Queue is empty\n");
        return -1;
    }
    return front->data;
}

int getRear(void)
{
    if (isEmpty())
    {
        printf("The Queue is empty\n");
        return -1;
    }
    return rear->data;
}

int peek(void)
{
    return getFront();
}

int queueSize(void)
{
    return qSize;
}

int enqueueRear(int data)
{
    if (isFull())
    {
        printf("The Queue is full, aborting enqueue at the rear end\n");
        return -1;
    }

    queue_t *newNode = malloc(sizeof(queue_t));
    if (!newNode)
    {
        printf("Not enough memory, aboting the enqueueRear\n");
        return -1;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    qSize++;
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
    free(ptr);
    qSize--;

    return data;
}

int dequeueRear(void)
{
    if (isEmpty())
    {
        printf("The Queue is empty, cannot dequeue rear\n");
        return -1;
    }

    queue_t *ptr = rear;
    int data = rear->data;
    queue_t *fPtr = front;

    while(fPtr)
    {
        if (fPtr->next == rear) break;
        fPtr = fPtr->next;
    }
    rear = fPtr;
    rear->next = NULL;
    free(ptr);
    qSize--;

    return data;
}

void freeQueue()
{
    while(!isEmpty())
    {
        dequeueFront(); // or dequeueRear()
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

    dequeueRear();
    printf("Queue after dequeueRear: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());
    printf("Rear: %d\n", getRear());
    printf("Front: %d\n", getFront());

    dequeueFront();
    printf("Queue after dequeueFront: ");
    printQueue();
    printf("The size of queue: %d\n", queueSize());
    printf("Rear: %d\n", getRear());
    printf("Front: %d\n", getFront());

err:
    freeQueue();
    return ret;

}