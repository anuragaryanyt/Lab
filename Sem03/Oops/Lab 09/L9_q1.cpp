// Create a class shape. Derive three classes from it; Circle, Square and Triangle. Find area
// of each shape and display it, using virtual

#include <iostream>
using namespace std;
class shape
{
public:
    int a, b, c;
    virtual void area() {}
};

class triangle : public shape
{
public:
    void area()
    {
        cout << "Enter the base & height: ";
        cin >> a >> b;
        cout << "Area of the triangle: " << a * b * 0.5 << endl;
    }
};

class rectangle : public shape
{
    void area()
    {
        cout << "Enter the length & breadth: ";
        cin >> a >> b;
        cout << "Area of the rectangle: " << a * b << endl;
    }
};

class circle : public shape
{
    void area()
    {
        cout << "Enter the radius: ";
        cin >> a;
        cout << "Area of the circle: " << 3.14 * a * a << endl;
    }
};

int main()
{
    shape *p;
    triangle t1;
    p = &t1;
    p->area();

    circle c1;
    p = &c1;
    p->area();

    rectangle r1;
    p = &r1;
    p->area();
    return 0;
}
