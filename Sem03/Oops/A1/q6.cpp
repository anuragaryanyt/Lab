/* Write a program to enter the code, name and price of items. The user must feed the
quantity in which he wants a product. The program must calculate and display the
final bill of 10 items in the following format.

Sl.No. Code Name           Price   Quantity Total -------------------------------------------------------------------------------------
1. rib001 Printer catrige  300        2      600
2. Pap45 A4 size  paper    200        0        0
3. Bk216 Computer book     350        5     1750
--------------------------------------------------------------------------------------
                                                                Total = Rs.2350/-   */

#include <iostream>
using namespace std;
class bill
{
    int sl[10], price[10], q[10], tot[50], total, n;
    int code[30];
    string name[20];

public:
    void getdetails(void);
    void display(void);
    void calc(void);
};
void bill::getdetails(void)
{
    cout << "Enter the no of products: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the sl no: ";
        cin >> sl[i];

        cout << "Enter the code of the product: ";
        cin >> code[i];

        cout << "Enter the name of the product: ";
        cin >> name[i];

        cout << "Enter the price of the product: ";
        cin >> price[i];

        cout << "Enter the quantity of the product: ";
        cin >> q[i];
    }
}
void bill::calc(void)
{
    for (int i = 0; i < n; i++)
    {
        tot[i] = price[i] * q[i];
    }
    total = 0;
    for (int i = 0; i < n; i++)
    {
        total = total + tot[i];
    }
}
void bill::display(void)
{
    cout << "\n\nSl No."
         << "\tCode"
         << "\tName"
         << "\tPrice"
         << "\tQuantity"
         << "\tTotal" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << sl[i] << "\t" << code[i] << "\t" << name[i] << "\t" << price[i] << "\t" << q[i] << "\t\t" << tot[i] << endl;
    }
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t"
         << "Net Total=" << total << endl;
}

int main()
{
    bill b;
    b.getdetails();
    b.calc();
    b.display();

    return 0;
}
