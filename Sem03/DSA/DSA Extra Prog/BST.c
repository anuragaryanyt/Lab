#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
create(int value)
{
    struct node *new, *node, *par, *root;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;

    node = root;
    par = NULL;
    if (node == NULL)
        root = new;
    else
    {
        while (node != NULL)
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
int main()
{
    struct node *root;
    int no;
    printf("ENter the no in tree: ");
    scanf("%d", &no);
    create(no);
    return 0;
}




// int main()
// {
//     int no, ch;
//     struct node *new, *node, *par, *root;
//     while (1)
//     {
//         printf("1. create\n");
//         printf("2. exit\n");
//         printf("choices: ");
//         scanf("%d", ch);
//         switch (ch)
//         {
//         case 1:
//             create(no);
//             printf("ENter the no in tree: ");
//             scanf("%d", &no);
//             break;
//         case 2:
//             exit(0);
//             break;
//         }
//     }
// }