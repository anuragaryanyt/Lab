// Create a class which stores a sting and its length as data members. Include all the constructors. Include a member function to join two strings and display the concatenated string.

#include <iostream>
#include <cstring>
using namespace std;
class conc
{
    char *str;
    int length;

public:
    conc()
    {
        length = 0;
        str = new char[length + 1];
    }
    conc(char *p)
    {
        length = strlen(p);
        str = new char[length + 1];
        strcpy(str, p);
    }
    void display(conc c1, conc c2)
    {
        length = c1.length + c2.length;
        str = new char[length + 1];
        strcpy(str, c1.str);
        strcat(str, c2.str);
        cout << str << endl;
    }
};
int main()
{
    char s1[] = "Hello ", s2[] = "World";
    conc c1(s1);
    conc c2(s2);
    conc c3;
    c3.display(c1, c2);
}
