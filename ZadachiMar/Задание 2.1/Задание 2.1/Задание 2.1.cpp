#include <iostream>
using namespace std;

int main()
{
	double a, b, c;
	double x, y;
	cout << "Vvedite znachenie dirki\n";
	cin >> x;
	cin >> y;
	cout << "Vvedite znachenia kirpicha\n";
	cin >> a;
	cin >> b;
	cin >> c;

	if (a <= x and c <= y or a <= x and b <= y or b <= x and a <= y or b <= x and c <= y or c <= x and b <= y) {
		cout << "Kirpich podhodit\n";
	}
	else cout << "Kirpich ne podhodit\n";

}
