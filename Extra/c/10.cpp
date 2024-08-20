// find non-repeating elements

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 2, 3, 1, 6, 4, 7, 7, 8, 9, 0,0};
    for (int i = 0; i < arr.size(); i++)                      // o(n^2) time complexity

    {
        int count = 0;
        int x = arr[i];
        for (int j = 0; j < arr.size(); j++)
        {            if (arr[j] == x)
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}






// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int main() {
//     vector<int> arr = {1, 2, 2, 3, 1, 6, 4, 7, 7, 8, 9, 0};
//     unordered_map<int, int> freq;

//     // Count the frequency of each element
//     for (int num : arr) {
//         freq[num]++;
//     }

//     // Print elements with frequency of 1
//     for (int num : arr) {
//         if (freq[num] == 1) {
//             cout << num << " ";
//             // Set frequency to a negative value to avoid printing it again
//             freq[num] = -1;
//         }
//     }
//     cout << endl;

//     return 0;
// }
