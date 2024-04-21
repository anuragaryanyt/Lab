/* Rewrite program i. using class template */

#include <iostream>
using namespace std;
const int N = 5;

template <class T>
class Array
{
    T arr[N];

public:
    void input()
    {
        for (int i = 0; i < N; i++)
            cin >> arr[i];
    }
    void sort()
    {
        T temp;
        int SIZE = sizeof(arr) / sizeof(T);
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = i + 1; j < SIZE; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    void display()
    {
        int SIZE = sizeof(arr) / sizeof(T);
        for (int i = 0; i < SIZE; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Array<int> i1;
    Array<float> f1;

    cout << "Enter integer array:";
    i1.input();
    i1.sort();

    cout << "Enter floating number array:";
    f1.input();
    f1.sort();
    
    cout << "Integer array:" << endl;
    i1.display();
    cout << endl<< "Floating number array:" << endl;
    f1.display();
    return 0;
}
