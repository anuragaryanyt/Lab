// Wap to perform circular rotation using D-queue.

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
void popPush(int q[], int* front, int* rear)
{
    int pop = q[*front];
    for (int i = 0;i < SIZE - 1;i++)
        q[i] = q[i + 1];

    q[*rear] = pop;
}

void main()
{
    int q[SIZE];
    int front = 0, rear = SIZE - 1;
    printf("Enter elements : ");
    for (int i = 0;i < SIZE;i++)
        scanf("%d", &q[i]);

    int index;
    printf("Enter degree of rotation : ");
    scanf("%d", &index);

    for (int i = 1;i <= index;i++)
        popPush(q, &front, &rear);

    printf("Array : \n ");
    for (int i = 0;i < SIZE;i++)
        printf("%d\t", q[i]);
}
