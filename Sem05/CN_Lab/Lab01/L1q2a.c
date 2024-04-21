/* Write a C program to assign values to each member of the following structure. Pass the  populated structure to a function Using call-by-value and another function using call by-address and print the value of each member of the structure.
struct student_info{
int roll_no;
char name[50];
float CGPA;
struct dob age;
};
*/

#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[20];
    float cgpa;
    int age;
};

void callbyvalue(struct student s)
{

    printf("Enter the student Roll no:\n");
    scanf("%d", &s.roll);
    printf("Enter the student Name:\n");
    scanf("%s", s.name);
    printf("Enter the student age:\n");
    scanf("%d", &s.age);
    printf("Enter the student cgpa:\n");
    scanf("%f", &s.cgpa);
}
void showbyvalue(struct student s)
{
    printf("----SHOW BY VALUE----");
    printf("Name: %s\n", s.name);
    printf("Roll: %d\n", s.roll);
    printf("CGPA: %.2f\n", s.cgpa);
    printf("Age: %d\n", s.age);

}

void callbyaddress(struct student *s)
{
    printf("\n Enter the student Roll no:\n");
    scanf("%d", &s->roll);
    printf("Enter the student Name:\n");
    scanf("%s", s->name);
    printf("Enter the student age:\n");
    scanf("%d", &s->age);
    printf("Enter the student cgpa:\n");
    scanf("%f", &s->cgpa);
}
void showbyaddress(struct student *s)
{
    printf("----SHOW BY ADDRESS----");
    printf("Name: %s\n", s->name);
    printf("Roll: %d\n", s->roll);
    printf("CGPA: %.2f\n", s->cgpa);
    printf("Age: %d\n", s->age);
}

int main()
{
    struct student s1,s2;

    callbyvalue(s1);
    showbyvalue(s1);
    callbyaddress(&s1);
    showbyaddress(&s2);

    return 0;
}
