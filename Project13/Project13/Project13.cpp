#include <iostream>
#include <Windows.h>
using namespace std;

void multiDigit(string digitA, string digitB, int enterInt) {
	string fullNumberStr = ""; 
	int digitA1, digitA2, digitB1, digitB2, i;
	if (digitA.find_first_not_of("1234567890+i") < -1 or digitB.find_first_not_of("1234567890+i") < -1 or digitA.empty() or digitB.empty()) { cout << "Ошибка"; return; }
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
		
		break;
	}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	multiDigit("2+1i", "3+4i", 1);
}