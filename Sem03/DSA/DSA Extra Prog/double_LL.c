//double linked list

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void create(struct Node** start, struct Node** last)
{
    int data;
    printf("Enter Data : ");
    scanf("%d", &data);

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
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

void traverseForward(struct Node* start)
{
    struct Node* temp = start;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void traverseBackward(struct Node* last)
{
    struct Node* temp = last;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
}

void addAfterData(struct Node* start)
{
    int data, pos;
    printf("Enter Data of new Node and Data of previous Node : ");
    scanf("%d%d", &data, &pos);

    struct Node* temp = start;
    while (temp != NULL)
    {
        if (temp->data == pos)
        {
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->data = data;
            node->next = temp->next;
            node->prev = temp;
            temp->next = node;
            node->next->prev = node;
            printf("Node Entered");
            return;
        }
        temp = temp->next;
    }
    printf("No Existing Data Found");
}

void addBeforeData(struct Node* start)
{
    int data, pos;
    printf("Enter Data of new Node and Data of previous Node : ");
    scanf("%d%d", &data, &pos);

    struct Node* temp = start;
    while (temp != NULL)
    {
        if (temp->data == pos)
        {
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->data = data;
            node->next = temp;
            node->prev = temp->prev;
            temp->prev->next = node;
            temp->prev = node;
            printf("Node Entered");
            return;
        }
        temp = temp->next;
    }
    printf("No Existing Data Found");
}

void deleteAtPosition(struct Node** start)
{
    int pos;
    printf("Enter Position : ");
    scanf("%d", &pos);

    if (pos == 1)
        *start = (*start)->next;

    else
    {
        struct Node* temp = *start;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        temp->next->next->prev = temp;
        temp->next = temp->next->next;
    }
}

void addFirstNode(struct Node** start)
{
    int data;
    printf("Enter Data : ");
    scanf("%d", &data);

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = *start;
    (*start)->prev = node;
    *start = node;
}

void deleteFirstNode(struct Node** start)
{
    *start = (*start)->next;
}

void reverse(struct Node** start)
{
    struct Node* end = *start;
    struct Node* curr = *start;
    struct Node* prev = NULL;
    if (start == NULL)
        return;
    while (end->next != NULL)
    {
        curr = end;
        end = end->next;
        curr->next = prev;
        prev = curr;
    }
    curr = end;
    curr->next = prev;
    *start = curr;
}

void main()
{
    int ch;
    struct Node* start = NULL;
    struct Node* last = NULL;
    while (1)
    {
        printf("\nMENU\n");
        printf("0. Exit\n");
        printf("1. Create Node\n");
        printf("2. Traverse Forward\n");
        printf("3. Traverse Backward\n");
        printf("4. Add Node After Given Data\n");
        printf("5. Add Node Before Given Data\n");
        printf("6. Delete a node at a given position\n");
        printf("7. Add first node\n");
        printf("8. Delete first node\n");
        printf("9. Reverse the content of the linked list\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create(&start, &last);
            break;
        case 2:
            if (start == NULL)
                printf("Empty List");
            else
                traverseForward(start);
            break;
        case 3:
            if (start == NULL)
                printf("Empty List");
            else
                traverseBackward(last);
            break;
        case 4:
            addAfterData(start);
            break;
        case 5:
            addBeforeData(start);
            break;
        case 6:
            deleteAtPosition(&start);
            break;
        case 7:
            addFirstNode(&start);
            break;
        case 8:
            deleteFirstNode(&start);
            break;
        case 9:
            reverse(&start);
            break;
        case 0:
            break;
        }
    }
}
