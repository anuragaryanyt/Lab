// Rewrite the assignment vii. From Inheritance including the parameterized constructors in all the classes

#include <iostream>
using namespace std;
class A
{
public:
    A(int p = 0)
    {
        cout << "Base Class 1 Constructor\n";
    }
    ~A()
    {
        cout << "Base Class 1 Destructor\n";
    }
};

class B
{
public:
    B(int p = 0)
    {
        cout << "Base Class 2 Constructor\n";
    }
    ~B()
    {
        cout << "Base Class 2 Destructor\n";
    }
};

class C : public A, public B
{
public:
    C(int p = 0) : A(p), B(p)
    {
        cout << "Derived Class Constructor\n";
    }
    ~C()
    {
        cout << "Derived Class Destructor\n";
    }
};

int main()
{
    C c1;
}
