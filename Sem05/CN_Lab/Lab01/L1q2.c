#include <stdio.h>
#include <string.h>
struct dob
{
    int day;
    int month;
    int year;
};
struct student_info
{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};
void call_by_Value(struct student_info student)
{
    printf("Roll No: %d\n", student.roll_no);
    printf("Name   : %s\n", student.name);
    printf("CGPA   : %.2f\n", student.CGPA);
    printf("Age    : %d/%d/%d\n", student.age.day, student.age.month, student.age.year);
}

void call_by_Address(struct student_info *student)
{
    printf("Roll No: %d\n", student->roll_no);
    printf("Name   : %s\n", student->name);
    printf("CGPA   : %.2f\n", student->CGPA);
    printf("Age    : %d/%d/%d\n", student->age.day, student->age.month, student->age.year);
}

int main()
{
    struct student_info student1;
    struct student_info student2;

    // for student 1
    student1.roll_no = 100;
    strcpy(student1.name, "Raj");
    student1.CGPA = 8.8;
    student1.age.day = 20;
    student1.age.month = 5;
    student1.age.year = 2003;

    // for student 2
    student2.roll_no = 101;
    strcpy(student2.name, "Aryan");
    student2.CGPA = 7.9;
    student2.age.day = 15;
    student2.age.month = 8;
    student2.age.year = 2002;

    printf("Student 1 Info (Call-by-Value):\n");
    call_by_Value(student1);
    printf("\nStudent 2 Info (Call-by-Address):\n");
    call_by_Address(&student2);
    return 0;
}