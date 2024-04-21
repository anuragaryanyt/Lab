//Write a program to represent a polynomial using linked list. Write a function to add two polynomials.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int cof;
    int deg;
    struct node *next;
};

void create(struct node **st, struct node **lt, int cof, int deg)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->cof = cof;
    n->deg = deg;
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
void add(struct node **s1, struct node **s2, struct node **s3, struct node **l3)
{
    int flag = 0;
    struct node *t2 = (*s2), *t3 = (*s3);

    while (t2 != NULL)
    {
        while (t3 != NULL)
        {
            if (t2->deg == t3->deg)
            {
                t3->cof += t2->cof;
                flag = 1;
            }
            t3 = t3->next;
        }
        if (flag == 0)
            create(&(*s3), &(*l3), t2->cof, t2->deg);
        t3 = (*s3);
        flag = 0;
        t2 = t2->next;
    }
}
void display(struct node **s)
{
    struct node *temp = (*s), *n = (*s)->next;
    while (temp != NULL)
    {
        n = temp->next;
        while (n != NULL)
        {
            if (temp->deg > n->deg)
            {
                int co, de;
                co = temp->cof;
                temp->cof = n->cof;
                n->cof = co;

                de = temp->deg;
                temp->deg = n->deg;
                n->deg = de;
            }
            n = n->next;
        }
        temp = temp->next;
    }

    struct node *dis = (*s);
    while (dis != NULL)
    {
        printf("%dx^%d", dis->cof, dis->deg);
        if (dis->next != NULL)
            printf(" + ");
        dis = dis->next;
    }
}

void main()
{
    struct node *s1 = NULL, *l1 = NULL, *s2 = NULL, *l2 = NULL, *s3 = NULL, *l3 = NULL;
    create(&s1, &l1, 7, 9);
    create(&s1, &l1, 6, 7);
    create(&s1, &l1, 5, 10);
    printf("1. ");
    display(&s1);
    s3 = s1;
    l3 = l1;
    create(&s2, &l2, 6, 7);
    create(&s2, &l2, 1, 2);
    create(&s2, &l2, 3, 9);
    printf("\n2. ");
    display(&s2);
    add(&s1, &s2, &s3, &l3);
    printf("\n");
    display(&s3);
}
