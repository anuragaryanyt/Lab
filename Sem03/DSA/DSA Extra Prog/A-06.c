/* WAP to construct tree using inorder and preorder traversals */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

int search(char arr[], int strt, int end, char value);
struct node *newNode(char data);

struct node *buildTree(char in[], char pre[], int istart, int inEnd)
{
    static int preIndex = 0;

    if (istart > inEnd)
        return NULL;
    struct node *tNode = newNode(pre[preIndex++]);
    if (istart == inEnd)
        return tNode;
    int inIndex = search(in, istart, inEnd, tNode->data);
    tNode->left = buildTree(in, pre, istart, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
}

struct node *newNode(char data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void postorder(struct node *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf(" %c ", node->data);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf(" %c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int i, n;
    printf("Enter the number of elements you want to enter:");
    scanf("%d", &n);
    char in[n];
    char pre[n];

    printf("Input elements inorder:\n");
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("nodes - %d : ", i);
        scanf("%c", &in[i]);
    }
    printf("\n");
    printf("Input elements preorder:\n");
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("nodes - %d : ", i);
        scanf("%c", &pre[i]);
    }

    printf("\nInorder: ");
    for (i = 0; i < n; i++)
        printf("%c ", in[i]);

    printf("\npreorder: ");
    for (i = 0; i < n; i++)
        printf("%c  ", pre[i]);

    int len = sizeof(in) / sizeof(in[0]);
    struct node *root = buildTree(in, pre, 0, len - 1);

    printf("\nPostrder traversal of the constructed tree is: ");
    postorder(root);
    getchar();
}
