/* Q5.WAP to store n employee’s data such as employee name, gender, designation, department, basic
pay. Calculate the gross pay of each employees as follows: Gross pay = basic pay + HR + DA HR=25% of
basic and DA=75% of basic by passing structure to a function. */

#include <stdio.h>
struct employee
{
    char name[10];
    char gender[10];
    char designation[10];
    char department[10];
    int basicpay;
};

float grosspay(struct employee e)
{
    float HRA = 0, DA = 0, gross = 0;
    HRA = 0.25 * (e.basicpay);
    DA = 0.75 * (e.basicpay);
    gross = HRA + DA + e.basicpay;
    return gross;
}

int main()
{
    int n;
    printf("Enter the number of employees = ");
    scanf("%d", &n);
    struct employee s[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter employee name : ");
        scanf("%s", s[i].name);
        printf("Enter employee gender : ");
        scanf("%s", s[i].gender);
        printf("Enter employee designation : ");
        scanf("%s", s[i].designation);
        printf("Enter employee department : ");
        scanf("%s", s[i].department);
        printf("Enter employee basicpay : ");
        scanf("%d", &s[i].basicpay);
    }
    
    for (int i = 0; i < n; i++)
    {
        float gross = grosspay(s[i]);
        printf("\nNAME: %s\tGENDER: %s\tDESIGNATION: %s\tDEPARTMENT: %s\tBASICPAY: %d\tGROSS: %.2f\n", s[i].name, s[i].gender, s[i].designation, s[i].department, s[i].basicpay, gross);
        gross = 0;
    }
    return 0;
}
