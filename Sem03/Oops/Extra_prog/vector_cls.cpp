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
        cout << a << "i +" << b << "j + " << c << "k" << endl;
    }
    vector add(vector y)
    {
        vector d;
        d.a = a + y.a;
        d.b = b + y.b;
        d.c = c + y.c;
        return (d);
    }
};

int main()
{
    vector<int> v1, v2, v3;
    v1.get();
    v2.get();
    v3 = v1.add(v2);
    v3.show();
    vector<float> v4, v5, v6;
    v4.get();
    v5.get();

    v6 = v4.add(v5);
    v6.show();

    return 0;
}

