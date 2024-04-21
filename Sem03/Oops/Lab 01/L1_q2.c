/* WAP to input name, roll number and marks in 5 subjects for n number
of students. Write functions to:-
a. Find total marks and percentage of all n students.
b. Display details of a student with a given roll number.
c. Display the details for all the students having percentage in a given range. */


#include <stdio.h>
#define SUBJECT_COUNT 5
struct Student
{
    char name[50];
    int roll;
    float marks[SUBJECT_COUNT];
};

void input(struct Student *s)
{
    // Input details
    printf("\nEnter name: ");
    scanf(" %[^\n]s", s->name);

    printf("Enter roll number: ");
    scanf("%d", &s->roll);

    printf("Enter marks for 5 subjects: ");
    for (int i = 0; i < SUBJECT_COUNT; i++)
        scanf("%f", &s->marks[i]);
}

void display(struct Student s)
{
    // Total marks
    float total = 0;
    // Output basic details
    printf("\t -Details- \n");
    // Output Name
    printf("Name: %s\n", s.name);
    printf("Roll number: %d\n", s.roll);

    // Calculate total and percentage
    for (int i = 0; i < SUBJECT_COUNT; i++)
        total += s.marks[i];

    printf("Total Marks: %.2f\n", total);

    float percentage = total / SUBJECT_COUNT;
    printf("Percentage: %.2f\n", percentage);
}

// b. find roll index
int findRollIndex(int n, struct Student s[n], int roll)
{
    // Loop it and search
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == roll)
            return i;
    }
    // If nothing is found
    return -1;
}

// c. display ranges within percentage range
void displayInRange(int n, struct Student s[n], float start, float end)
{
    // Loop and search
    for (int i = 0; i < n; i++)
    {
        // Calculate percentage
        float percentage = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++)
            percentage += s[i].marks[j] / SUBJECT_COUNT;

        // If it's within the range, display it
        if (percentage >= start && percentage <= end)
            display(s[i]);
    }
}

// d. Sort in asc order of marks
void sortInAscOrder(int n, struct Student s[n])
{
    for (int i = 0; i < n - 1; i++)
    {
        // Total of current student
        float total1 = 0;
        for (int k = 0; k < SUBJECT_COUNT; k++)
            total1 += s[i].marks[k];

        // Loop and compare
        for (int j = i + 1; j < n; j++)
        {
            // Total of the other student
            float total2 = 0;
            for (int k = 0; k < SUBJECT_COUNT; k++)
                total2 += s[j].marks[k];

            // Compare
            if (total2 > total1)
            {
                struct Student temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
        }
    }
}

int main()
{
    // No. of students
    int n;

    // Input
    printf("Enter no. of students: ");
    scanf("%d", &n);

    // Make a student struct
    struct Student s[n];

    for (int i = 0; i < n; i++)
        input(&s[i]);

    // a. Output for all students
    for (int i = 0; i < n; i++)
        display(s[i]);

    // b. Find details of a given roll number
    int in;
    printf("\n\n\nEnter roll: ");
    scanf("%d", &in);
    int res = findRollIndex(n, s, in);
    if (res == -1)
    {
        printf("Invalid roll; No student found. \n");
    }
    else
        display(s[res]);

    // c. Display in percentage range
    float start, end;
    printf("\n\n\nEnter starting and ending percentage range: ");
    scanf("%f %f", &start, &end);
    displayInRange(n, s, start, end);

    // d. Sort array
    printf("\n\n\nDetails after ordering according to marks: \n");
    sortInAscOrder(n, s);
    // Display
    for (int i = 0; i < n; i++)
        display(s[i]);

    // The end!
    return 0;
}