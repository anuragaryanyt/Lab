// WAP to demonstrate the order of call of constructors and destructors for a class

#include <iostream>
using namespace std;
class count
{
    static int c;

public:
    count()
    {
        c = c + 1;
        cout << c << " constructor invoked" << endl;
    }

    ~count()
    {
        cout << c << " deconstructor invoked" << endl;
        c--;
    }
};
int count::c;

int main()
{
    count c1, c2, c3;
    {
        count c8,c9;
    }
    count c4;
}
