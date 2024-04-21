// Write overloaded functions to find the area of scalene, isosceles and equilateral triangle
// Area of scalene triangle = √(s(s-a)(s-b)(s-c))
// Area of isosceles triangle = 1⁄2[√(a2 − b2/4) × b]
// Area of equilateral triangle= (√3/4)a2

#include <iostream>
#include <math.h>
using namespace std;
class area
{
    int a, b, c;
    int a1, b1;
    int a2;

public:
    void display_area(void);
    void disp_area(int a, int b, int c);
    void disp_area(int a2, int b2);
    void disp_area(int a2);
};
void area::display_area(void)
{
    cout << "Enter the sides of scalene triangle: ";
    cin >> a >> b >> c;
    disp_area(a, b, c);

    cout << "Enter the sides of isosceles triangle: ";
    cin >> a1 >> b1;
    disp_area(a1, b1);

    cout << "Enter the sides of equilateral triangle: ";
    cin >> a2;
    disp_area(a2);
}
void area::disp_area(int a, int b, int c)
{
    int s = (a + b + c) / 2;
    int p = s * (s - a) * (s - b) * (s - c);
    float x = pow(p,0.5);
    cout << "Area of Scalene triangle: " << x << endl;
}
void area::disp_area(int a1, int b1)
{
    float s = pow(((pow(a1 , 2 )- pow(b1 , 2) / 4) * b1),0.5);
    
    cout << "Area of isosceles triangle: " << s << endl;
}
void area::disp_area(int a2)
{
    float q = (pow(3 , 0.5) / 4) * a2;
    cout << "Area of equilateral triangle is: " << q << endl;
}

int main()
{
    area a;
    a.display_area();
    return 0;
}
