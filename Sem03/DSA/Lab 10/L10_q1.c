/* Write a menu driven prog to perform the following operation on BST..
1.create 2.Traverse in Preorder 3.Inorder 4.Postorder 5.Level order 6.Search a element 7.Deletion*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

void create(int value)
{
    struct node *new, *par, *node = root;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;

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
}

void preorder(struct node *node)
{
    if (node != NULL)
    {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
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

void postorder(struct node *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}

int height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void currLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d\t", root->data);
    else if (level > 1)
    {
        currLevel(root->left, level - 1);
        currLevel(root->right, level - 1);
    }
}

void levelorder(struct node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        currLevel(root, i);
}

void search(int key, struct node *node)
{
    if (node != NULL)
    {
        if (node->data == key)
            printf("Data found");

        if (key < node->data)
            return search(key, node->left);
        else
            return search(key, node->right);
    }
    printf("%d\t", key);
}

void delete(struct node *root, int value)
{
    struct node *ptr = root, *par = NULL;
    while (ptr->data != value)
    {
        par = ptr;
        if (value < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if (!ptr->left && !ptr->right)
    {
        if (par->data < ptr->data)
            par->right = NULL;
        else
            par->left = NULL;
    }

    else if (!ptr->left || !ptr->right)
    {
        struct node *p;
        if (ptr->left != NULL)
            p = ptr->left;
        else
            p = ptr->right;

        if (par->data < ptr->data)
            par->right = p;
        else
            par->left = p;

        printf("Element Deleted Successful");
    }
    else
    {
        struct node *temp = ptr->left;

        while (temp->right)
            temp = temp->right;

        int val = temp->data;
        delete (root, temp->data);
        ptr->data = val;
    }
}

void main()
{
    while (1)
    {
        int value, s, d,ch;
        printf("\n----MENU----");
        printf("\n1. Create");
        printf("\n2. Preorder");
        printf("\n3. Inorder");
        printf("\n4. Postorder");
        printf("\n5. Levelorder");
        printf("\n6. Search");
        printf("\n7. Deletion");
        printf("\n8. Exit");
        printf("\nEnter Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Value : ");
            scanf("%d", &value);
            create(value);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            levelorder(root);
            break;
        case 6:
            printf("Enter the element to be searched: ");
            scanf("%d", &s);
            search(s, root);
            break;
        case 7:
            printf("Enter the element to b deleted: ");
            scanf("%d", &d);
            delete(root, d);
            break;
        case 8:
            exit(0);
            break;
        }
    }
}

