#include <iostream>

using namespace std;
template <class T>
class vector
{
    T a, b, c;

public:
    void get()
    {
        cin >> a >> b >> c;
    }
    void show()
    {
        cout << a << "i +" << b << "j +" << c << " k" << endl;
    }
    T multiply(vector y)
    {
        vector d;
        d.a = a * y.a;
        d.b = b * y.b;
        d.c = c * y.c;
        return (d.a + d.b + d.c);
    }
};

int main()
{
    vector <int> v1, v2;
    v1.get();
    // v1.show();
    v2.get();
    // v2.show();
    cout << v1.multiply(v2) << endl;

    vector <float> v3, v4;
    v3.get();
    // v3.show();
    v4.get();
    // v4.show();
    cout << v3.multiply(v4) << endl;

    return 0;
}
