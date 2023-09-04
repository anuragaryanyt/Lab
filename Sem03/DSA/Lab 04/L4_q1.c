#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
} *start = NULL;

struct node *createnode(struct node *end)
{
    int data;
    printf("\nEnter Data : ");
    scanf("%d", &data);

    struct node *node = (struct node *)malloc(sizeof(struct node *));
    node->value = data;
    node->next = NULL;
    if (start == NULL)
        start = node;
    else
    {
        end->next = node;
    }
    return node;
}

void printnode()
{
    printf("\n");
    struct node *node = start;
    while (node != NULL)
    {
        printf("%d\t", node->value);
        node = node->next;
    }
}

void swap()
{
    struct node *q;
    q = start;
    int temp;
    while (q != NULL && q->next != NULL)
    {
        temp = q->value;
        q->value = q->next->value;
        q->next->value = temp;
        q = q->next->next;
    }
}

void addatdata()
{
    int data, item;
    printf("\nEnter the data where you want to add node: ");
    scanf("%d", &item);
    printf("\nEnter Data : ");
    scanf("%d", &data);
    struct node *node = (struct node *)malloc(sizeof(struct node *));
    struct node *n;
    node = start;
    while (node->value != item && node != NULL)
    {
        node = node->next;
    }
    if (node != NULL)
    {
        // n->next=node->next;
        // node->next=n;
        // node->value = data;
        // node->next = start;
        // start=node;
        node->next = n;
        n->next = node->next;
    }
    else
    {
        printf("Data not found");
    }
}

void delkey()
{
    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    struct node *temp;
    struct node *ptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        if ((ptr->next)->value != NULL)
        {
            temp = ptr->next;
            ptr->next = (ptr->next)->next;
            free(temp);
            ptr = ptr->next;
        }
        else
        {
            ptr = ptr->next;
        }
    }
}
void addnode()
{
    int data;
    printf("\nEnter Data : ");
    scanf("%d", &data);

    struct node *node = (struct node *)malloc(sizeof(struct node *));
    node->value = data;
    node->next = start;
    start = node;
}

struct node *nposition(struct node *end)
{
    int data, n;
    printf("\nEnter Position : ");
    scanf("%d", &n);

    if (n == 1)
    {
        addnode();
        return end;
    }

    printf("\nEnter Data : ");
    scanf("%d", &data);

    struct node *temp = start;
    int flag = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (temp == NULL)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    struct node *node = (struct node *)malloc(sizeof(struct node *));
    if (flag == 0)
    {
        node->value = data;
        node->next = temp->next;
        temp->next = node;
    }
    else
    {
        printf("\nInvalid Position");
        free(node);
    }

    if (end->next != NULL)
        return node;
    return end;
}

int main()
{
    struct node *end = NULL;
    int ch;
    while (1)
    {
        printf("\n\t\t*****MENU*****");
        printf("\n1. Create list \n2. Display \n3. Add node \n4. Add node at N position \n5. Exit \n6. Swap \n7.add node at specific data \n8. Del at key");
        printf("\n Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("-----Creating Node-----");
            end = createnode(end);
            break;
        case 2:
            printf("\n -----Displaying Nodes-----");
            printnode();
            break;
        case 3:
            addnode();
            break;
        case 4:
            printf("\n -----Node added at n position-----");
            end = nposition(end);
            break;
        case 5:
            free(end);
            free(start);
            exit(0);
            break;
        case 6:
            swap();
            break;
        case 7:
            addatdata();
            break;
        case 8:
            delkey();
            break;
        }
    }
    return 0;
}

/*void nposition(int data, int position)
{
    struct node *temp = start;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }

    struct node *node = (struct node *)malloc(sizeof(struct node *));
    node->value = data;
    node->next = temp->next;

    temp->next = node;
}*/
