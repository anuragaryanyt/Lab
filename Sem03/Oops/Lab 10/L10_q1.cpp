// WAP to find sort an integer array and a float array, using function template

#include <iostream>
using namespace std;
#define S 5

template <class T>
void sort(T arr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (arr[i] > arr[j])
            {
                T temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int int_a[S];
    cout << "Enter integer elements :" << endl;
    for (int i = 0; i < S; i++)
    {
        cin >> int_a[i];
    }

    float f_arr[S];
    cout << "Enter float elements:" << endl;
    for (int i = 0; i < S; i++)
    {
        cin >> f_arr[i];
    }

    sort(int_a, S);

    cout << "\nAfter sorting:" << endl;
    cout<<"\nInteger elements Sorting:" << endl;
    for (int i = 0; i < S; i++)
    {
        cout << int_a[i] << " ";
    }
    cout << endl;

    sort(f_arr, S);
    cout<<"\nFloat elements Sorting:" << endl;
    for (int i = 0; i < S; i++)
    {
        cout << f_arr[i] << " ";
    }
    return 0;
}
