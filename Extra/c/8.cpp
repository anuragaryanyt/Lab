// Insert element in the array

// using vector:

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int element = 99;
    int pos = 1;
    int size = sizeof(arr) / sizeof(arr[0]);

    // arr.begin() + pos: Calculates an iterator pointing to the position where you want to insert the new element.
    // arr.insert(...): Inserts element (99) at the specified position in the vector.

    arr.insert(arr.begin() + pos, element);

    cout << "Updated array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     int element = 99;
//     int pos = 2;

//     for (int i = size; i > pos; --i)
//     {
//         arr[i] = arr[i - 1];
//     }
//     arr[pos] = element;
//     ++size;

//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
