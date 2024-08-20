// position of last occurance of a element

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    cout << "Enter elements: ";
    for (int i = 0; i < 6; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    cout << endl;

    int x;
    cout << "Enter x: ";
    cin >> x;

    int occur;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
        {
            occur = i;
            continue;
        }
        // else
        // {
        //     cout << "Element not found" << endl;
        //     return -1;
        //     // break;
        // }
        
        }
    cout << "At Pos: " << occur + 1 << endl;
    return 0;
}
