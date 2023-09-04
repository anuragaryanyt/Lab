//multiplication of two polynomial

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    int pow;
    struct Node* next;
};
struct Node* createlist(struct Node* head, int k)
{
    printf("Enter values for the nodes : \n");
    for (int i = 0;i < k;i++)
    {
        int data, pow;
        printf("Enter coefficient : \n");
        scanf("%d", &data);
        printf("Enter power of x : \n");
        scanf("%d", &pow);
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->pow = pow;
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;


        else
        {
            struct Node* last = head;
            while (last->next != NULL)
                last = last->next;

            last->next = newnode;
        }
    }
    return head;
}
void printNode(struct Node* n)
{
    while (n != NULL)
    {
        if (n->next == NULL)
        {
            if (n->pow == 0)
                printf("%d", n->data, n->pow);
            else
                printf("%dx^%d", n->data, n->pow);
        }
        else
        {
            if (n->pow == 0)
                printf("%d + ", n->data, n->pow);
            printf("%dx^%d + ", n->data, n->pow);
        }
        n = n->next;
    }
}
struct Node* createNode(struct Node* h3, int data, int pow)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->pow = pow;
    newnode->next = NULL;

    if (h3 == NULL)
        h3 = newnode;

    else
    {
        struct Node* last = h3;

        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newnode;

    }
    return h3;
}
struct Node* removeDup(struct Node* h3)
{
    struct Node* n1, * n2, * dup;
    n1 = h3;
    while (n1 != NULL && n1->next != NULL)
    {
        n2 = n1;
        while (n2->next != NULL)
        {
            if (n1->pow == n2->next->pow)
            {
                n1->data = n1->data + n2->next->data;
                dup = n2->next;
                n2->next = n2->next->next;
                free(dup);
            }
            else
                n2 = n2->next;
        }
        n1 = n1->next;
    }
    return h3;
}
struct Node* multiplyNode(struct Node* h1, struct Node* h2, struct Node* h3)
{
    int data, pow;
    for (struct Node* n1 = h1; n1 != NULL; n1 = n1->next)
    {
        for (struct Node* n2 = h2; n2 != NULL; n2 = n2->next)
        {
            data = n1->data * n2->data;
            pow = n1->pow + n2->pow;
            h3 = createNode(h3, data, pow);
        }
    }
    removeDup(h3);
    return h3;

}
int main()
{
    int k;

    struct Node* h1 = NULL;
    struct Node* h2 = NULL;
    struct Node* h3 = NULL;

    printf("Enter the number of terms in the 1st polynomial : ");
    scanf("%d", &k);
    h1 = createlist(h1, k);
    printNode(h1);
    printf("\n\n");

    printf("Enter the number of terms in the 2nd polynomial : ");
    scanf("%d", &k);
    h2 = createlist(h2, k);
    printNode(h2);
    printf("\n\n");

    h3 = multiplyNode(h1, h2, h3);
    printf("The product of the two polynomials : ");
    printNode(h3);

    return 0;
}