#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
	int n;
	double E, sum = 0, s, f;
	do
	{
		cout << "Vvedite n " << endl;
		cin >> n;
	} while (n < 1);
	for (float k = 1; k <= n; k++)
	{
		f = (pow((-1) , k)/ ((2*k + 1 )*k));
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
		s = (pow((-1), k) / ((2 * k + 1) * k));
		if (abs(s) >= E)
		{
			cout << "А" << k << "= " << s << endl;
		}

	}

}