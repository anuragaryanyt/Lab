#include <iostream>
using namespace std;
class parcel
{
private:
    int wt;

protected:
    int ship_cost;

public:
    int n, vol;
    void call_shipping()
    {
        if (vol > 3)
            ship_cost = 10 * vol + 30;
        else
            ship_cost = 10 * vol;
        cout << "shipping cost:" << ship_cost << endl;
    }
};
class box : public parcel
{
    int wt, ht, d;

public:
    void volume()
    {
        cout << "Enter the ht,wt,depth: ";
        cin >> wt >> ht >> d;
        vol = wt * ht * d;
    }
};
int main()
{
    box b1;
    b1.volume();
    b1.call_shipping();
    return 0;
}
