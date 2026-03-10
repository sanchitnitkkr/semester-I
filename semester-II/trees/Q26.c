#include <stdio.h>
#include "tree.h"

int countFullNodes(TreeNode *root)
{
    if (!root)
        return 0;

    if (root->left && root->right)
    {
        return 1 + countFullNodes(root->left) + countFullNodes(root->right);
    }

    return countFullNodes(root->left) + countFullNodes(root->right);
};

int main()
{
    TreeNode *root = getTreeFromUserInput();
    printf("No of full nodes: %d", countFullNodes(root));
    return 0;
}