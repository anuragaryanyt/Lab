// WAP to demonstrate the order of call of constructors and destructors in case of virtual base class 

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

class B :public virtual A
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

class C : public virtual A
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

class D : public B, public C
{
public:
    D()
    {
        cout << "Class D Constructor\n";
    }
    ~D()
    {
        cout << "Class D Destructor\n";
    }
};

int main()
{
    D d1;
}
