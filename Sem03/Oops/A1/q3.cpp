/* WAP using classes, objects to represent the class student with following specification
Private data members: Roll no, Name, 6 subjects marks and Total marks Public members function to:
1. Accept values from input device 2. to calculate
the grand total and 3. display grade with other details. */

#include <iostream>
using namespace std;
class student
{
    int roll, marks[10], total, grade;
    string name;

public:
    void getdetails(void);
    void display(void);
    void calc(void);
};
void student::getdetails(void)
{
    cout << "Name: ";
    cin >> name;

    cout << "Roll no: ";
    cin >> roll;

    cout << "Enter the marks of 6 subjects: ";
    for (int i = 0; i < 6; i++)
    {
        cin >> marks[i];
    }
}
void student::display(void)
{

    cout << "\n\nName: " << name << "\tRollno: " << roll << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << "Marks of subject " << i + 1 << ": " << marks[i] << endl;
    }
}
void student::calc(void)
{
    total = 0;
    for (int i = 0; i < 6; i++)
    {
        total = total + marks[i];
    }
    cout << "\nTotal marks: " << total << endl;
    if (total > 90)
        cout << "O grade";
    else if (total > 80)
        cout << "E grade";
    else if (total > 70)
        cout << "A grade";
    else if (total > 60)
        cout << "B grade";
    else if (total > 50)
        cout << "C grade";
    else
        cout << "F grade";
}

int main()
{
    student stu;
    stu.getdetails();
    stu.display();
    stu.calc();
    return 0;
}
