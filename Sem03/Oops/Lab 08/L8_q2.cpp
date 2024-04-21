/* Create a class to store an integer array. Overload insertion and extraction operator to
input and display the array elements */

#include <iostream>
using namespace std;
class Input
{
public:
    int a[5];
    Input(){};
    friend ostream &operator<<(ostream &, Input &);
    friend istream &operator>>(istream &, Input &);
};

ostream &operator<<(ostream &out, Input &arr)
{
    for (int i = 0; i < 5; i++)
        out << arr.a[i] << " ";
    out << endl;
    return out;
}

istream &operator>>(istream &in, Input &arr)
{
    for (int i = 0; i < 5; i++)
        in >> arr.a[i];
    return in;
}

int main()
{
    Input i;
    cout << "Input elements: ";
    cin >> i;
    cout << "Elements entered: " << i;
    return 0;
}
