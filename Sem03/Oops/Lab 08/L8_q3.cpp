/* Create a class which a Complex number. Add two objects and display the resultant object. Overload the ++ (post and pre) operator for the c */

#include <iostream>
using namespace std;
class Complex
{
    int real, img;

public:
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }
    Complex(){};
    void display()
    {
        cout << "Complex no is: " << real << "+" << img << "i" << endl;
    }

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    // prefix for incrementing real & postfix for incrementing img
    void operator++()
    {
        real++;
    }
    void operator++(int)
    {
        ++img;
    }
};

int main()
{
    Complex c1(5, 6);
    Complex c2(6, 7);
    Complex c3;
    c3 = c1 + c2;
    c3.display();
    printf("\nComplex no after increament is:\n");
    c3++;
    ++c3;
    c3.display();
    return 0;
}
