/* WAP to demonstrate use of pure virtual function and abstract base cla */

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void abcd() = 0;
};

class Derive : public Base
{
public:
    void abcd()
    {
        cout << "funnction has been called";
    }
};

int main()
{
    Derive d1;
    d1.abcd();
}

