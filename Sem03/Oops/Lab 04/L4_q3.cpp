#include <iostream>

using namespace std;
class abc
{
public:
    void function(int n, char ch)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    void function(char ch)
    {
        for (int i = 0; i < 80; i++)
        {
            cout << ch;
        }
        cout << endl;
    }
    void function(void)
    {
        char ch = '*';
        for (int i = 0; i < 80; i++)
        {
            cout << ch;
        }
    }
};
int main()
{
    abc a;
    int n;
    char ch;
    cout << "Enter the character you want to display" << endl;
    cin >> ch;
    cout << "Enter the "
}