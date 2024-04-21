// iv. WAP to display content of a file in reverse order
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void reverse(char c[], int i)
{

    while (i != -1)
    {
        cout << c[i - 1];
        i--;
    }
}
int main()
{
    char c[100];
    int i = 0;
    ifstream in;
    in.open("samplefile.txt");
    while (in.eof() == 0)
    {
        in >> c[i];
        cout << c[i];
        i++;
    }
    cout << "\nlengh of string = " << i << endl;
    cout << "Displaying content of a file in a reverse order\n";
    reverse(c, i);
    return 0;
}
