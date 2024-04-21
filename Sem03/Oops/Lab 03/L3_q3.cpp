// Create a class with an integer data member. Include functions for input and output in class. Count the number of times each function is called and display it.

#include <iostream>
using namespace std;
class count
{
    static int cinp;
    static int cou;
    int x, y;

public:
    void input()
    {
        cout << "Enter the values of x and y :";
        cin >> x >> y;
        cinp++;
    }
    void output()
    {
        cout << "x= " << x << "y= " << y << endl;
        cou++;
    }
    void display()
    {
        cout << "No of times Input function is called : " << cinp << endl;
        cout << "No of times Output function is called :" << cou << endl;
    }
};
int count::cinp;
int count::cou;

int main()
{
    count obj;
    obj.input();
    obj.output();
    obj.input();
    obj.output();
    obj.display();
}