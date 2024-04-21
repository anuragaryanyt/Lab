#include <iostream>
using namespace std;
class Bank_Acc
{
private:
    long Account_No;
    string name;
    int balance;

public:
    void get_info()
    {
        cout << "Enter account number : ";
        cin >> Account_No;
        cout << "Enter name of member : ";
        getchar();
        getline(cin, name);
        cout << "Enter balance in account : ";
        cin >> balance;
    }
    void show_info()
    {
        cout << "Account number : " << Account_No << endl;
        cout << "Name of Member : " << name << endl;
        cout << "Balance : " << balance << endl;
    }
    void deposit()
    {
        cout << "Enter amount to deposit : ";
        int amount;
        cin >> amount;
        if (amount > 300000)
            cout << "Daily limit of deposition is 3 lakh " << endl;
        else
            balance += amount;
    }
    void withdraw()
    {
        cout << "Enter amount to withdraw ";
        int amount;
        cin >> amount;
        if (balance < 500)
            cout << "Cannot withdraw money  " << endl;
        else if (balance < amount)
            cout << "Not available " << endl;
        else
            balance -= amount;
    }
};
int main()
{
    Bank_Acc b;
    cout << "CHOICES ARE : " << endl;
    cout << "1 - input details\n2 - deposit\n3 - withdraw\n4 - show details" << endl;
    char ch;
    do
    {
        int choice;
        cout << "Enter choice : ";
        cin >> choice;
        if (choice == 1)
            b.get_info();
        else if (choice == 2)
            b.deposit();
        else if (choice == 3)
            b.withdraw();
        else if (choice == 4)
            b.show_info();
        else
            cout << "INVALID INPUT " << endl;

        cout << "Do you want to continue ? enter y " << endl;
        cin >> ch;
    } while (ch == 'y');
}