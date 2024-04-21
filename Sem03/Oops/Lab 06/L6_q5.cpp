// Create a class ‘shape’. Derive three classes from it: Circle, Triangle and
// Rectangle. Include the relevant data members and functions in all the classes.
// Find the area of each shape and display it.

#include <iostream>
using namespace std;
#define PI 3.14

class Shape
{
public:
    int a,b;
};

class Circle : public Shape
{
public:
    void getLength()
    {
        cout << "\nEnter radius of circle: ";
        cin >> a;
    }
    void printArea()
    {
        cout << "Area of circle is: " << (float)(a * a) * PI << endl;
    }
};

class Triangle : public Shape
{
public:
    void getLength()
    {
        cout << "\nEnter base and height of triangle: ";
        cin >> a >> b;
    }
    void printArea()
    {
        cout << "Area of triangle is: " << (float)(a * b) * 0.5 << endl;
    }
};

class Rectangle : public Shape
{
public:
    void getLength()
    {
        cout << "\nEnter length and breadth of rectangle: ";
        cin >> a >> b;
    }
    void printArea()
    {
        cout << "Area of rectangle is: " << (float)(a * b) << endl;
    }
};

int main()
{
    Circle ob1;
    ob1.getLength();
    ob1.printArea();

    Triangle ob2;
    ob2.getLength();
    ob2.printArea();

    Rectangle ob3;
    ob3.getLength();
    ob3.printArea();
    return 0;
}
