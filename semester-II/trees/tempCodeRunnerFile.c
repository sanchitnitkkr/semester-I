// Find the preorder, inorder and postorder traversal of the tree
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

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

TreeNode *build(int *arr, int size, int i)
{
    if (i >= size || arr[i] == -1)
        return NULL;

    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = arr[i];
    node->left = build(arr, size, 2 * i + 1);
    node->right = build(arr, size, 2 * i + 2);

    return node;
}

TreeNode *createTreeFromArray(int *arr, int size)
{
    return build(arr, size, 0);
}

int main()
{
    printf("Enter no of elements in the tree: ");

    int noOfElements;
    scanf("%d", &noOfElements);
    int treeArr[noOfElements];

    for (int i = 0; i < noOfElements; i++)
    {
        printf("Enter element %d: ", i);
        int ele;
        scanf("%d", &ele);
        treeArr[i] = ele;
    };

    TreeNode *root = createTreeFromArray(treeArr, noOfElements);
    printf("Preorder Traversal -> ");
    preorderTraversal(root);
    printf("\nInorder Traversal -> ");
    inorderTraversal(root);
    printf("\nPostorder Traversal -> ");
    postOrderTraversal(root);
    return 0;
}