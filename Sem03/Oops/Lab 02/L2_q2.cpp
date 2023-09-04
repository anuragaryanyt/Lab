/*Create a class which stores name, roll number and total marks for a student. Input the
data for a student and display it.*/

#include <iostream>
using namespace std;
class student
{
private:
    char name[30];
    int roll;
    float marks;

public:
    void getDetails(void);
    void display(void);
};

void student::getDetails(void)
{
    cout << "Enter the Name- ";
    cin >> name;

    cout << "Enter the roll no - ";
    cin >> roll;

    cout << "Enter the marks- ";
    cin >> marks;
}
void student::display(void)
{
    cout << "\n Student Info :-"
         << "\n Name- " << name << "\t Roll- " << roll << "\t Marks- " << marks;
}

int main()
{ 
    student stu;
    stu.getDetails();
    stu.display();

    return 0;
}
