// Find the preorder, inorder and postorder traversal of the tree
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void preorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
};

void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
};

void postOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
};

int main()
{
    TreeNode *root = getTreeFromUserInput();

    printf("Preorder Traversal -> ");
    preorderTraversal(root);
    printf("\nInorder Traversal -> ");
    inorderTraversal(root);
    printf("\nPostorder Traversal -> ");
    postOrderTraversal(root);
    return 0;
}