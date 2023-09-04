

#include<iostream>
using namespace std;

int f1()
{
    int a;
    cout << "Enter Value of A : ";
    cin >> a;

    try
    {
        if (a < 0)
            throw 5.5f;
        else if (a > 0)
            throw 'A';
        else
            throw 10;
    }

    catch (float t) {
        cout << t;
    }

    catch (char t) {
        cout << t;
    }

    catch (...) {
        cout << "Default Catch Block";
    }
}
