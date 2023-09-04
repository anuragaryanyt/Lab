#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *node(int value)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
}


void InOrder(struct node *node)
{
    if (node == NULL)
        return;
    InOrder(node->left); // displaying in preorder
    printf("%d", node->data);
    InOrder(node->right);
}
void preorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%d", node->data);

    preorder(node->left);
    preorder(node->right);
}
void postorder(struct node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d", node->data);
}
int main()
{
    struct node *root = node(1);
    root->left = node(2);
    root->right = node(3);
    root->left->left = node(4);
    root->left->right = node(6);
    root->right->left = node(5);
    root->right->right = node(7);
    printf("Data entered successfully!!\n");
    printf("Data transvered successfully!!\n");
    InOrder(root);
    printf("\n\n");

    printf("\nDisplaying in InOrder--\n");
    InOrder(root);
    printf("\nDisplaying in PreOrder--\n");
    preorder(root);
    printf("\nDisplaying in PostOrder--\n");
    postorder(root);

    getchar();
    return 0;
}


/*
struct node *insert(struct node *root, int val)
{
    printf("Enter the value: ");
    scanf("%d", &val);
    if (root == NULL)
        return node(val);
    if (root->data < val)
        root->right = insert(root->right, val);
    else if (root->data > val)
        root->left = insert(root->left, val);
    return root;
}
    root = insert(root, 20);
    root = insert(root, 90);
    root = insert(root, 78);
*/