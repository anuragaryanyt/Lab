/* Create a class which allocates the memory for a string through dynamic constructor. Overload the binary + to concatenate two strings and display it. */

#include <iostream>
#include <string>
using namespace std;

class String
{
    char *ch;
    short int len;

public:
    String(string str)
    {
        len = str.length();
        ch = new char[len];
        for (int i = 0; i < str.length(); i++)
        {
            ch[i] = str[i];
            cout << ch[i];
        }
    }

    bool operator<(const String &S)
    {
        return this->len < S.len;
    }
    String &operator+(const String &S)
    {
        String s("");
        s.len = this->len + S.len;
        int i = 0;
        for (; i < this->len; i++)
        {
            s.ch[i] = this->ch[i];
        }
        for (int j = 0; j < S.len; i++, j++)
        {
            s.ch[i] = s.ch[j];
        }
        return s;
    }
    void print()
    {
        for (int i = 0; i < len; i++)
        {
            cout << ch[i] << " ";
        }
    }
};

int main()
{
    String S1("Raj "), S2("Aryan");
    String S3("");
    S3 = S1 + S2;
    return 0;
}
