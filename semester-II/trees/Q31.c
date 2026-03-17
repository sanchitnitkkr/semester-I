#include <stdio.h>
#include "tree.h"

int findMin(TreeNode *root)
{
    if (!root)
        return 0;

    if (root->left)
    {
        return findMax(root->left);
    }

    return root->data;
};

int findMax(TreeNode *root)
{
    if (!root)
        return 0;

    if (root->right)
    {
        return findMax(root->right);
    }

    return root->data;
}

int main()
{
    int arr[] = {10, 5, 20, 2, 7, 15, 30};
    int size = sizeof(arr) / sizeof(int);
    TreeNode *root = createTreeFromArray(arr, size);
    printf("Min: %d\n", findMin(root));
    printf("Max: %d\n", findMax(root));

    return 0;
}