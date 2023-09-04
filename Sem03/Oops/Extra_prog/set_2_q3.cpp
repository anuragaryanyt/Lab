#include <iostream>
using namespace std;
class shape
{
public:
    int a, b;
    virtual void area() = 0;
};
class circle : public shape
{
    public:
    void input()
    {
        cout << "Enter the radius: ";
        cin >> a;
    }
    void area()
    {
        cout << "Area of the circle is: " << 3.14 * a * a << endl;
    }
};
class triangle : public shape
{
    public:
    void input()
    {
        cout<<"Enter the base and height: ";
        cin>>a>>b;

    }
    void area()
    {
        cout<<"Area of the triangle is: "<<0.5*a*b<<endl;
    }
};

int main()
{
    circle c1;
    c1.input();
    c1.area();

    triangle t1;
    t1.input();
    t1.area();

    return 0;
}
