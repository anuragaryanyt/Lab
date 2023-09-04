/* Rewrite program ii. using class template */

#include <iostream>
using namespace std;
template <class t1, class t2>
class xyz
{
    public:
    void display(t1 x, t2 y)
    {
        cout << "1st no is:" << x << " "
             << "2nd no is:" << y << endl;
    }
};
int main()
{
    xyz<int,float> ob;
    int a = 2321;
    float b = 45.56;
    ob.display(a, b);
}