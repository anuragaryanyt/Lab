/* WAP to add two objects of distance class. Overload the operator ‘>’ to compare two objects and return the object with larger time value and display it. Overload the ‘==’ operator to compare and display whether two given objects contain same distance value. */

#include <iostream>
using namespace std;
class Distance
{
    int a;

public:
    Distance(){};
    Distance(int d)
    {
        a = d;
    }
    Distance operator>(Distance &ob)
    {
        Distance temp;
        if (a > ob.a)
            temp.a = a;
        else
            temp.a = ob.a;
        return temp;
    }
};
