// iii. WAP to write 10 strings into a file and display them from file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream out;
    out.open("samplefile.txt");
    out << "hello good morning how you doing? is everything \nfine";
    out.close();
    string s;
    ifstream in;
    in.open("samplefile.txt");
    while (in.eof() == 0)
    {
        getline(in, s);
        cout << s << endl;
    }
    return 0;
}