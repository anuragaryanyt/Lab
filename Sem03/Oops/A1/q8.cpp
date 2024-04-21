// write a overloaded functions to find the perimeter of circle, rectangle and triangle.
#include <iostream>
using namespace std;
class perimeter
{
    int l, b, s;
    float r;

public:
    void display_perimeter(void);
    void disp_perimeter(float r);
    void disp_perimeter(int l, int b);
    void disp_perimeter(int s);
};
void perimeter::display_perimeter(void)
{
    cout << "Enter the radius of the circle: ";
    cin >> r;
    disp_perimeter(r);

    cout << "Enter the length & breadth of the rectangle: ";
    cin >> l >> b;
    disp_perimeter(l, b);

    cout << "Enter the side of the triangle: ";
    cin >> s;
    disp_perimeter(s);
}
void perimeter::disp_perimeter(float r)
{
    cout << "Perimeter of the circle is: " << 2 * 3.14 * r << endl;
}
void perimeter::disp_perimeter(int l, int b)
{
    cout << "Perimeter of the retangle is: " << 2 * (l + b) << endl;
}
void perimeter::disp_perimeter(int s)
{
    cout << "Perimeter of the triangle is: " << 3 * s << endl;
}
int main()
{
    perimeter p;
    p.display_perimeter();
    return 0;
}
