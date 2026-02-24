/* Write a recursive program to count the total number of nodes in the tree*/
#include <stdio.h>
#include "tree.h"

void countNodes(TreeNode *root, int *count)
{
    if (!root)
        return;

    (*count)++;
    countNodes(root->left, count);
    countNodes(root->right, count);
}

int main()
{
    int nodeCount = 0;
    TreeNode *root = getTreeFromUserInput();
    countNodes(root, &nodeCount);
    printf("Total no of nodes in the tree: %d", nodeCount);
    return 0;
}