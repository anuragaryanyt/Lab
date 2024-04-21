// Create a class which stores time in hh:mm format. Include all the constructors. The parameterized constructor should initialize the minute value to zero, if it is not provided

#include <iostream>
using namespace std;
class time
{
    int h, m;

public:
    time() // default const.
    {
        cout << "Enter the Hour: ";
        cin >> h;
        cout << "Enter the min. ";
        cin >> m;
    }
    time(int a, int b)
    {
        h = a;
        m = b;
    }
    time(int a) // when min value->0
    {
        h = a;
        m = 0;
    }
    
    void display()
    {
        cout << "Time is: " << h << ":" << m << endl;
    }
};
int main()
{
    time t1;
    t1.display();

    time t2(5, 45);
    t2.display();

    time t3(4);
    t3.display();

    time t4(t1); // copy t1
    t4.display();
}
