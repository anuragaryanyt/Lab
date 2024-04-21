//circular linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void create(struct Node** start)
{
    int data;
    printf("Enter Data : ");
    scanf("%d", &data);

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;

    if (*start == NULL)
    {
        *start = node;
        (*start)->next = *start;
    }
    else
    {
        struct Node* temp = *start;
        while (temp->next != *start)
            temp = temp->next;

        node->next = *start;
        temp->next = node;
    }
}

void traverse(struct Node* start)
{
    struct Node* temp = start;
    if (start != NULL)
        do
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while (temp != start);
}

void addFirst(struct Node** start)
{
    int data;
    printf("Enter Data : ");
    scanf("%d", &data);

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = *start;

    struct Node* temp = *start;
    while (temp->next != *start)
        temp = temp->next;

    *start = node;
    temp->next = *start;
}

void deleteFirst(struct Node** start)
{
    if (*start == (*start)->next)
    {
        *start = NULL;
        return;
    }
    struct Node* temp = *start;
    while (temp->next != *start)
        temp = temp->next;

    *start = (*start)->next;
    temp->next = *start;
}

void main()
{
    int ch;
    struct Node* start = NULL;

    while (1)
    {
        printf("\n\n\nMENU\n");
        printf("0. Exit\n");
        printf("1. Create Node\n");
        printf("2. Traverse\n");
        printf("3. Add a First Node\n");
        printf("4. Delete First Node\n");
        printf("\n\nEnter Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            exit(1);
            break;

        case 1:
            create(&start);
            break;

        case 2:
            traverse(start);
            break;

        case 3:
            addFirst(&start);
            break;

        case 4:
            deleteFirst(&start);
            break;

        default:
            printf("Invalid Choice");
        }
    }
}