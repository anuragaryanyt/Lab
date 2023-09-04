// Create a class which stores employee name,id and salary Derive two
// classes from ‘Employee’ class: ‘Regular’ and ‘Part-Time’. The ‘Regular’ class
// stores DA, HRA and basic salary. The ‘Part-Time’ class stores the number
// of hour and pay per hour. Calculate the salary of a regular employee and a
// par-time employee.

#include <iostream>
using namespace std;
class Employee
{
public:
    char name[20];
    int id;
    float salary;
};

class Regular : public Employee
{
public:
    float DA, HRA;
    int basic_sal;

    void getInfo()
    {
        cout << "\nEnter name of regular employee: ";
        cin >> name;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter basic salary: ";
        cin >> basic_sal;
        DA = 0.8 * (float)basic_sal;
        HRA = 0.1 * (float)basic_sal;
        salary = basic_sal + DA + HRA;
    }

    void printInfo()
    {
        cout << "\nName: " << name << "\nID: " << id << "\nTotal salary: " << salary << endl;
    }
};

class Part_Time : public Employee
{
public:
    float pay_hr;
    int hr;

    void getInfo()
    {
        cout << "\nEnter name of part-time employee: ";
        cin >> name;
        cout << "Enter id: ";
        cin >> id;
        cout << "\nEnter pay per hour: ";
        cin >> pay_hr;
        cout << "Enter number of hr put in: ";
        cin >> hr;
        salary = pay_hr * hr;
    }

    void printInfo()
    {
        cout << "\nName: " << name << "\nID: " << id << "\nTotal salary: " << salary << endl;
    }
};

int main()
{
    Regular ob1;
    ob1.getInfo();
    ob1.printInfo();

    Part_Time ob2;
    ob2.getInfo();
    ob2.printInfo();
    return 0;
}
