// Wap to implement the operation of double ended queue.

#include <stdio.h>
#include <stdlib.h>
#define size 10
int arr[size], R = -1, F = 0, count = 0, n, i, x;

void AddRear()
{
    if (count == size)
    {
        printf("Queue is full");
    }
    else
    {
        printf("Enter a number ");
        scanf("%d", &n);
        R = (R + 1) % size;
        arr[R] = n;
        count = count + 1;
    }
}

void DelRear()
{
    if (count == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        if (R == -1)
        {
            R = size - 1;
        }
        printf("Number Deleted From Rear End = %d", arr[R]);
        R = R - 1;
        count = count - 1;
    }
}

void AddFront()
{
    if (count == size)
    {
        printf("Queue is full");
    }
    else
    {
        printf("Enter a number ");
        scanf("%d", &n);
        if (F == 0)
        {
            F = size - 1;
        }
        else
        {
            F = F - 1;
        }
        arr[F] = n;
        count = count + 1;
    }
}

void DelFront()
{
    if (count == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Number Deleted From Front End = %d", arr[F]);
        F = (F + 1) % size;
        count = count - 1;
    }
}

void display()
{
    if (count == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        // x = F;
        for (i = 1; i <= count; i++)
        {
            printf("%d ", arr[F]);
            F = (F + 1) % size;
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("\nF=%d  R=%d\n\n", F, R);
        printf("1. Add Rear\n");
        printf("2. Delete Rear\n");
        printf("3. Add Front\n");
        printf("4. Delete Front\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            AddRear();
            break;
        case 2:
            DelRear();
            break;
        case 3:
            AddFront();
            break;
        case 4:
            DelFront();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        }
    }
}
