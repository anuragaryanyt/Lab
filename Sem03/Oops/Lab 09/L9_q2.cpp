/* Create a class which stores employee name,id and salary Derive two classes from ‘Employee’ class: ‘Regular’ and ‘Part-Time’. The ‘Regular’ class stores DA, HRA and basic salary. The ‘Part-Time’ class stores the number of hours and pay per hour. Calculate the salary of a regular employee and a par-time employee, using virtual function */

#include <iostream>
using namespace std;
class Employee
{
public:
    char name[20];
    int id;
    float sal;
    virtual void salary() {}
};

class Regular : public Employee
{
public:
    float DA, HRA;
    int basic_sal;

    void salary()
    {
        cout << "\nEnter name of regular employee: ";
        cin >> name;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter basic sal: ";
        cin >> basic_sal;
        DA = 0.8 * (float)basic_sal;
        HRA = 0.1 * (float)basic_sal;
        sal = basic_sal + DA + HRA;

        cout << "\nName: " << name << "\nID: " << id << "\nTotal sal: " << sal << endl;
    }
};

class Part_Time : public Employee
{
public:
    float pay_hr;
    int hr;

    void salary()
    {
        cout << "\nEnter name of part-time employee: ";
        cin >> name;
        cout << "Enter id: ";
        cin >> id;
        cout << "\nEnter pay per hour: ";
        cin >> pay_hr;
        cout << "Enter number of hr put in: ";
        cin >> hr;
        sal = pay_hr * hr;

        cout << "\nName: " << name << "\nID: " << id << "\nTotal sal: " << sal << endl;
    }
};

int main()
{
    Employee *p1;

    Regular r1;
    p1 = &r1;
    p1->salary();

    Part_Time r2;
    p1 = &r2;
    p1->salary();

    return 0;
}
