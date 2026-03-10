#include <stdio.h>
#include "tree.h"

// Construct a bst using inorder and postorder and hence find preorder

TreeNode *buildBSTFromInorderAndPostOrder(int inorder[], int postorder[], int noOfNodes, int rangeStart, int rangeEnd, int *postOrderRootIndex)
{
    if (rangeStart > rangeEnd)
    {
        return NULL;
    }

    int postOrderElement = postorder[*postOrderRootIndex];
    TreeNode *root = createNode(postOrderElement);

    int indexOfPostOrderEleInInorder;
    for (int i = rangeStart; i <= rangeEnd; i++)
    {
        if (inorder[i] == postOrderElement)
        {
            indexOfPostOrderEleInInorder = i;
            break;
        }
    };

    (*postOrderRootIndex)--;
    root->right = buildBSTFromInorderAndPostOrder(inorder, postorder, noOfNodes, indexOfPostOrderEleInInorder + 1, rangeEnd, postOrderRootIndex); // right subtree must be made first, why?
    root->left = buildBSTFromInorderAndPostOrder(inorder, postorder, noOfNodes, rangeStart, indexOfPostOrderEleInInorder - 1, postOrderRootIndex);

    return root;
}

void preorderTraversal(TreeNode *root)
{
    if (!root)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
};

int main()
{
    int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    int postorder[] = {10, 30, 20, 50, 70, 60, 40};

    int size = sizeof(inorder) / sizeof(int);
    int postOrderRootIndex = size - 1;

    TreeNode *root = buildBSTFromInorderAndPostOrder(inorder, postorder, size, 0, size - 1, &postOrderRootIndex);

    preorderTraversal(root);
    return 0;
}