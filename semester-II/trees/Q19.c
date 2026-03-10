#include <stdio.h>
#include "tree.h"

void doubleOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    printf("%d ", root->data);
    doubleOrderTraversal(root->left);
    printf("%d ", root->data);
    doubleOrderTraversal(root->right);
}

void tripleOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    printf("%d ", root->data);
    tripleOrderTraversal(root->left);
    printf("%d ", root->data);
    tripleOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    TreeNode *root = createTreeFromArray(arr, 5);
    printf("Double order traversal: ");
    doubleOrderTraversal(root);
    printf("\nTriple order traversal: ");
    tripleOrderTraversal(root);
}
