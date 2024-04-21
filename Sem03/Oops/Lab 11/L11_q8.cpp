//WAP to write multiple data to a file using insertion operator and read data from file using extraction operator

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char name[20], n[20];
    int age, a;
    float weight, w;
    ofstream o("Data.txt");
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter weight: ";
    cin >> weight;
    o << name << "\n";
    o << age << "\n";
    o << weight;
    o.close();
    ifstream i;
    i.open("Data.txt");
    i >> n;
    cout << "Name: " << n << endl;
    i >> a;
    cout << "Age: " << a << endl;
    i >> w;
    cout << "Weight: " << w << endl;
}
