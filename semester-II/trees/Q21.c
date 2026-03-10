#include <stdio.h>
#include "tree.h"

void traverseRight(TreeNode *root); // forward declaration

void traverseLeft(TreeNode *root)
{
    if (!root)
        return;

    // do processing, whatever processing
    printf("%d ", root->data);
    traverseRight(root->left);
    traverseRight(root->right);
}

void indirectRecursion(TreeNode *root)
{
    traverseLeft(root);
}

void traverseRight(TreeNode *root)
{
    if (!root)
        return;

    // do processing, whatever processing
    printf("%d ", root->data);
    traverseLeft(root->left);
    traverseLeft(root->right);
}

int main()
{
    TreeNode *root = getTreeFromUserInput();
    indirectRecursion(root);
    return 0;
}