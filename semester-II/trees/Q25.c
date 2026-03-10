#include <stdio.h>
#include "tree.h"

int countLeafNodes(TreeNode *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
};

int countNonLeafNodes(TreeNode *root)
{
    if (!root)
        return 0;

    if (root->left || root->right)
        return 1 + countNonLeafNodes(root->left) +
               countNonLeafNodes(root->right);

    return 0;
}

int main()
{
    TreeNode *root = getTreeFromUserInput();
    printf("No of leaf nodes: %d", countLeafNodes(root));
    printf("\nNo of non leaf nodes: %d", countNonLeafNodes(root));
    return 0;
}