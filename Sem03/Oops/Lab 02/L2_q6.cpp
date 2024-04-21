/* Create a class which stores id, name, age and basic salary of an employee.
Input data for n number of employees. Calculate the gross salary of all the
employees and display it along with all other details in a tabular form.
[Gross salary= Basic salary + DA + HRA,
DA = 80% of Basic salary
HRA=10% of Basic salary ] */

#include <iostream>
using namespace std;

class employee
{
    string name;
    int id;
    int age;
    int salary;

public:
    void input();
    void display();
};

void employee::input()
{
    cout << "Enter name : ";
    getline(cin, name);
    cout << "Enter id, age, salary :";
    cin >> id >> age >> salary;
    getchar();
}

void employee::display()
{
    cout << name << "\t" << id << "\t" << age << "\t" << salary << "\t" << salary * 0.9 << endl;
}

int main()
{
    int n, i;
    cout << "Enter no of Employee: ";
    cin >> n;
    getchar();
    employee arr[n];
    for (i = 0; i < n; i++)
        arr[i].input();
    cout << "name"<< "\t"<< "id"<< "\t"<< "age"<< "\t"<< "salary"<< "\t"<< "gross salary" << endl;
    for (i = 0; i < n; i++)
        arr[i].display();

    return 0;
}