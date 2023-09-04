// WAP to demonstrate the order of call of constructors and destructors in case of multilevel inheritance.

#include<iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "Class A Constructor\n";
    }
    ~A()
    {
        cout << "Class A Destructor\n";
    }
};

class B :public A
{
public:
    B()
    {
        cout << "Class B Constructor\n";
    }
    ~B()
    {
        cout << "Class B Destructor\n";
    }
};

class C : public B
{
public:
    C()
    {
        cout << "Class C Constructor\n";
    }
    ~C()
    {
        cout << "Class C Destructor\n";
    }
};

int main()
{
    C c1;
}
