#include <iostream>
using namespace std;
class increase
{
    int n;

public:
    void input(void);
    void func(int &);
};
void increase::input(void)
{
    cout << "Enter the value of an argument: ";
    cin >> n;
    func(n);
}
void increase::func(int &n)
{
    n++;
    cout << "No after incrementing by 1: " << n;
}

int main()
{
    increase a;
    a.input();
    return 0;
}