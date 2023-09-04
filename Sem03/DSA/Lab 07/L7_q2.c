#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
} *top = NULL;

void push(int element);
int pop();
void display();

void push(int element)
{
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    printf("Data pushed to stack.\n");
}

int pop()
{
    int data;
    if (!top)
        printf("Stack is empty.\n");

    data = top->data;
    top = top->next;

    return data;
}

void display()
{
    struct stack *temp = top;
    struct node 
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void main()
{
    int choice, data;

    while (1)
    {

        printf("MENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to push into stack: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            data = pop();
            printf("Popped Data => %d\n", data);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
        }

        printf("\n\n");
    }
}

