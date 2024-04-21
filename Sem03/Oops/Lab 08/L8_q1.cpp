/* WAP to overload following operators for class Distance, which stores the Distance in feet
and inches. a) Binary + to
-add two objects (D3=D1+D2)
-Add an object to an integer, where the integer should be added to the
inches value ( D2=4+D1)
b) Unary -
*/

#include <iostream>
using namespace std;
class Distance
{
    int feet, inches;

public:
    void getdata()
    {
        cout << "Enter the Distance in feet & inches: ";
        cin >> feet >> inches;
    }

    void display()
    {
        cout << feet << " feet " << inches << " inches";
    }

    Distance operator+(Distance d) //d3=d1+d2
    {
        Distance temp;
        temp.feet = feet + d.feet;
        temp.inches = inches + d.inches;
        if (temp.inches > 12)
        {
            temp.feet = temp.feet + (temp.inches / 12);
            temp.inches = temp.inches % 12;
        }
        return temp;
    }
    Distance operator+(int a) //d3=4+d1
    {
        Distance temp;
        temp.feet = feet;
        temp.inches = inches + a;
        return temp;
    }

    Distance operator-() //unary -
    {
        Distance temp;
        temp.feet = -feet;
        temp.inches = -inches;
        return temp;
    }
};

int main()
{
    Distance a1, a2, a3;
    a1.getdata();
    a2.getdata();
    a3 = a1 + a2;
    a3.display();
    printf("\n");
    a3 = a3 + 4;
    a3.display();
    printf("\n");
    a3 = -a3;
    a3.display();
    printf("\n");
    return 0;
}
