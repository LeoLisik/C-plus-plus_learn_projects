#include <iostream>
using namespace std;

int main()
{
    int n;
    double E, sum = 0, s, f;
    float k;
    do
    {
        cout << "Vvedite n " << endl;
        cin >> n;
    } while (n < 1);
    for (k = 1; k <= n; k++)
    {
        f = k / ((k + 1) * (k + 2));
        sum = sum + f;
    }
    cout << "Summa pervih n chlenov = " << sum << endl;
    do
    {
        cout << "Vvedite E" << endl;
        cin >> E;
    } while (E >= 1);
    for (double k = 1; k++;)
    {
        s = k / ((k + 1) * (k + 2));
        if (abs(s) >= E)
        {
            cout << "A" << k << "= " << s << endl;
        }

    }

}