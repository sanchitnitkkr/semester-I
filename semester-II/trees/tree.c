#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

TreeNode *build(int *arr, int size, int i)
{
    if (i >= size || arr[i] == -1)
        return NULL;

    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = arr[i];
    node->left = build(arr, size, 2 * i + 1);
    node->right = build(arr, size, 2 * i + 2);

    return node;
}

TreeNode *createTreeFromArray(int *arr, int size)
{
    return build(arr, size, 0);
}

TreeNode *getTreeFromUserInput()
{
    printf("Enter no of elements in the tree: ");

    int noOfElements;
    scanf("%d", &noOfElements);
    int treeArr[noOfElements];

    for (int i = 0; i < noOfElements; i++)
    {
        printf("Enter element %d: ", i);
        int ele;
        scanf("%d", &ele);
        treeArr[i] = ele;
    };

    TreeNode *root = createTreeFromArray(treeArr, noOfElements);
    return root;
}