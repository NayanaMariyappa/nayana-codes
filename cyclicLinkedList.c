#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void printList(node_t *head)
{
    while(head) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int createList(node_t **head, int *arr, int sz)
{
    node_t *ptr;
    node_t *newNode;
    
    for (int i = 0; i < sz; i++)
    {
        newNode = malloc(sizeof(node_t));
        newNode->data = arr[i];
        newNode->next = NULL;
        
        if (!(*head)) { *head = newNode; ptr = *head; }
        else { ptr->next = newNode; ptr = ptr->next; }
    } 
}

bool isCyclicList(node_t *head)
{
    node_t *slow = head;
    node_t *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) return true;
    }

    return false;
}

void createLoop(node_t **head)
{
    node_t *ptr = *head;

    while(ptr && ptr->next) ptr = ptr->next;
    ptr->next = *head;
}

int main(void)
{
    int arr[] = {2, 3, 5, 7, 9};
    int sz = sizeof(arr) / sizeof(arr[0]);
    node_t *head = NULL;

    createList(&head, arr, sz);
    printf("List: ");
    printList(head);
    if (isCyclicList(head)) printf("The list is the cyclic list (has a loop)\n");
    else printf("The list is not a cyclic list (does not have a loop)\n");

    createLoop(&head);
    if (isCyclicList(head)) printf("The list is the cyclic list after createLoop (has a loop)\n");
    else printf("The list is not a cyclic list (does not have a loop)\n");

    return 0;
}