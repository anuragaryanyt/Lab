#include <iostream>
using namespace std;
class volume
{
    float r1, r2;
    int l, b, h1, h2;

public:
    void display_volume(void);
    void disp_vol(float r1);
    void disp_vol(float r2, int h1);
    void disp_vol(int l, int b, int h2);
};
void volume::display_volume(void)
{
    cout << "Enter the radius of sphere: \n";
    cin >> r1;
    disp_vol(r1);

    cout << "Enter the radius and height of the cylinder: \n";
    cin >> r2 >> h1;
    disp_vol(r2, h1);

    cout << "Enter the length, breadth & height of the cuboid: \n";
    cin >> l >> b >> h2;
    disp_vol(l, b, h2);
}
void volume::disp_vol(float r1)
{
    cout << "Area of Sphere: " << (4 / 3) * 3.14 * r1 * r1 << endl;
}
void volume::disp_vol(float r2, int h1)
{
    cout << "Area of cylinder: " << 3.14 * r2 * r2 * h1 << endl;
}
void volume::disp_vol(int l, int b, int h2)
{
    cout << "Area of cuboid: " << l * b * h2 << endl;
}
int main()
{
    volume v;
    v.display_volume();
    return 0;
}