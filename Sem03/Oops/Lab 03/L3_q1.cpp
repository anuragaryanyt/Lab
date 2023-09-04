// WAP to swap private data member of two classes. [The classes have no relation with each other].

#include <iostream>
using namespace std;
class mno;
class raj
{
private:
    int a;

public:
    void get(int n)
    {
        a = n;
    }
    void display()
    {
        cout << "a=" << a << "\t";
    }
    friend void swap(raj &, mno &);
};

class mno
{
private:
    int b;

public:
    void get(int n)
    {
        b = n;
    }
    void display()
    {
        cout << "b=" << b << "\t";
    }
    friend void swap(raj &, mno &);
};
void swap(raj &a1, mno &x1)
{
    int temp = a1.a;
    a1.a = x1.b;
    x1.b = temp;
}
int main()
{
    raj a1;
    mno x1;

    a1.get(13);
    x1.get(54);

    printf("before swapping of the nos. : \n");
    a1.display();
    x1.display();

    swap(a1, x1);
    printf("\n After swapping nos. : \n");
    a1.display();
    x1.display();
}
