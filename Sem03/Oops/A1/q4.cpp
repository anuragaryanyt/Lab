/* WAP that uses a date structure within a class. Enter any date and your birth date. The
program must display your exact age in years, months and days. */

#include <iostream>
using namespace std;
class date
{
    int bdate[3];
    int date[3];
    int d, m, y;

public:
    void getdetails(void);
    void calc(void);
    void display(void);
};
void date::getdetails(void)
{
    cout << "Enter your Birth Day, month & year: ";
    cin >> bdate[0] >> bdate[1] >> bdate[2];

    cout << "Enter your any Day, month & year: ";
    cin >> date[0] >> date[1] >> date[2];
}
void date::calc(void)
{
    int month[] = {31, 28, 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31};

    if (bdate[0] > date[0])
    {
        date[0] = date[0] + month[bdate[1] - 1];
        date[1] = date[1] - 1;
    }

    if (bdate[1] > date[1])
    {
        date[2] = date[2] - 1;
        date[1] = date[1] + 12;
    }

    d = date[0] - bdate[0];
    m = date[1] - bdate[1];
    y = date[2] - bdate[2];
}
void date::display(void)
{
    cout << "Age \n  Year: " << y << " \tMonth: " << m << " \tDay: " << d;
}

int main()
{
    date d;
    d.getdetails();
    d.calc();
    d.display();
    return 0;
}
