#include <iostream>
using namespace std;
class Int
{
    int a;

public:
    void input()
    {
        cout << "Enter the no: ";
        cin >> a;
        // if (-2147483647 < a < 2147483648)
        // {
        //     cout<<"It is in normal range"<<endl;
        // }
        // else
        //     exit(0);
    }
    
    void display()
    {
        cout << "output is: " << a;
    }
    Int operator+(Int x)
    {
        Int temp;
        temp.a = a + x.a;
        return temp;
    }
    Int operator-(Int x)
    {
        Int temp;
        temp.a = a - x.a;
        return temp;
    }
    Int operator*(Int x)
    {
        Int temp;
        temp.a = a * x.a;
        return temp;
    }
    Int operator/(Int x)
    {
        Int temp;
        temp.a = a / x.a;
        return temp;
    }
};
int main()
{
    Int x1, x2, x3;

    x1.input();
    x2.input();
    x3 = x1 + x2;
    x3.display();
    cout << endl;

    x3 = x1 - x2;
    x3.display();
    cout << endl;

    x3 = x1 * x2;
    x3.display();
    cout << endl;

    x3 = x1 / x2;
    x3.display();
    cout << endl;

    return 0;
}
