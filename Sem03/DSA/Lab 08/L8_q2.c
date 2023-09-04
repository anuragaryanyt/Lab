/* Implement a queue ADT */
#include <stdio.h>
#define size 5
struct queue
{
    int q[size];
    int front, rear;
};

void ini(struct queue *queue)
{
    queue->front = 0;
    queue->rear = -1;
    printf("queue");
}

void insert(struct queue *queue, int data)
{
    if ((queue->front == 0 && queue->rear == size - 1) || ((queue->front == queue->rear + 1) && queue->rear != -1))
    {
        printf("queue Overflow");
        return;
    }
    queue->rear = ++(queue->rear) % size;
    queue->q[queue->rear] = data;
    printf("%d\t%d", queue->front, queue->rear);
}

void delete (struct queue *queue)
{
    if (queue->front == 0 && queue->rear == -1)
    {
        printf("queue Underflow");
        return;
    }
    else if (queue->front == queue->rear)
    {
        queue->front = 0;
        queue->rear = -1;
    }
    else
        queue->front = ++(queue->front) % size;

    printf("Deleted Element : %d", queue->front);
}

void display(struct queue *queue)
{
    if (queue->front == 0 && queue->rear == -1)
    {
        printf("queue Empty");
        return;
    }
    int temp = queue->front;
    while (temp != queue->rear)
    {
        printf("%d\t", queue->q[temp++]);
        if (temp == size)
            temp = 0;
    }
    printf("%d\t", queue->q[temp]);
}

void main()
{
    struct queue *queue;
    ini(queue);

    int ch, data;
    while (1)
    {
        printf("\n----MENU----");
        printf("\n1.Insertion");
        printf("\n2.Deletion");
        printf("\n3.Display");
        printf("\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Data : ");
            scanf("%d", &data);
            insert(queue, data);
            break;

        case 2:
            delete (queue);
            break;

        case 3:
            display(queue);
            break;
        case 4:
            exit(0);
            break;
        
        }
    }
}
