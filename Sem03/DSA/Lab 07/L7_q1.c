#include <stdio.h>
struct Stack
{
    int arr[10];
    int top;
    int size;
};

void ini_stack(struct Stack *stack)
{
    stack->top = -1;
    stack->size = 10;
}
int checkOverflow(int top)
{
    if (top == 9)
        return 1;
    return 0;
}

int checkUnderflow(int top)
{
    if (top == -1)
        return 1;
    return 0;
}

void push(struct Stack *stack)
{
    int data;
    printf("Enter Data to be pushed : ");
    scanf("%d", &data);

    if (!checkOverflow(stack->top))
    {
        stack->top++;
        stack->arr[stack->top] = data;
    }
    else
        printf("Stack Overflow \n");
}

void pop(struct Stack *stack)
{
    if (!checkUnderflow(stack->top))
    {
        printf("Popped Element : %d", stack->arr[stack->top]);
        stack->top--;
    }
    else
        printf("Stack Underflow\n");
}

void display(struct Stack *stack)
{
    for (int i = 0; i <= stack->top; i++)
        printf("%d\t", stack->arr[i]);
    printf("\n");
}

void main()
{
    struct Stack *stack;
    int choice;
    ini_stack(stack);
    while (1)
    {
        printf("\n-----MENU-----\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(stack);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            display(stack);
            break;
        default:
            break;
        }
    }
}
