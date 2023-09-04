#include <iostream>
using namespace std;
class area
{
    float r, l, b;
    int base, h;

public:
    void disp_area(float r)
    {
        cout << "Area of the circle is: " << 3.14 * r * r << endl;
    }
    void disp_area(float l, float b)
    {
        cout << "Area of the rectangle is: " << l * b << endl;
    }
    void disp_area(int base, int h)
    {
        cout << "Area of the triangle is: " << 0.5 * base * h;
    }
    
    void display_area()
    {
        cout << "Enter the radius of the circle: \n";
        cin >> r;
        disp_area(r);

        cout << "Enter the length and breadth of the rectangle: \n";
        cin >> l >> b;
        disp_area(l, b);

        cout << "Enter the base and height of the triangle";
        cin >> base >> h;
        disp_area(base, h);
    }
};

int main()
{
    area a;
    a.display_area();
    return 0;
}