/* Create a class which stores account number, customer name and balance. Derive two
classes from ‘Account’ class: ‘Savings’ and ‘Current’. The ‘Savings’ class stores
minimum balance. The ‘Current’ class stores the over-due amount. Include member
functions in the appropriate class for
-deposit money
-withdraw [For saving account minimum balance should be checked.]
[For current account overdue amount should be calculated.]
-display balance
Display data from each class using virtual function */

#include <iostream>
using namespace std;
class Account
{
public:
    string name;
    int cno, bal;
    Account()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Custormer no:";
        cin >> cno;

        cout << "Balance:";
        cin >> bal;
    }
    virtual void withdraw(int) = 0;
    virtual void deposit(int amt)
    {
        bal += amt;
    }
    virtual void display()
    {
        cout << "Name: " << name << "\nBalance: " << bal << endl;
    }
};

class Savings : public Account
{
public:
    const int MIN_BAL = 1000;
    void withdraw(int amt)
    {
        if (bal - amt < MIN_BAL)
        {
            cout << "Amount less than 1000!! Cannot withdraw.\n";
            return;
        }
        bal -= amt;
    }
};

class Current : public Account
{
public:
    int a1;
    Current()
    {
        cout << "Input overdue amount: ";
        cin >> a1;
    }

    void withdraw(int amt)
    {
        if (bal - amt < a1)
        {
            cout << "money Can't be withdraw.\n";
            return;
        }
        bal -= amt;
    }
};

int main()
{
    Savings s1;
    Current s2;

    s1.deposit(1000);
    s1.withdraw(500);

    s1.display();
    s2.display();
    return 0;
}
