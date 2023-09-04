#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
struct node *root = NULL;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void create(int value)
{
    struct node *new, *par, *node = root;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    node->height = 1;

    if (node == NULL)
        root = new;
    else
    {
        while (node)
        {
            par = node;
            if (value < node->data)
                node = node->left;
            else
                node = node->right;
        }
        if (value < par->data)
            par->left = new;
        else
            par->right = new;
    }
    node->height = 1+ max(height(node->left), height(node->right));
    int bf = balfactor(node);

    // LL case
    if (bf > 1 && value < node->left->value)
        return leftrotate(node);

    // RR case
    if (bf < -1 && value < root->right->value)
        return rightrotate(node);

    //LR case
    if (bf > 1 && value>node->left->value)
    {
        node->left=leftrotate(node->left);
        return rightrotate(node);
    }

    //RL case
    if (bf < -1 && value<node->right->value)
    {
        node->right=rightrotate(node->left);
        return leftrotate(node);
    }
}

int height(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int balfactor(struct node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
};

// right rotation
struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->right), height(y->left));
    x->height = max(height(x->right), height(x->left));
}
// left rotation
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(height(y->right), height(y->left));
    x->height = max(height(x->right), height(x->left));
}

void inorder(struct node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}
void main()
{

    
}