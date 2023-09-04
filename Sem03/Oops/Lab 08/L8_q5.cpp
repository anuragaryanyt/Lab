/* WAP to add two objects of Time class. Overload the operator ‘==’ to compare two objects
and display whether they are equal or not. Overload the assignment operator */

#include <iostream>
using namespace std;
class Time
{
    int hour;
    int min;

public:
    Time()
    {
        hour = 0;
        min = 0;
    }
    Time(int a, int b)
    {
        Time x;
        hour = a;
        min = b;
        while (x.min >= 60)
        {
            x.min -= 60;
            x.hour++;
        }
    }
    void display()
    {
        cout << "Time is " << hour << ":" << min << endl;
    }
    Time operator+(Time &a)
    {
        Time x;
        x.hour = a.hour + hour;
        x.min = a.min + min;
        while (x.min >= 60)
        {
            x.min -= 60;
            x.hour++;
        }
        return x;
    }
    bool operator==(Time &a)
    {
        if (a.hour == hour && a.min == min)
            return true;
        else
            return false;
    }
};
int main()
{
    Time X1(3, 40), X2(3, 40), X3;
    X3 = X1 + X2;
    if (X1 == X2)
        X3.display();
    else
        cout << "Time is not equal!!";
    return 0;
}

