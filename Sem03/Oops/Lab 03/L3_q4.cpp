//Create a class which stores name, roll number and total marks for a student. Input data for n students. Find the average marks scored by n students, store it as a data member of the class and display it using a function which may be called without object.

#include <iostream>
using namespace std;
class students
{
    string name;
    int roll;
    int totmarks;
    static int avgMarks;

public:
    void getdata()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll: ";
        cin >> roll;
        cout << "Enter Total Marks: ";
        cin >> totmarks;
    }
    static void display(students obj[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            avgMarks = avgMarks + obj[i].totmarks;
        }
        cout << "\nAverage marks of the students : " << (avgMarks / n);
    }
};
int students::avgMarks = 0;
int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    students ob[n];
    for (int i = 0; i < n; i++)
    {
        ob[i].getdata();
    }
    cout << "\n";
    students::display(ob, n);

    return 0;
}
