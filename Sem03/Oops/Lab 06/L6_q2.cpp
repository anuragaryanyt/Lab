// Create a class student which stores name, roll number and age of a
// student. Derive a class test from student class, which stores marks in 5 subjects.
// Input and display the details of a student.

#include <iostream>
using namespace std;
class Student
{
    char name[20];
    int roll, age;

public:
    void getDetails()
    {
        cout << "Enter student's name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter student's age: ";
        cin >> age;
    }
    void displayDetails()
    {
        cout << "\nStudent Details:";
        cout << "\nName: " << name << "\nRoll number: " << roll << "\nAge: " << age;
    }
};

class Test : public Student
{
    int marks[5];

public:
    void getDetails()
    {
        Student::getDetails();
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks in subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void displayDetails()
    {
        Student::displayDetails();
        cout << "\n\nMarks obtained:";
        for (int i = 0; i < 5; i++)
            cout << "\nMarks in subject " << i + 1 << ": " << marks[i];
    }
};

int main()
{
    Test ob;
    ob.getDetails();
    ob.displayDetails();
    return 0;
}
