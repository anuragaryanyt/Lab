/* WAP to display data of two different types using function template with multiple arguments. */

#include <iostream>
using namespace std;
template <class t1, class t2>
void display(t1 x, t2 y)
{
    cout << "1st no is:" << x << " "
         << "2nd no is:" << y << endl;
}
int main()
{
    int a = 2321;
    float b = 45.56;
    display(a, b);
}
