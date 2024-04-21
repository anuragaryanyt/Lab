// WAP to count number of objects created from a class using concept of static data members and static member

#include <iostream>
using namespace std;
class count
{
    static int c;

public:
    count()
    {
        // c = c + 1;
        ++c;
    }
    static void display()
    {
        cout << c << " object created" << endl;
    }
};
int count::c;

int main()
{
    count c1, c2, c3, c4,c5, c6, c7, c8;
    count::display();
}
