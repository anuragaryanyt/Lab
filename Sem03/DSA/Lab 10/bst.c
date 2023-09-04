#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};


void create(int value, struct node** root)
{
    struct node* new, * par, * node = *root;

    new = (struct node*)malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;

    if (node == NULL)
        *root = new;
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

void preorder(struct node* node)
{
    if (node != NULL)
    {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(struct node* node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}

void postorder(struct node* node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void currLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d\t", root->data);
    else if (level > 1) {
        currLevel(root->left, level - 1);
        currLevel(root->right, level - 1);
    }
}

void levelorder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        currLevel(root, i);
}

void search(int key, struct node* node)
{
    if (node)
    {
        if (node->data == key)
            printf("Data Found");

        if (key < node->data)
            search(key, node->left);
        else
            search(key, node->right);
    }
}

void delete(struct node* root, int value)
{
    struct node* ptr = root, * par = NULL;

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

        printf("Delete Successful");
    }

    else if (!ptr->left || !ptr->right)
    {
        struct node* p;
        if (ptr->left != NULL)
            p = ptr->left;
        else
            p = ptr->right;

        if (par->data < ptr->data)
            par->right = p;
        else
            par->left = p;

        printf("Delete Successful");
    }

    else
    {
        struct node* temp = ptr->left;

        while (temp->right)
            temp = temp->right;

        int val = temp->data;
        delete(root, temp->data);
        ptr->data = val;
    }
}

void main()
{
    struct node* root = NULL;

    while (1)
    {
        int ch;
        printf("\n\nMENU");
        printf("\n1. Create BST");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Levelorder Traversal");
        printf("\n6. Search");
        printf("\n7. Delete");

        printf("\n\nEnter Choice : ");
        scanf("%d", &ch);

        int value;
        switch (ch)
        {
        case 1:
            printf("Enter Value : ");
            scanf("%d", &value);
            create(value, &root);
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
            printf("Enter Value to be searched : ");
            scanf("%d", &value);
            search(value, root);
            break;

        case 7:
            printf("Enter Value to be delete : ");
            scanf("%d", &value);
            delete(root, value);
            break;

        default:
            break;
        }
    }
}
