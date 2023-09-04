//WAP to input name, roll number and marks in 5 subjects for a student and display it.


#include <stdio.h>
struct student
{
    char name[25];
    int roll, marks[5];
};

int main()
{
    struct student stud;
    printf("enter the name:");
    scanf("%[^\n]s", &stud.name);
    
    printf("\n enter the roll no:");
    scanf("%d", &stud.roll);

    printf("\n enter the marks:");
    for (int i = 0; i <= 4; i++)
    {
        scanf("%d", &stud.marks[i]);
    }
    printf("Displaying All info:");
    printf("\n Name- %s", stud.name);
    printf("\n Roll no- %d", stud.roll);
    printf("\n Marks :\n");
    for (int i = 0; i < 5; i++)
        printf("%d\n", stud.marks[i]);

    return 0;
}