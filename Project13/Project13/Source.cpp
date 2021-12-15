#include <iostream>
#include <Windows.h>
using namespace std;

void multiDigit(string digitA, string digitB, int enterInt) {
	string fullNumberStr = "";
	int digitA1, digitA2, digitB1, digitB2, i;
	for (i = 0; (isdigit(digitA[i])); i++) {
		fullNumberStr += digitA[i];
	}
	digitA1 = atof(fullNumberStr.c_str());
	fullNumberStr.clear();
	i++;
	while (isdigit(digitA[i])) {
		fullNumberStr += digitA[i];
		i++;
	}
	digitA2 = atof(fullNumberStr.c_str());
	fullNumberStr.clear();
	for (i = 0; (isdigit(digitB[i])); i++) {
		fullNumberStr += digitB[i];
	}
	digitB1 = atof(fullNumberStr.c_str());
	fullNumberStr.clear();
	i++;
	while (isdigit(digitB[i])) {
		fullNumberStr += digitB[i];
		i++;
	}
	digitB2 = atof(fullNumberStr.c_str());
	fullNumberStr.clear();
	switch (enterInt) {
	case 1: {
		cout << "Результат: " << digitA1 + digitB1 << " + " << digitA2 + digitB2 << "i ";
		break;
	}
	case 2: {
		cout << "Результат: " << digitA1 - digitB1 << " + " << digitA2 - digitB2 << "i ";
		break;
	}
	case 3: {
		cout << "Результат: " << digitA1 * digitB1 - digitA2 * digitB2 << " + " << (digitA1 * digitB2 + digitA2 * digitB1) << "i ";
		break;
	}
	case 4: {
		int znam = digitB1 * digitB1 + digitB2 * digitB2;
		float digit1 = digitA1 * digitB1 - digitA2 * digitB2;
		float digit2 = digitA1 * digitB2 + digitA2 * digitB1;
		cout << "Результат: " << digit1 / znam << " + " << digit2 / znam << "i" << endl;
		break;
	}
	}
	cout << endl;
}