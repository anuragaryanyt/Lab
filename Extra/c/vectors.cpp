#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    for (int i = 0; i < 6; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << endl;

    cout << "Orginal array: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.insert(v.begin() + 2, 99);
    cout << "After inserting at pos 3: ";
    int idx = 0;
    while (idx < v.size())
    {
        cout << v[idx++] << " ";
    }
    cout << endl;

    v.pop_back();
    cout << "After popping back: ";
    int idx2 = 0;
    while (idx2 < v.size())
    {
        cout << v[idx2++] << " ";
    }
    cout << endl;


    // v.erase(v.end() - 3);
    v.erase(v.begin() + 3);
    cout << "After erasing at pos 4: ";
    int idx3 = 0;
    while (idx3 < v.size())
    {
        cout << v[idx3++] << " ";
    }
    cout << endl;

    return 0;
}