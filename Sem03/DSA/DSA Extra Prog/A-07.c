/*Write a program to check that the left sub-tree of an binary tree is a mirror image of its right sub-tree.*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    printf("Enter left child of %d:\n", x);
    p->left = create();

    printf("Enter right child of %d:\n", x);
    p->right = create();
    return p;
}

bool isMirror(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    return false;
}

bool isSymmetric(node *root)
{
    return isMirror(root, root);
}

int main()
{
    node *root;
    root = create();
    if (isSymmetric(root))
        printf("\nTree is Symmetric");
    else
        printf("\nTree is Not Symmetric");
    return 0;
}
