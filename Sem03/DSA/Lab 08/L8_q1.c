/* Implement a circular queue by writing menu driven prog which func like
1.Insertion 2.Deletion 3.Display*/

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;
void insert(int item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1 && front != 0)
            rear = 0;
        else
            rear++;
    }
    queue[rear] = item;
}

void delete ()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted: %d\n", queue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
}

void display()
{
    if (front == 0 && rear == -1)
    {
        printf("Queue Empty");
        return;
    }
    int temp = front;
    while (temp != rear)
    {
        printf("%d\t", queue[temp++]);
        if (temp == MAX)
            temp = 0;
    }
    printf("%d\t", queue[temp]);
}


int main()
{
    int choice, item;
    do
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the element for insertion in queue : ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 4);
    return 0;
}

