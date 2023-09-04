// Create a class complex which stores real and imaginary part of a complex number. Include all types of constructors and destructor. The destructor should display a message about the destructor being invoked. Create objects using different constructors and display them.

#include <iostream>
using namespace std;
class complex
{
    int real, img;

public:
    complex() // default const.
    {
        cout << "Enter the real no.: ";
        cin >> real;
        cout << "Enter the imaginary no.: ";
        cin >> img;
    }

    complex(int a, int b) // parameterized const.
    {
        real = a;
        img = b;
    }

    complex(complex &p) // copy const
    {
        real = p.real;
        img = p.img;
    }
    ~complex()
    {
        cout << "Deconstructor invoked!" << endl;
    }

    void display()
    {
        cout << "Complex no is: " << real << "+" << img << "i" << endl;
    }
};
int main()
{
    complex c1;
    c1.display();
    complex c2;
    c2.display();

    // complex c2(4, 5);
    // c2.display();

    complex c3(c2); // copy const.
    c3.display();
}
