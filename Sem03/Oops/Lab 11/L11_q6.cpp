// vi. WAP to convert all uppercase letters in a given file, to lower case and vice-versa.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;
    ifstream in;
    in.open("samplefile.txt");
    if (in)
    {
        while (in.eof() == 0)
        {
            in.get(ch);

            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + 32;
            }
            else if (ch >= 'a' && ch <= 'z')
            {
                ch = ch - 32;
            }
            cout << ch;
        }
    }
    else
    {
        cout << "Error occured";
    }
    return 0;
}
