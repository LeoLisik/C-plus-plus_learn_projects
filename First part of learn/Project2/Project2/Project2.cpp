#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a, i;
	cout << "Vvedite a = ";
	cin >> a;
	cout << "Ploshad chego vam nada? 1-kvadrat 2-romb 3-kryg 4-ravnostoronni treyg = ";
	cin >> i;
	switch (i) {
	case 1: {cout << a * a; break;}
	case 2: {cout << a * a; break;}
	case 3: {cout << 3.14 * pow(a, 2); break;}
	case 4: {cout << (pow(a,2) * sqrt(3)) / 4; break;}
	default: {cout << "Vi gdeto oshiblis";}
	}
}