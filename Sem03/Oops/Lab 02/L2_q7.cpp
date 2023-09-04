/* Create a class which stores x and y coordinates of a point. Calculate
distance between two given points and display it. */

#include<iostream>
#include<math.h>
using namespace std;

class coord
{
    int x;
    int y;
    public:
        void input();
        void dist(coord a);
};

void coord::input()
{
    cout << "Enter value of x and y : ";
    cin >> x >> y;
}

void coord::dist(coord a)
{
    cout << "Distance between " << "(" << x << "," << y << ") and " << "(" << a.x << "," << a.y << ")" <<endl;
    cout << sqrt(((x-a.x)*(x-a.x) + (y-a.y)*(y-a.y))) <<endl;
}

int main()
{
    coord a,b;
    a.input();
    b.input();
    a.dist(b);
    return 0;
}