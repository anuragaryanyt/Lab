/* 6. Define a structure of student having data members: name, address, marks in C
language, and marks in information system. Take data for n students in an array
and find the total marks obtained by passing structure to a function. */

#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[100];
    char address[100];
    float marks_c;
    float marks_info;
};

void total(int, struct student *);
void input(int, struct student *);
void main()
{
    int n;
    printf("Enter number of students :");
    scanf("%d", &n);

    struct student *stud = (struct student *)malloc(n * sizeof(struct student));

    input(n, stud);
    total(n, stud);
    
}

void input(int n, struct student *stud)
{
    for (int i = 0; i < n; i++)
    {
        printf(" Student  %d\n", i + 1);
        printf("Enter Name : ");
        scanf("%s", &(stud + i)->name);
        printf("Enter Address : ");
        scanf("%s", &(stud + i)->address);
        printf("Enter Marks in C Language : ");
        scanf("%f", &(stud + i)->marks_c);
        printf("Enter Marks in Information System : ");
        scanf("%f", &(stud + i)->marks_info);
    }
}

void total(int n, struct student *stud)
{
    for (int i = 0; i < n; i++)
    {
        printf(" Student  %d\n", i + 1);
        printf(" Name : %s\n", (stud + i)->name);
        printf(" Address : %s\n", (stud + i)->address);
        printf(" Marks in C Language : %.2f\n", (stud + i)->marks_c);
        printf(" Marks in Information System : %.2f\n", (stud + i)->marks_info);
        printf(" Enter Total Marks : %.2f\n", (stud + i)->marks_c + (stud + i)->marks_info);
    }
}