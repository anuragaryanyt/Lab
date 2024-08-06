//check for palindrome

#include <iostream>
using namespace std;

bool isPalindrome(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        if (arr[start] != arr[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    if (isPalindrome(arr, size))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}
