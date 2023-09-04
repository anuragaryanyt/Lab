// Create a class which stores account number, customer name and balance.
// Derive two classes from ‘Account’ class: ‘Savings’ and ‘Current’. The ‘Savings’
// class stores minimum balance. The ‘Current’ class stores the over-due amount.
// Include member functions in the appropriate class for
// -deposit money
// -withdraw [For saving account minimum balance should be checked.]
// [For current account overdue amount should be calculated.]
// -display balance

#include <iostream>
using namespace std;
#define min_bal 1000
#define MAX_OVERDRAFT 5000

class Account
{
public:
    int ac_no;
    char name[20];
    float balance = 0;
    void depositAmount()
    {
        float deposit;
        cout << "\nEnter amount to be deposited: ";
        cin >> deposit;
        balance += deposit;
        cout << "Amount of Rs." << deposit << " has been successfully deposited " << endl;
        
    }
    void showInfo()
    {
        cout << "\nAccount Number: " << ac_no;
        cout << "\nCustome Name: " << name;
        cout << "\nCurrent Balance: Rs." << balance << endl;
    }
};

class Savings : public Account
{
public:
    void getInfo()
    {
        cout << "\nEnter name of customer: ";
        cin >> name;
        cout << "Enter customer's account number: ";
        cin >> ac_no;
    }

    void withdrawAmount()
    {
        float withdraw;
        cout << "\nEnter amount to be withdrawn: ";
        cin >> withdraw;
        if (balance - withdraw < min_bal)
        {
            cout << "Withdrawal not possible as amount in balance would fall behind the mimnimum balance amount" << endl;
            return;
        }
        balance -= withdraw;
        cout << "Amount of Rs." << withdraw << " has been withdrawn successfully " << endl;
    }

    void operations()
    {
        int ch = 1;
        while (ch)
        {
            cout << "\nChoose from the following operations that you want to perform on your Savings Account";
            cout << "\n1-Deposit Amount\n2-Withdraw Amount\n3-Display Information\n0-Exit";
            cout << "\nEnter choice: ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                depositAmount();
                break;
            case 2:
                withdrawAmount();
                break;
            case 3:
                showInfo();
                break;
            case 0:
                cout << "Exited program";
                break;
            default:
                cout << "Invalid option";
                break;
            }
        }
    }
};

class Current : public Account
{
public:
    float cur_od = 0;

    void getInfo()
    {
        cout << "\nEnter name of customer: ";
        cin >> name;
        cout << "Enter customer's account number: ";
        cin >> ac_no;
    }

    void showInfo()
    {
        Account ::showInfo();
        if (cur_od)
            cout << "Overdraft amount: Rs." << cur_od << endl;
    }

    void withdrawAmount()
    {
        if (cur_od >= MAX_OVERDRAFT)
        {
            cout << "\nOverdraft has reached maximum amount permissible. Withdrawak nor possible." << endl;
            return;
        }
        float withdraw;
        cout << "\nEnter amount to be withdrawn: ";
        cin >> withdraw;
        if (withdraw > balance)
        {
            cur_od += withdraw - balance;
            balance = 0;
            cout << "Amount of Rs." << cur_od << " is now pending in overdraft " << endl;
            return;
        }
        balance -= withdraw;
        cout << "Amount of Rs." << withdraw << " has been withdrawn successfully " << endl;
    }

    void operations()
    {
        int ch = 1;
        while (ch)
        {
            cout << "\nChoose from the following operations that you want to perform on your Current Account";
            cout << "\n1-Deposit Amount\n2-Withdraw Amount\n3-Display Information\n0-Exit";
            cout << "\nEnter choice: ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                depositAmount();
                break;
            case 2:
                withdrawAmount();
                break;
            case 3:
                showInfo();
                break;
            case 0:
                cout << "Exited program";
                break;
            default:
                cout << "Invalid option";
                break;
            }
        }
    }
};

int main()
{
    int c = 0;
    cout << "Choose account type (1-Savings, 2-Current): ";
    cin >> c;
    if (c == 1)
    {
        Savings obS;
        obS.getInfo();
        obS.operations();
    }
    else if (c == 2)
    {
        Current obC;
        obC.getInfo();
        obC.operations();
    }
    else
        cout << "Invalid input";
    return 0;
}
