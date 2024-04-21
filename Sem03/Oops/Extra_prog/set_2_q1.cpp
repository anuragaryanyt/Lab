#include<iostream>
#include<string.h>
using namespace std;
class abc
{
    char str[20];
    public:
    void input()
    {
        cout<<"Enter a string: ";
        cin>>str;

    }
    void display()
    {
        cout<<"String is: "<<str;
    }
    abc operator+(abc x)
    {
        abc temp;
        strcpy(temp.str,str);
        strcat(temp.str,x.str);
        return temp;
    }
};

int main()
{
    abc s1,s2,s3;
    s1.input();
    s2.input();
    s3=s1+s2;
    s3.display();
    return 0;
}
