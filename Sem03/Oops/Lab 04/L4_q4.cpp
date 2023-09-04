#include <iostream>
using namespace std;
class numb
{
    int n;

public:
    inline void input()
    {
        cout << "Enter the number: \n";

        cin >> n;
    }
    void square(void);
    void cube(void);
};

inline void numb::square(void)
{
    cout << "The square of the number is: " << n * n << endl;
}
inline void numb::cube(void)
{
    cout << "The cube of the number is: " << n * n * n << endl;
}
int main()
{
    numb a;
    a.input();
    a.square();
    a.cube();
    return 0;
}
