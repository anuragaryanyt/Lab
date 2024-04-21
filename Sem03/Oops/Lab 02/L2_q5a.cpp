/* Create a class distance which stores a distance in feet and inches. Input 2
distance values in objects, add them, store the resultant distance in and object
and display it.
*/

#include <iostream>
using namespace std;

class Distance
{
    int feet;
    int inches;

public:
    void input();
    void sum(Distance a, Distance b);
    void display();
};

void Distance::input()
{
    cout << "Enter distance in Feet and Inches : ";
    cin >> feet >> inches;
}

void Distance::sum(Distance a, Distance b)
{
    feet = a.feet + b.feet;
    inches = a.inches + b.inches;
    while (inches >= 12)
    {
        inches = inches - 12;
        feet++;
    }
}

void Distance::display()
{
    cout << "Distance = " << feet << " feet " << inches << " inches" << endl;
}

int main()
{
    Distance a, b, c;
    a.input();
    b.input();
    c.sum(a, b);
    c.display();

    return 0;
}