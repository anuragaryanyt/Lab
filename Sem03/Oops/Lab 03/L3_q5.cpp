#include <iostream>
#include <conio.h>
using namespace std;

int const size = 50;

class ballot
{
    int candidate; // candidate you want to create for votingint vote[size];
    int ballot[5];
    static int spballot; // spoil ballotpublic :
public:
    void display();
};

int ballot::spballot;

void ballot::display()
{
    cout << "\nEnter how many candidate you want to make:-";
    cin >> candidate;

    static int a, b, c, d, e;

    a = b = c = d = e = 0;
    int vote[100];
    cout << "\nEnter 1-5 Integers\n";
    for (int i = 0; i < candidate; i++)
    {
        cin >> vote[i];
        switch (vote[i])
        {
        case 1:
            ballot[a];
            a++;
            break;
        case 2:
            ballot[b];
            b++;
            break;
        case 3:
            ballot[c];
            c++;
            break;
        case 4:
            ballot[d];
            d++;
            break;
        case 5:
            ballot[e];
            e++;
            break;
        default:
            ++spballot;
        }
    }

    // for displaying int choice;
    do
    {
        int choice;
        cout << "\n\n\n\nChoices Available\n";
        cout << "\n1)  Scored By Ballot A\n";
        cout << "2)  Scored By Ballot B\n";
        cout << "3)  Scored By Ballot C\n";
        cout << "4)  Scored By Ballot D\n";
        cout << "5)  Scored By Ballot E\n";
        cout << "6)  Spoilt Ballot\n";
        cout << "7)  EXIT\n";
        cout << "Enter Your Choice :- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Scored By Ballot A is " << a;
            break;
        case 2:
            cout << "Scored By Ballot B is " << b;
            break;
        case 3:
            cout << "Scored By Ballot C is " << c;
            break;
        case 4:
            cout << "Scored By Ballot D is " << d;
            break;
        case 5:
            cout << "Scored By Ballot E is " << e;
            break;
        case 6:
            cout << "Spoil Ballot were " << spballot;
            break;
        case 7:
            exit(0);
        }
    } while (1);
}

int main()
{
    // clrscr();
    ballot abc;
    abc.display();
    return 0;
}