// i. WAP to display content of a file using character output function.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    char c;
    ifstream in;
    in.open("samplefile.txt");
    while (in.eof() == 0)
    {
        in.get(c);
        cout << c;
    }
    in.close();
    return 0;
}