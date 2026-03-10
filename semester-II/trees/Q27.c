#include <stdio.h>
#include "tree.h"

int max(int val1, int val2)
{
    if (val1 > val2)
        return val1;
    return val2;
}

int findHeight(TreeNode *root)
{
    if (!root)
        return 0;

    if (root->left || root->right)
    {
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }

    return 1;
};

int main()
{
    TreeNode *root = getTreeFromUserInput();
    printf("Height of the tree: %d", findHeight(root));
    return 0;
}