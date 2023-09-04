/* WAP to throw and handle ‘division by zero’ exception */

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    float d;
    cout << "Enter the value of x : ";
    cin >> x;
    cout << "Enter the value of y : ";
    cin >> y;

    try
    {
        if (x != 0)
        {
            d = y / x;
            cout << "Result is:" << d;
        }
        else
        {
            throw y;
        }
    }
    catch (int i)
    {
        cout << "Answer is infinite:" << i;
    }
}
