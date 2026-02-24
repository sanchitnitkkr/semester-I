#ifndef TREE_H
#define TREE_H

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


TreeNode *createTreeFromArray(int *arr, int size);
TreeNode *getTreeFromUserInput();

#endif
