#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void create(struct node **start, struct node **last)

{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *node = (struct node *)malloc(sizeof(struct node *));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if (*start == NULL)
    {
        *start = node;
        *last = node;
    }
    else
    {
        node->prev = *last;
        (*last)->next = node;
        (*last) = node;
    }
}

void traverseforward(struct node *last)
{
    struct node *temp = last;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
}
void main()
{
    int ch;
    struct node *start = NULL;
    struct node *last = NULL;
    while (1)
    {
        printf("------MENU ----------\n");
        printf("\n1. create new node");
        printf("\n2. Traverse forward");
        printf("\n0. Exit program");
        scanf("%d", ch);
        switch (ch)
        {

        case 1:
        create();
        break;
        case 2:
        traverseforward(last);
        }
    }
}
