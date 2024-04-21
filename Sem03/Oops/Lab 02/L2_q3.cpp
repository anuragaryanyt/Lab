/*Modify the program ii) to store marks in 5 subjects. Calculate the total marks and
percentage of a student and display it.*/

#include <iostream>
using namespace std;
class student
{
private:
    char name[30];
    int roll, full;
    float marks[5],total;
    float percent;

public:
    void getDetails(void);
    void putDetails(void);
    void calc();
};
void student::getDetails(void)
{
    cout << "Enter the Name: ";
    cin >> name;

    cout << "Enter the roll no: ";
    cin >> roll;

    cout << "Enter the marks:";
    for (int i = 0; i < 5; i++)
        cin >> marks[i];
    cout<<"Enter the full marks:";
    cin>>total;
}

void student::putDetails(void)
{
    cout << "\n Student Info :-"
         << "\n Name: " << name << endl;
    cout << "Roll: " << roll << endl;
    cout << "Marks:";
    for (int i = 0; i < 5; i++)
        cout << marks[i] << " ";
    cout << endl;
    
}
void student::calc()
{
    int sum = 0, loop = 5;
    while (loop--)
        sum += marks[loop];
    cout << "Total marks : " << sum << endl;
    cout << "Percentage : " << (sum * 100)/total << endl;
}

int main()
{
    student std;
    std.getDetails();
    std.putDetails();
    std.calc();

    return 0;
}









/* int main()
{
    int total = 0, full;
    float marks, percent;

    cout << "Enter the marks of 1 sub--";
    cin >> marks;
    total = total + marks;
    cout << "Enter the marks of 2 sub--";
    cin >> marks;
    total = total + marks;
    cout << "Enter the marks of 3 sub--";
    cin >> marks;
    total = total + marks;
    cout << "Enter the marks of 4 sub--";
    cin >> marks;
    total = total + marks;
    cout << "Enter the marks of 5 sub--";
    cin >> marks;
    total = total + marks;

    cout << "Enter the Full marks=";
    cin >> full;
    percent = (total * 100) / full;

    cout << "\n Total marks ==" << total;
    cout << "\n Total Percentage ==" << percent;

    return 0;
}*/
