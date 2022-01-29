#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    float x1,x2,x3,y1,y2,y3,m1,m2,m3;
    cout << "Vvedite coordinati pervoi materialnoi tochki i massy(x, y, m)" << endl;
    cin >> x1 >> y1 >> m1;
    cout << "Vvedite coordinati vtoroi materialnoi tochki i massy(x, y, m)" << endl;
    cin >> x2 >> y2 >> m2;
    cout << "Vvedite coordinati treti materialnoi tochki i massy(x, y, m)" << endl;
    cin >> x3 >> y3 >> m3;
    cout << "Xc = " << (x1 * m1 + x2 * m2 + x3 * m3) / (m1 + m2 + m3) << " Yc = " << (y1 * m1 + y2 * m2 + y3 * m3) / (m1 + m2 + m3);
}
