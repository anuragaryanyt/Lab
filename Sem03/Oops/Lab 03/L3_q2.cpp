// Create two classes which stores distance in feet, inches and meter, centimeter format respectively. Write a function which compares distance in object of these classes and displays the larger one.

#include <iostream>
using namespace std;

class mcm;
class fi
{
    int feet, inches;

public:
    void get()
    {
        cout << "Enter the distance in feet and inches. :";
        cin >> feet >> inches;
    }
    friend void compare(fi, mcm);
};
class mcm
{
    int me, cm;

public:
    void get()
    {
        cout << "Enter the distance in m and cm. :";
        cin >> me >> cm;
    }
    friend void compare(fi, mcm);
};

void compare(fi f, mcm m)
{
    int totalfeet = f.feet + (f.inches / 12);
    int totalm = m.me + (m.cm / 100);
    if (totalm > totalfeet)
        cout << m.me << " meters and " << m.cm << " centimeters is large";
    else
        cout << f.feet << " feets and " << f.inches << " inches is large";
}
int main()
{
    mcm m;
    fi f;
    m.get();
    f.get();
    compare(f, m);
}