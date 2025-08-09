#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t, *pNode;

node_t* createNode(int d)
{
    pNode node = malloc(sizeof(node_t));
    if (!node) return NULL;

    node->data = d;
    node->next = NULL;

    return node;
}

void delete(int n, pNode *head)
{
    pNode deleteNode = NULL;
    if (!(*head)) {printf("The list is empty cannot delete the node\n"); return;}

    pNode ptr = *head;
    pNode prev = ptr;
    while (ptr)
    {
        if (ptr->data == n)
        {
            deleteNode = ptr;
            if (deleteNode == *head)
                *head = (*head)->next;
            prev->next = deleteNode->next;
            free(deleteNode);
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if (!deleteNode)
        printf("The node corresponding to the data %d is not found in the list\n", n);
}

void insert(int val, pNode *head, bool front)
{
    pNode node = createNode(val);
    if (!node) { printf("Failed to create the new node\n"); return; }

    if (front)
    {
        node->next = *head;
        *head = node;
    }
    else
    {
        if (!(*head)) *head = node;
        else
        {
            pNode ptr = *head;
            while (ptr->next)
                ptr = ptr->next;
            ptr->next = node;
        }
    }
}

void printList(pNode head)
{
    if (!head) { printf("The list is empty\n"); return;}

    printf("The list: ");
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteMiddleNode(pNode *head)
{
    if (!(*head)) {printf("The list is empty, aborting the middle node deletion\n"); return;}
    
    pNode fastPtr = *head;
    pNode slowPtr = *head;
    pNode prev = NULL;

    while(fastPtr->next)
    {
        fastPtr = fastPtr->next;
        fastPtr = fastPtr->next;
        prev = slowPtr;       
        slowPtr = slowPtr->next;        
    }

    if (prev)
    {
        prev->next = slowPtr->next;
        free(slowPtr);
    }
}

void reverseList(pNode *head)
{
    if (!(*head)) {printf("The list is empty, aboring\n"); return;}

    pNode prev = *head;
    pNode ptr = *head;
    pNode save = ptr->next;
    prev->next = NULL;

    while(save)
    {
        ptr = save;
        save = ptr->next;
        ptr->next = prev;
        prev = ptr;
    }
    (*head) = ptr;
}

void printReverseWithoutReversingList(pNode head)
{
    if (head == NULL) return;
    printReverseWithoutReversingList(head->next);
    printf("%d ", head->data);
}

int main(void)
{
    pNode head = NULL;

    printList(head);
    insert(5, &head, false);
    insert(10, &head, true);
    insert(20, &head, true);
    insert(25, &head, false);
    printList(head);
    reverseList(&head);
    printList(head);
    printf("Print reverse without reversing the list: ");
    printReverseWithoutReversingList(head);
    printf("\n");
    delete(10, &head);
    printList(head);
    deleteMiddleNode(&head);
    printList(head);

    return 0;
}