// ii. WAP to copy content of one file to another.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    char c;
    ifstream in;
    in.open("samplefile.txt");
    ofstream out;
    out.open("samplefile2.txt");
    if (in && out)
    {
        while (in.eof() == 0)
        {
            in.get(c);
            // out.put(c);
            out << c;
        }
        cout << "Copy Finished.";
    }
    else
    {
        cout << "Cannot read file";
    }
    in.close();
    out.close();

    return 0;
}
