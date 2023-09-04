/* WAP that reads DATA of n students and find the
 average mark of each student
 # of students above average mark in the class.
 # of students below average mark in the class.
 Sort students in ascending order of their mark.
 Display the name of the student secured highest mark.
 Display the roll number of the student secured highest mark from bottom. */

#include <iostream>
using namespace std;
class student
{
    string name[50];
    int roll[50], n;
    float avg, total, mark[50];

public:
    void getdetails();
    void calc();
    void display();
};

void student::getdetails()
{
    cout << "Enter no of students: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter roll: ";
        cin >> roll[i];

        cout << "Enter name: ";
        cin >> name[i];

        cout << "Enter mark: ";
        cin >> mark[i];
    }
}
void student::calc()
{
    total = 0;
    for (int i = 0; i < n; i++)
    {
        total = total + mark[i];
    }
    avg = total / n;
}
void student::display()
{
    cout << "\n\n";
    cout << "Roll"
         << "\tName"
         << "\tMarks" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << roll[i] << "\t" << name[i] << "\t" << mark[i] << endl;
    }
    cout << "Average: " << avg << endl;
    cout << "\n";
    cout << "----Details of students above average marks----" << endl;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] > avg)
        {
            cout << roll[i] << "\t" << name[i] << "\t" << mark[i] << endl;
        }
    }
    cout << "\n";
    cout << "----Details of students below average marks----" << endl;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] < avg)
        {
            cout << roll[i] << "\t" << name[i] << "\t" << mark[i] << endl;
        }
    }
    cout << "----Details of students sorted by marks----" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mark[i] > mark[j])
            {
                float temp = mark[i];
                mark[i] = mark[j];
                mark[j] = temp;

                string temp2 = name[i];
                name[i] = name[j];
                name[j] = temp2;

                int temp3 = roll[i];
                roll[i] = roll[j];
                roll[j] = temp3;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << roll[i] << "\t" << name[i] << "\t" << mark[i] << endl;

    cout << "\n\nStudent who scored highest marks : " << name[n - 1];
    cout << "\nStudent who scored highest marks from bottom : " << name[0];
}

int main()
{
    student stu;
    stu.getdetails();
    stu.calc();
    stu.display();
}