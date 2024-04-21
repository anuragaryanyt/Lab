// Extend the program ii. to include a class sports, which stores the marks
// in sports activity. Derive the result class from the classes ‘test’ and ‘sports’.
// Calculate the total marks and percentage of a student.

#include <iostream>
using namespace std;

class Student
{
public:
    char name[20];
    int roll, age;

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
public:
    int marks[5];

    void getDetails()
    {
        Student ::getDetails();
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks in subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void displayDetails()
    {
        Student ::displayDetails();
        cout << "\n\nMarks obtained:";
        for (int i = 0; i < 5; i++)
            cout << "\nMarks in subject " << i + 1 << ": " << marks[i];
    }
};

class Sports : public Test
{
public:
    int sports_marks;
    int total_marks = 0;
    float total_percentage;

    void getDetails(){
        Test::getDetails();
        cout << "Enter marks obtained in sports activities: ";
        cin >> sports_marks;
    }

    void showMarks()
    {
        for (int i = 0; i < 5; i++)
            total_marks += marks[i];
        total_marks+=sports_marks;
        total_percentage = ((float)total_marks / 600) * 100;
        cout << "Total marks:" << total_marks << "\nTotal percentage: " << total_percentage << "%" << endl;
    }
};

int main()
{
    Sports ob;
    ob.getDetails();
    ob.showMarks();
    return 0;
}