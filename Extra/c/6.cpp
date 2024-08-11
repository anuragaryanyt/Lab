// sum of elements in an array

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    cout <<"Sum of elements in array: "<<sum<< endl;
    return 0;
}
