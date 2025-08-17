#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *random;
} node_t;

void printList(node_t *head)
{
    node_t *ptr = head;
    while(ptr)
    {
        printf("data: %d next: %p random: %p\n", ptr->data, ptr->next, ptr->random);
        ptr = ptr->next;
    }
}

node_t *createNode(int a)
{
    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        printf("No sufficient memory. Aborting the insert\n");
        return NULL;
    }

    newNode->data = a;
    newNode->next = NULL;
    newNode->random = NULL;

    return newNode;
}

void deleteList(node_t **head)
{
    node_t *ptr = *head;
    while(ptr)
    {
        node_t *save = ptr;
        ptr = ptr->next;
        free(save);
    }
}

int insertNodeAtListEnd(node_t **head, int d)
{
    node_t *newNode = createNode(d);
    if (!newNode) return -1;
    node_t *ptr = *head;

    if (*head == NULL) *head = newNode;
    else 
    {
        while((ptr)->next) ptr = ptr->next;
        ptr->next = newNode;
    }

    return 0;
}

void copyListRandomPointer(node_t **head, node_t **copyHead)
{
    node_t *ptrList = *head;
    node_t *copyList;

    /* Insert the new nodes in between the old nodes and create a single new list */
    while(ptrList)
    {
        node_t *tmpPtr = ptrList->next; // Save the next node.
        ptrList->next = createNode(ptrList->data); // insert the new node whose data is same as the previous.
        if (!ptrList->next) return;
        ptrList->next->next = tmpPtr; // the newly inserted node will point to the next node of the old list.
        ptrList = ptrList->next->next;
    }

    // Update the random pointer in the new list
    ptrList = *head;
    while(ptrList)
    {
        ptrList->next->random = ptrList->random->next;
        ptrList = ptrList->next->next;
    }

    // Separate the original and copied lists into two separate lists
    ptrList = *head;
    *copyHead = ptrList->next;
    while(ptrList)
    {
        copyList = ptrList->next;
        ptrList->next = ptrList->next ? ptrList->next->next : NULL;
        copyList->next = copyList->next ? copyList->next->next : NULL;
        ptrList = ptrList->next;
    }
}

int main(void)
{
    int arr[] = {7, 8, 3, 56, 78};
    unsigned long random[100] = {0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    node_t *head = NULL;
    node_t *copyHead = NULL;

    for (int i = 0; i < sz; i++)
    {
        if (insertNodeAtListEnd(&head, arr[i]) == -1) 
        {
            printf("Insert failed, deleting the list\n");
            deleteList(&head);
            return -1;
        }
    }
    printf("Insertion is completed\n");
    /* Set random pointers */    
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    printf("List:\n");
    printList(head);    
    copyListRandomPointer(&head, &copyHead);

    printf("List after the copy:\n");
    printList(head);

    printf("Copied list after the copy:\n");
    printList(copyHead);

    deleteList(&head);
    deleteList(&copyHead);

    return 0;
}