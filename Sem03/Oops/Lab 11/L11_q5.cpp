// v. WAP to count following in a given file:
// a. No. of characters
// b. No. of words
// c. No. of lines
// d. No. of uppercase letters, lowercase letters, digits and special symbols
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;
    int i = 0;
    int n_ch = 0;
    int n_words = 1;
    int n_line = 1;
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int spl_no = 0;
    ifstream in;
    in.open("Samplefile.txt");

    while (in.eof() == 0)
    {
        in.get(ch);
        cout << ch;
        i++;
        n_ch++;
        if (ch == ' ' || ch == '\n')
        {
            n_words++;
            n_ch--;
        }
        if (ch == '\n')
        {
            n_line++;
        }
        if (ch >= 'A' && ch <= 'Z')
        {
            upper++;
        }
        if (ch >= 'a' && ch <= 'z')
        {
            lower++;
        }
        if (ch >= '0' && ch <= '9')
        {
            digit++;
        }
        if (ch >= '33' && ch <= '47')
        {
            spl_no++;
        }
    }

    cout << "\na.No. of characters = " << n_ch++ << endl
         << "b. No. of words = " << n_words << endl
         << "c. No. of lines = " << n_line << endl
         << "d. No. of Uppercase = " << upper << endl
         << "e. No. of Lowercase = " << lower << endl
         << "f. No. of digits = " << digit << endl
         << "g. No. of special character = " << spl_no << endl;
    in.close();
    return 0;
}