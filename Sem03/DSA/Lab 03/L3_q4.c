// Q4. Create a structure named student that has name, roll and mark as members. Assume appropriate types and size of member. Write a program using structure to read and display the data entered by the user by passing structure to a function.

#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[100];
    int roll;
    float mark;
};

void read(struct student *);
void disp(struct student *);

void main()
{
    struct student *stud = (struct student *)malloc(sizeof(struct student));
    read(stud);
    disp(stud);
}

void read(struct student *stud)
{
    printf("Enter name : ");
    scanf("%s", &stud->name);
    printf("Enter Roll : ");
    scanf("%d", &stud->roll);
    printf("Enter Mark : ");
    scanf("%f", &stud->mark);
}
void disp(struct student *stud)
{
    printf("\n\nAll info:--");
    printf("\n Name : %s\n", stud->name);
    printf("Roll : %d\n", stud->roll);
    printf("Mark : %.2f\n", stud->mark);
}
