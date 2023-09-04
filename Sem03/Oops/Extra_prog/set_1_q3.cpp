#include <iostream>
using namespace std;
class bank
{
    int n = 0, count;

public:
    void people()
    {
        cout << "Enter no of people:";
        cin >> count;
    }

    void display()
    {
        cout << "No. of people in the bank: " << count << endl;
    }

    void operator++(int)
    {
        count++;
    }

    void operator--(int)
    {
        count--;
    }
};

int main()
{
    int ch;
    bank b1;
    b1.people();
    b1.display();

    while (1)
    {
        cout << "----menu ----" << endl;
        cout << "1. Enter" << endl;
        cout << "2. Exiting" << endl;
        cout << "3. break" << endl;
        cout << "Enter the choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:

            b1++;
            cout << "No. of people after entering 1 person:" << endl;
            b1.display();
            break;
        case 2:

            b1--;
            cout << "No. of people after exiting 1 person:" << endl;
            b1.display();
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}
