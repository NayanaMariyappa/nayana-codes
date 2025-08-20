#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

void printArray(int *arr, int sz)
{
    for (int i = 0; i < sz; i++) printf("%d ", arr[i]);
    printf("\n");
}

void inOrderPrintList(node_t *root)
{
    if(root)
    {
        inOrderPrintList(root->left);
        printf("%d ", root->data);
        inOrderPrintList(root->right);
    }
}

void preOrderPrintList(node_t *root)
{
    if(root)
    {
        printf("%d ", root->data);
        preOrderPrintList(root->left);
        preOrderPrintList(root->right);
    }
}

void postOrderPrintList(node_t *root)
{
    if(root)
    {
        postOrderPrintList(root->left);
        postOrderPrintList(root->right);
        printf("%d ", root->data);
    }
}

node_t *createNode(int data)
{
    node_t *node = malloc(sizeof(node_t));
    if (!node) return NULL;

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void addToBinaryTree(node_t **root, int data)
{
    node_t *ptr = *root;

    if (!(*root)) { *root = createNode(data); return;}
    
    if (data <= ptr->data) addToBinaryTree(&ptr->left, data);
    else addToBinaryTree(&ptr->right, data);
}

void swap(node_t **a, node_t **b)
{
    (*a)->data = (*a)->data ^ (*b)->data;
    (*b)->data = (*a)->data ^ (*b)->data;
    (*a)->data = (*a)->data ^ (*b)->data;
}

void deleteNodeFromBinaryTree(node_t **root, int data)
{
    node_t *ptr = *root;

    if (!ptr) return;

    if (data > ptr->data) deleteNodeFromBinaryTree(&ptr->right, data);
    else if (data < ptr->data) deleteNodeFromBinaryTree(&ptr->left, data);
    else
    {
        // Push the node to the leaf by swapping and then delete
        if (ptr->left) { swap (&ptr, &ptr->left); deleteNodeFromBinaryTree(&ptr->left, data); }
        else if (ptr->right) { swap (&ptr, &ptr->right); deleteNodeFromBinaryTree(&ptr->right, data); }
        else { free(ptr); *root = NULL; }
    }
}

int main(void)
{
    int arr[] = {5, 3, 0, 8, 1, 7, 9};
    int sz = sizeof(arr) / sizeof(arr[0]);
    node_t *root = NULL;

    printf("Array: \n");
    printArray(arr, sz);
    /*
             5
            / \
           3   8
          /   / \
         0   7   9
          \
           1

        Array: 5 3 0 8 1 7 9
        In-order: 0 1 3 5 7 8 9
        Pre-order: 5 3 0 1 8 7 9
        Post-order: 1 0 3 7 9 8 5

     */

    for (int i = 0; i < sz; i++) addToBinaryTree(&root, arr[i]);

    printf("In order: ");
    inOrderPrintList(root);
    printf("\n");

    printf("Pre order: ");
    preOrderPrintList(root);
    printf("\n");

    printf("Post order: ");
    postOrderPrintList(root);
    printf("\n");

    /* Delete arr[4] */
    printf("Deleting %d\n", arr[4]);
    deleteNodeFromBinaryTree(&root, arr[4]);

    printf("In order after the deletion: ");
    inOrderPrintList(root);
    printf("\n");

    printf("Pre order after the deletion: ");
    preOrderPrintList(root);
    printf("\n");

    printf("Post order after the deletion: ");
    postOrderPrintList(root);
    printf("\n");

    /* Delete arr[4] */
    printf("Deleting %d\n", arr[1]);
    deleteNodeFromBinaryTree(&root, arr[1]);

    printf("In order after the deletion: ");
    inOrderPrintList(root);
    printf("\n");

    printf("Pre order after the deletion: ");
    preOrderPrintList(root);
    printf("\n");

    printf("Post order after the deletion: ");
    postOrderPrintList(root);
    printf("\n");

    /* Delete arr[0] - root */
    printf("Deleting %d\n", arr[0]);
    deleteNodeFromBinaryTree(&root, arr[0]);

    printf("In order after the deletion: ");
    inOrderPrintList(root);
    printf("\n");

    printf("Pre order after the deletion: ");
    preOrderPrintList(root);
    printf("\n");

    printf("Post order after the deletion: ");
    postOrderPrintList(root);
    printf("\n");

    /* Try to delete the node that doesn't exist */
    printf("Deleting %d\n", 100);
    deleteNodeFromBinaryTree(&root, 100);

    printf("In order after the deletion: ");
    inOrderPrintList(root);
    printf("\n");

    printf("Pre order after the deletion: ");
    preOrderPrintList(root);
    printf("\n");

    printf("Post order after the deletion: ");
    postOrderPrintList(root);
    printf("\n");

    return 0;
}