// Create a class complex which stores real and imaginary part of a complex number. Input 10 complex numbers and display them.

#include <iostream>
using namespace std;
class Complex
{
    int real[10];
    int img[10];

public:
    void input();
    void display();
};
void Complex::input()
{
    cout << "Enter 10 real no: ";
    for (int i = 0; i < 10; i++)
        cin >> real[i];

    cout << "Enter 10 img part";
    for (int i = 0; i < 10; i++)
        cin >> img[i];
}
void Complex::display()
{
    cout<<"\n-----10 Complex nos. are ----- \n";
    for (int i = 0; i < 10; i++)
        cout << real[i] << " + " << img[i] << "j" << endl;
}
int main()
{
    Complex std;
    std.input();
    std.display();
    return 0;
}















/*
#include <iostream>
using namespace std;
class Complex
{
    int real;
    int img;
public:
    void input();
    void display();
};
void Complex::input()
{
    cout << "Enter complex number's real and imaginary value : ";
    cin >> real >> img;
}
void Complex::display()
{
    cout << real << " + " << img << "j" << endl;
}
int main()
{
    Complex arr[10];
    int i;
    for (i = 0; i < 10; i++)
        arr[i].input();
    for (i = 0; i < 10; i++)
        arr[i].display();

    return 0;
}
*/