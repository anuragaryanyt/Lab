/* WAP to throw and handle array out of bound’ exception */

#include<iostream>
using namespace std;
#define SIZE 5

int main()
{
    int arr[SIZE];
    cout << "Enter Elements : ";
    for (int i = 0;i < SIZE;i++)
        cin >> arr[i];

    cout << "Enter Index Required : ";
    int index;
    cin >> index;

    try {
        if (index <= SIZE)
            cout << arr[index];
        else {
            throw index;
        }
    }
    catch (int i) {
        cout << i << " is Out of Bounds";
    }

}
