#include "Header.h"
#include <string>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string complex1, complex2, doingStr;
	int doing;
	while (true) {
		while (true) {
			cout << "Введите первое комплексное число вида(2+4i) = ";
			getline(cin, complex1);
			if (complex1.find_first_not_of("1234567890+-i") < -1 or complex1.empty() or complex1.length() < 4 or complex1.find("i") > 1000 or complex1.find_first_of("+-") > 1000 or complex1.find_first_of("i") != complex1.length() - 1) {
				cout << "Ошибка\n"; 
				continue; 
			}
			break;
		}
		while (true) {
			cout << "Введите второе комплексное число вида(2+4i) = ";
			getline(cin, complex2);
			cout << complex2.find_first_of("i");
			if (complex2.find_first_not_of("1234567890+-i") < -1 or complex2.empty() or complex2.length() < 4 or complex2.find("i") > 1000 or complex2.find_first_of("+-") > 1000 or complex2.find_first_of("i") != complex2.length() - 1) {
				cout << "Ошибка\n";
				continue;
			}
			break;
		}
		while (true) {
			cout << "1 - Сложить, 2 - Вычесть, 3 - Умножить, 4 - разделить\nВаш выбор: ";
			getline(cin, doingStr);
			if (doingStr.find_first_not_of("1234") < -1 or doingStr.length() > 1 or doingStr.empty()) {
				cout << "Ошибка\n";
				continue;
			}
			doing = atof(doingStr.c_str());
			break;
		}
		multiDigit(complex1, complex2, doing);
	}
}