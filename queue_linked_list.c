#include <stdio.h>
#include <stdbool.h>

#define QUEUE_CAPACITY 100
typedef struct queue {
    int data;
    struct queue *next;
} queue_t;

queue_t *front = NULL;
queue_t *rear = NULL;

void printQueue(void)
{
    if (front == NULL || rear == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    queue_t *ptr = front;
    while(front)
    {
        
    }
}

int enqueue(int data)
{
    kljl
}

int dequeue(void)
{
    //
}

int peek(void)
{
    //
}

bool isEmpty(void)
{
    //
}

bool isFull(void)
{
    //
}

int queueSize(void)
{
    //
}

int main(void)
{
    int arr[] = {5, 89, 33, 29, 10};
    int ret;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (enqueue(arr[i]) == -1)
        {
            printf("Queue is full, cannot enqueue %d\n", arr[i]);
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
    return 0;

err:
    ret = queueSize();
    for (int i = 0; i < ret; i++)
    {
        dequeue();
    }
    return -1;
}