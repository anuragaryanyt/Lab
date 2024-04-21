/* WAP using class “Employee” having data members: name, employee No, dept and
salary. Demonstrate the use of inline functions . */

#include <iostream>
using namespace std;
class employee
{
    string name, dept;
    int eno, sal;

public:
    void getdetails();
    void display();
};
inline void employee::getdetails()
{
    cout << "Enter the name of the employee: ";
    cin >> name;
    cout << "Enter the eno of the employee: ";
    cin >> eno;
    cout << "Enter the department of the employee: ";
    cin >> dept;
    cout << "Enter the salary of the employee: ";
    cin >> sal;
}
inline void employee::display()
{
    cout << "Name: " << name << "\t Eno: " << eno << "\t Dept: " << dept << "\t salary: " << sal << endl;
}

int main()
{
    employee e;
    e.getdetails();
    e.display();
    return 0;
}
