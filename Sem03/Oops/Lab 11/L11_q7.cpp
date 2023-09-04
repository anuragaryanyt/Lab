// WAP to read and write objects to a file, using read and write function

#include <iostream>
#include <fstream>
using namespace std;
class test
{
    char name[20];
    int age;

public:
    void get()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    void show()
    {
        cout << "Name is " << name << endl
             << "Age is " << age << endl;
    }
};
int main()
{
    ofstream out;
    out.open("Test.txt");
    test ob1;
    ob1.get();
    out.write((char *)&ob1, sizeof(ob1));
    out.close();
    cout << "Object written on file" << endl;
    ifstream in;
    in.open("Test.txt");
    test ob2;
    in.read((char *)&ob2, sizeof(ob2));
    ob2.show();
    in.close();
}
