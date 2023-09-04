#include <iostream>
using namespace std;
class Swap
{
    int a;
    int b;

public:
    void input(void);
    void swap(int *a, int *b);
    void display(void);
};
void Swap::input(void)
{
    cout << "Enter the first integer: \n";
    cin >> a;
    cout << "Enter the second integer: \n";
    cin >> b;
    cout << "Before Swapping: " << "a= " << a << "\t b= " << b << endl;
    swap(&a, &b);
}
void Swap::swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Swap::display(void)
{
    cout << "After Swapping: "<< "a= " << a << "\tb= " << b << endl;
}
int main()
{
    Swap s;
    s.input();
    s.display();

    return 0;
}
