#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int search(int *arr, int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

TreeNode *buildBinaryFromInAndPreOrder(
    int *inorder,
    int *preorder,
    int startIdx,
    int endIdx,
    int *index)
{
    if (startIdx > endIdx)
        return NULL;

    TreeNode *root = malloc(sizeof(TreeNode));
    root->data = preorder[*index];
    (*index)++; // move forward now
    root->left = NULL;
    root->right = NULL;

    if (startIdx == endIdx)
        return root;

    int iIndex = search(inorder, startIdx, endIdx, root->data);

    // IMPORTANT: build LEFT first for preorder
    root->left = buildBinaryFromInAndPreOrder(
        inorder, preorder,
        startIdx, iIndex - 1,
        index);

    root->right = buildBinaryFromInAndPreOrder(
        inorder, preorder,
        iIndex + 1, endIdx,
        index);

    return root;
}

void printPostorder(TreeNode *curr)
{
    if (!curr)
        return;

    printPostorder(curr->left);
    printPostorder(curr->right);
    printf("%d ", curr->data);
}

int main()
{
    int inorder[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 8, 5, 3, 6, 7};

    int n = sizeof(inorder) / sizeof(inorder[0]);

    int preIndex = 0;

    TreeNode *root =
        buildBinaryFromInAndPreOrder(
            inorder, preorder,
            0, n - 1,
            &preIndex);

    printPostorder(root);

    return 0;
}