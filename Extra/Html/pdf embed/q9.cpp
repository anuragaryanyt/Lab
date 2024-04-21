/* Write a menu-driven program that reads title of a book from the user. The program
will check if the book is available or not, if available then display the details of the
book such as author, price and number of copies available. Calculate the bill of the
user as per the number of copies required. Decrement the count of books requested
from available copies. The program must also have functions to update the number of
copies available and the price of the book. [Hint: Create a class book with the data
members: title, authorname, price and #no of copies] */

#include <iostream>
using namespace std;
class book
{
    string title[50], aname[50];
    int price[50], ncopy[50], count, n, y;

public:
    void getdetails();
    void display();
    void titlecheck();
    void bill();
};
void book::getdetails()
{

    cout << "Enter the no of books: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the book title: ";
        cin >> title[i];
        cout << "Enter the author name: ";
        cin >> aname[i];
        cout << "Enter the price of the book: ";
        cin >> price[i];
        cout << "Enter the number of copies available: ";
        cin >> ncopy[i];
    }
}
void book::display()
{
    cout << "Title"
         << "\tAuthor name"
         << "\tPrice"
         << "\tCopy available" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << title[i] << "\t" << aname[i] << "\t\t" << price[i] << "\t" << ncopy[i] << endl;
    }
}

void book::titlecheck()
{
    string x;
    cout << "Enter the book title: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (x == title[i])
        {
            cout << "Author name: " << aname[i] << "\tPrice: " << price[i] << "\tCopy available: " << ncopy[i];
        }

        // cout << "\nBook details not found!!!\n";
    }
}

void book::bill()
{
    string x;
    int pr, c;
    cout << "Enter the title of book you want: ";
    cin >> x;
    cout << "Enter the no of copies you want: ";
    cin >> y;
    cout << "\n\nTitle"
         << "\tPrice"
         << "\tQuantity"
         << "\tTotal" << endl;

    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        if (x == title[i] && y <= ncopy[i])
        {
            cout << title[i] << "\t" << price[i] << "\t" << y << "\t\t" << y * price[i] << endl;
            ncopy[i] -= y;
        }
    }
    cout << "--------------------------------------------------------" << endl;
}
int main()
{
    int i;
    book b;
    cout << "-------MENU-------" << endl;
    cout << "------------------" << endl;
    b.getdetails();
    while (true)
    {
        cout << "\n----Select appropriate option----" << endl;
        cout << "1. Display all books details" << endl;
        cout << "2. calculate the bill of the book" << endl;
        cout << "3. check the book available by entering book title" << endl;
        cout << "4. exit" << endl;
        cout << "Enter your choice: ";
        cin >> i;
        switch (i)
        {
        case 1:
            b.display();
            break;
        case 2:
            b.bill();
            break;
        case 3:
            b.titlecheck();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}
