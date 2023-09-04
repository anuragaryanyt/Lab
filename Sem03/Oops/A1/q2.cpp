/* WAP to add, multiply two polynomial using classes and objects. */

#include <iostream>
using namespace std;
class poly
{
    int order;
    int coeff[10];

public:
    void initialize();
    void getorder();
    void create();
    void poly3order(poly, poly);
    void polyadd(poly, poly);
    void display();
};

void poly::initialize()
{
    int i;
    for (i = 0; i < 10; i++)
        coeff[i] = 0;
}

void poly::getorder()
{
    cout << "Highest Order: ";
    cin >> order;
}

void poly::create()
{
    int i;
    for (i = order; i > -1; i--)
    {
        cout << "Exponent: " << i << " ";
        cout << "Coefficient: ";
        cin >> coeff[i];
    }
}
void poly::poly3order(poly f, poly s)
{
    if (f.order == s.order)
        order = f.order;
    else if (f.order > s.order)
        order = f.order;
    else if (s.order > f.order)
        order = s.order;
}

void poly::polyadd(poly fp, poly sp)
{
    int i;
    for (i = order; i > -1; i--)
        coeff[i] = fp.coeff[i] + sp.coeff[i];
}

void poly::display()
{
    int i;
    for (i = order; i > -1; i--)
    {
        if (i == order)
            cout << coeff[i] << "x^" << i << " ";
        else
        {
            if (coeff[i] >= 0)
                cout << "+";

            cout << coeff[i] << "x^" << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    poly p1, p2, p3;
    cout << "Polynomial 1:\n";
    p1.initialize();
    p1.getorder();
    p1.create();
    cout << "Polynomial 2:\n";
    p2.initialize();
    p2.getorder();
    p2.create();
    p3.initialize();
    p3.poly3order(p1, p2);
    p3.polyadd(p1, p2);
    cout << "First Polynomial: ";
    p1.display();
    cout << "Second Polynomial: ";
    p2.display();
    cout << "Third Polynomial: ";
    p3.display();
    return 0;
}