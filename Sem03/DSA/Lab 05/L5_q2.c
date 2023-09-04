//Write a program to merge two sorted linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **st, struct node **lt, int num)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = num;
    n->next = NULL;

    if ((*st) == NULL)
    {
        (*st) = n;
        (*lt) = n;
    }
    else
    {
        (*lt)->next = n;
        (*lt) = n;
    }
}
void traverse(struct node **st)
{
    struct node *temp = (*st);
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void sortMerge(struct node **s1, struct node **s2)
{
    struct node *t1 = (*s1), *t2 = (*s2);
    struct node *temp;

    if (t1->data < t2->data)
    {
        temp = t1;
        t1 = t1->next;
    }
    else
    {
        temp = t2;
        t2 = t2->next;
    }

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }

    if (t1 != NULL)
        temp->next = t1;
    else
        temp->next = t2;
}

void main()
{
    struct node *s1 = NULL, *l1 = NULL, *s2 = NULL, *l2 = NULL;
    printf("Linked List 1:\n");
    create(&s1, &l1, 1);
    create(&s1, &l1, 3);
    create(&s1, &l1, 8);
    create(&s1, &l1, 13);
    create(&s1, &l1, 21);
    create(&s2, &l2, 2);
    create(&s2, &l2, 4);
    create(&s2, &l2, 5);
    create(&s2, &l2, 17);
    create(&s2, &l2, 22);
    traverse(&s1);
    printf("Linked List 2:\n");
    traverse(&s2);
    sortMerge(&s1, &s2);
    traverse(&s1);
}
