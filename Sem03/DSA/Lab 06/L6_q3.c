#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char name[100];
    int roll;
    float cgpa;
    char address[100];
    char branch[50];
    struct Node* next;
};
struct Node_head
{
    int count;
    struct Node* next;
};

void create(struct Node_head** start)
{
    char name[100];
    int roll;
    float cgpa;
    char address[100];
    char branch[50];
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter name : ");
    scanf("%s", node->name);
    printf("Roll : ");
    scanf("%d", &node->roll);
    printf("CGPA : ");
    scanf("%f", &node->cgpa);
    printf("Address : ");
    scanf(" %s", node->address);
    printf("Branch : ");
    scanf(" %s", node->branch);

    node->next = NULL;

    if (*start == NULL)
    {
        struct Node_head* head = (struct Node_head*)malloc(sizeof(struct Node_head));
        head->next = node;
        head->count = 0;
        head->count++;
        *start = head;
    }
    else
    {
        struct Node* temp = (*start)->next;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = node;
        (*start)->count++;
    }
}

void display(struct Node_head* start)
{
    struct Node* temp = start->next;
    int c = 1;

    while (temp != NULL)
    {
        printf("Student %d\n", c++);
        printf("Name : %s\n", temp->name);
        printf("Roll : %d\n", temp->roll);
        printf("CGPA : %f\n", temp->cgpa);
        printf("Address : %s\n", temp->address);
        printf("Branch : %s\n", temp->branch);
        temp = temp->next;
    }
}

void dispByBranch(struct Node_head* start)
{
    char branch[50];
    printf("Enter Branch : ");
    scanf("%s", branch);
    struct Node* temp = start->next;
    int c = 1;

    while (temp != NULL)
    {
        if (strcmp(temp->branch, branch) == 0)
        {
            printf("\n\nStudent %d\n", c++);
            printf("Name : %s\n", temp->name);
            printf("Roll : %d\n", temp->roll);
            printf("CGPA : %f\n", temp->cgpa);
            printf("Address : %s\n", temp->address);
            printf("Branch : %s\n", temp->branch);
        }
        temp = temp->next;
    }
}

void dispByMarks(struct Node_head* start)
{
    char branch[50];
    printf("Enter Branch : ");
    scanf("%s", branch);

    struct Node* temp = start->next;
    int c = 1;

    while (temp != NULL)
    {
        if ((strcmp(temp->branch, branch) == 0) && temp->cgpa > 7.5)
        {
            printf("\n\nStudent %d\n", c++);
            printf("Name : %s\n", temp->name);
            printf("Roll : %d\n", temp->roll);
            printf("CGPA : %f\n", temp->cgpa);
            printf("Address : %s\n", temp->address);
            printf("Branch : %s\n", temp->branch);
        }
        temp = temp->next;
    }
}

void totalNodes(struct Node_head* start)
{
    printf("Total Number of Students : %d\n\n", start->count);
}

void main()
{
    int ch;
    struct Node_head* start = NULL;

    while (1)
    {
        printf("\n\n\nMENU\n");
        printf("0. Exit\n");
        printf("1. Create Node\n");
        printf("2. Display Student Information\n");
        printf("3. Display number of nodes\n");
        printf("4. Display the students details belonging to a particular branch\n");
        printf("5. Display the students details securing > 7.5 CGPA and belonging to a given branch.\n");

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
            display(start);
            break;

        case 3:
            totalNodes(start);
            break;

        case 4:
            dispByBranch(start);
            break;

        case 5:
            dispByMarks(start);
            break;

        default:
            printf("Invalid");
        }
    }
}
