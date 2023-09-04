/* WAP to implement two stacks in one array to minimize the overflow in the stack */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int s[MAX];
int top1 = -1, top2 = MAX;
void push(int data, int num)
{
    if (top1 + 1 == top2)
    {
        printf("Stack overflow");
        return;
    }

    if (num == 1)
    {
        top1++;
        s[top1] = data;
    }
    else
    {
        top2--;
        s[top2] = data;
    }
}

void pop(int num)
{
    if (top1 == -1 && top2 == MAX)
    {
        printf("Stack underflow");
        return;
    }

    if (num == 1 && top1 != -1)
    {
        printf("Popped Data : %d", s[top1]);
        top1--;
    }
    else if (num == 2 && top2 != MAX)
    {
        printf("Popped Data : %d", s[top2]);
        top2++;
    }
}

void display(int num)
{
    if (top1 == -1 && top2 == MAX)
    {
        printf("Stack Empty");
        return;
    }

    if (num == 1 && top1 != -1)
    {
        for (int i = 0; i <= top1; i++)
            printf("%d\t", s[i]);
    }

    else if (num == 2 && top2 != MAX)
    {
        for (int i = MAX - 1; i >= top2; i--)
            printf("%d\t", s[i]);
    }
}

void main()
{

    int ch, data;

    while (1)
    {
        printf("\n\nMENU\n1.Push in Stack 1\n2.Push in Stack 2\n3.Pop in Stack 1\n4.Pop in Stack 2\n5.Display Stack 1\n6.Displays Stack 2\n");
        printf("\nEnter Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Data : ");
            scanf("%d", &data);
            push(data, 1);
            break;

        case 2:
            printf("Enter Data : ");
            scanf("%d", &data);
            push(data, 2);
            break;

        case 3:
            pop(1);
            break;

        case 4:
            pop(1);
            break;

        case 5:
            display(1);
            break;

        case 6:
            display(2);
            break;

        default:
            exit(0);
            break;
        }
    }
}

/*
#include <stdio.h>
#define SIZE 20
int array[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int data)
{

    if (top1 < top2 - 1)
    {
        top1++;
        array[top1] = data;
    }
    else
    {
        printf("Stack is full");
    }
}

void push2(int data)
{

    if (top1 < top2 - 1)
    {
        top2--;
        array[top2] = data;
    }
    else
    {
        printf("Stack is full.. \n");
    }
}

void pop1()
{

    if (top1 >= 0)
    {
        int popped_element = array[top1];
        top1--;

        printf("\n %d is being popped from Stack 1", popped_element);
    }
    else
    {
        printf("Stack is Empty \n");
    }
}

void pop2()
{

    if (top2 < SIZE)
    {
        int popped_element = array[top2];
        top2--;

        printf("%d is being popped from Stack 1\n", popped_element);
    }
    else
    {
        printf("Stack is Empty!\n");
    }
}

void display_stack1()
{
    int i;
    for (i = top1; i >= 0; --i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void display_stack2()
{
    int i;
    for (i = top2; i < SIZE; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int ar[SIZE];
    int i;
    int num_of_ele;

    printf("We can push a total of 20 values\n");
    for (i = 1; i <= 10; ++i)
    {
        push1(i);
        printf("Value Pushed in Stack 1 is %d\n", i);
    }

    for (i = 11; i <= 20; ++i)
    {
        push2(i);
        printf("Value Pushed in Stack 2 is %d\n", i);
    }

    display_stack1();
    display_stack2();

    printf("Pushing Value in Stack 1 is %d\n", 11);
    push1(11);

    num_of_ele = top1 + 1;
    while (num_of_ele)
    {
        pop1();
        --num_of_ele;
    }

    pop1();

    return 0;
}
*/