// WAP to construct an expression tree for the given Prefix/Postfix.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
    struct node *next;
};
struct node *head = NULL;
struct node *newNode(char data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;

    return (node);
}

void inorder(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }
}

void push(struct node *x)
{
    if (head == NULL)
        head = x;
    else
    {
        (x)->next = head;
        head = x;
    }
}
struct node *pop()
{
    struct node *p = head; // pop top most ele
    head = head->next;
    return p;
}

int main()
{
    char s[] = {'p', 'r', 'a', '*', '+', 'd', '/', 'q', '+'};
    int l = sizeof(s) / sizeof(s[0]);
    struct node *x, *y, *z;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            z = newNode(s[i]);
            x = pop();
            y = pop();
            z->left = y;
            z->right = x;
            push(z);
        }
        else
        {
            z = newNode(s[i]);
            push(z);
        }
    }
    printf("Expression Tree : ");
    inorder(z);
    return 0;
}
/*
int post_eva(char *post)
{
    int i = 0, k = 0;
    char data[3];
    while (post[i] != '\0')
    {
        switch (post[i])
        {
        case '+':
            evaluate(1);
            k = 0;
            break;
        case '-':
            evaluate(2);
            k = 0;
            break;
        case '*':
            evaluate(3);
            k = 0;
            break;
        case '/':
            evaluate(4);
            k = 0;
            break;
        case '%':
            evaluate(5);
            k = 0;
            break;
        default:
            if (post[i] != ' ')
            {
                data[k++] = post[i];
            }
            else if (post[i] != ' ' && k > 0)
            {
                data[k] = '\0' push(s1, atoi(data));
            }
        }
        i++;
    }
    return pop(s1);
}*/