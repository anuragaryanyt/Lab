// Wap to Traverse a tree in InOrder (Non-Recursive)

#include <stdio.h>
#include <stdlib.h>
#define bool int

struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
};

struct sNode
{
    struct tNode *t;
    struct sNode *next;
};

void push(struct sNode **top_ref, struct tNode *t);
struct tNode *pop(struct sNode **top_ref);
bool isEmpty(struct sNode *top);

void inOrder(struct tNode *root)
{
    struct tNode *current = root;
    struct sNode *s = NULL;
    bool done = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }

        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%d ", current->data);

                current = current->right;
            }
            else
                done = 1;
        }
    }
}

void push(struct sNode **top_ref, struct tNode *t)
{
    struct sNode *new_tNode =
        (struct sNode *)malloc(sizeof(struct sNode));

    if (new_tNode == NULL)
    {
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }

    new_tNode->t = t;
    new_tNode->next = (*top_ref);
    (*top_ref) = new_tNode; // head ptr to new node
}

bool isEmpty(struct sNode *top) // return true stack empty
{
    return (top == NULL) ? 1 : 0;
}

struct tNode *pop(struct sNode **top_ref)
{
    struct tNode *res;
    struct sNode *top;

    /*If sNode is empty then error */
    if (isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

/* Helper function that allocates a new tNode with the
given data and NULL left and right pointers. */
struct tNode *newtNode(int data)
{
    struct tNode *tNode = (struct tNode *)malloc(sizeof(struct tNode));
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;

    return (tNode);
}

int main()
{
    struct tNode *root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);

    inOrder(root);
    getchar();
    return 0;
}
