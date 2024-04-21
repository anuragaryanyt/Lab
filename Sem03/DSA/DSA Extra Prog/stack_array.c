#include <stdio.h>
#include<stdlib.h>
struct stack
{
    int arr[10];
    int size;
    int top;
};
void ini_stack(struct stack *stack)
{
    stack->top = -1;
    stack->size = 10;
}
int overflow(int top)
{
    if (top ==9)
        return 1;
    return 0;
}
int underflow(int top)
{
    if (top == -1)
        return 1;
    return 0;
}
void push(struct stack *stack)
{
    int data;
    printf("Enter the data to be pushed: ");
    scanf("%d", &data);
    if (!overflow(stack->top))
    {
        stack->top++;
        stack->arr[stack->top] = data;
    }
    else
        printf("Stack overflow!!");
}
void pop(struct stack *stack)
{
    if (!underflow(stack->top))
    {
        printf("Data popped %d\n", stack->arr[stack->top]);
        stack->top--;
    }
    else
        printf("stack underflow");
}
void display(struct stack *stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d\t", stack->arr[i]);
    }
    printf("\n");
}
int main()
{
    int ch;
    struct stack *stack;
    ini_stack(stack);
    while (1)
    {
        printf("----MENU----\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
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
        case 4:
            exit(0);
            break;
        }
    }
}

