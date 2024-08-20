#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1 == s2)
    {
        cout << "It is an anagram!!" << endl;
    }
    else
    {
        cout << "Not an anagram!" << endl;
    }
    return 0;
}