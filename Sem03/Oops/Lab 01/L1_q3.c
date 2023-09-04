/*WAP to enter id, name, age and basic salary of n number of employees.
Calculate the gross salary of all the employees and display it along with all other
details in a tabular form, using pointer to structure.
[ Gross salary= Basic salary + DA + HRA,
DA = 80% of Basic salary
HRA=10% of Basic salary ] */


#include <stdio.h>
struct employee
{
    char name[100];
    int id;
    float basicSal, grossSalary;
};

int main()
{
    int n;
    printf("Enter the number of Employees: ");
    scanf("%d", &n);
    struct employee e[n];

    for (int i = 0; i < n; i++)
    {
        printf("employee %d:- \n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]s", e[i].name);

        printf("Id: ");
        scanf("%d", &e[i].id);

        printf("Salary: ");
        scanf("%f", &e[i].basicSal);

        e[i].grossSalary = e[i].basicSal + (0.8 * e[i].basicSal) + (0.1 * e[i].basicSal);
    }
    printf(" Name\t  ID\t  B. Salary\t  G. Salary\t \n");
    for (int i = 0; i < n; i++)
        printf(" %s\t  %d\t  %.2f\t  %.2f\t \n", e[i].name, e[i].id, e[i].basicSal, e[i].grossSalary);
    return 0;
}