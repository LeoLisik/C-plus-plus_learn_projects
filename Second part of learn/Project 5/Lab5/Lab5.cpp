#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>
using namespace std;

char Vernam(char ch, string key, int number_of_check) {
	if (ch == '\n') {
		return '|';
	}
	if ((ch < 65 or ch > 90) and (ch < 97 or ch > 122)) {
		return ch;
	}
	while (number_of_check > key.length() - 1) {
		number_of_check -= key.length();
	}
	int result;
	if (ch >= 97 and ch <= 122) {
		result = (int(ch) % 97) ^ (int(tolower(key[number_of_check])) % 97);
		/*while (result > 26) {
			result -= 26;
		}
		while (result < 0) {
			result += 26;
		}*/
		cout << ch << " = " << result << endl;
		return char(result + 97);
	}
	else {
		result = (int(ch) % 65) ^ (int(tolower(key[number_of_check])) % 65);
		while (result > 26) {
			result -= 26;
		}
		while (result < 0) {
			result += 26;
		}
		return char(result + 65);
	}
}

char Atbash(char ch) {
	if (ch == '\n') {
		return '|';
	}
	if ((ch < 65 or ch > 90) and (ch < 97 or ch > 122)) {
		return ch;
	}
	if (ch >= 97 and ch <= 122) {
		return char((26 - (int(ch) % 97 + 1)) + 97);
	}
	else {
		return char((26 - (int(ch) % 65 + 1)) + 65);
	}
}

char UnCezar(char ch, int shift) {
	if (ch == '\n') {
		return '|';
	}
	if ((ch < 65 or ch > 90) and (ch < 97 or ch > 122)) {
		return ch;
	}

}

char Cezar(char ch, int shift) {
	if (ch == '\n') {
		return '|';
	}
	if ((ch < 65 or ch > 90) and (ch < 97 or ch > 122)) {
		return ch;
	}
	if (ch >= 65 and ch <= 90) {
		while ((int(ch) + shift) < 65)
		{
			ch += 26;
		}
		while ((int(ch) + shift) > 90)
		{
			ch -= 26;
		}
	}
	else {
		while ((int(ch) + shift) < 97)
		{
			ch += 26;
		}
		while ((int(ch) + shift) > 122)
		{
			ch -= 26;
		}
	}
	return char(int(ch) + shift); //65 122
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << int('z') << endl;
	char c = 'y';
	char str[9] = { 0 };

	for (int i = 8; i--; ) {
		str[7 - i] = !!(c & (1 << i)) + '0';
	}
	char x = 'h';
	char strx[9] = { 0 };

	for (int i = 8; i--; ) {
		strx[7 - i] = !!(x & (1 << i)) + '0';
	}
	printf("%s", str); cout << endl;
	printf("%s", strx); cout << endl;
	//cout << char(('a' ^ 'z') + 97);
	cout << char(((int('y') - 97) ^ (int('h') - 97)) + 97);
	FILE* f;
	char ch;
	string buff = "";
	int choice;
	cout << "Как шифровать будем?\n1 - Атбаш\n2 - Цезарь\n3 - Верман\n";
	cin >> choice;
	if ((f = fopen("Lab5File.txt", "r")) != NULL) {
		switch (choice)
		{
		case 1:
			while ((ch = getc(f)) != EOF) {
				cout << ch << endl;
				buff += Atbash(ch);
			}
			cout << endl << buff << endl;
			break;
		case 2:
			int shift;
			cout << "\nВведите смещение\n";
			cin >> shift;
			while ((ch = getc(f)) != EOF) {
				buff += Cezar(ch, shift);
			}
			break;
		case 3:
			int numberOfCheck = 0;
			string key;
			cout << "\nВведите ключ\n";
			cin >> key;
			while ((ch = getc(f)) != EOF) {
				buff += Vernam(ch, key, numberOfCheck);
				numberOfCheck++;
			}
			cout << endl << buff << endl;
			break;
		}
	}
	cout << "Зашифровано\n";
	if ((f = fopen("Lab5File.txt", "w")) != NULL) {
		for (int i = 0; i < buff.length(); i++) {
			if (buff[i] == '|') {
				putc('\n', f);
			}
			else {
				putc(buff[i], f);
			}
		}
	}
	cout << "Записано\n";
	fclose(f);
	buff = "";
	if ((f = fopen("Lab5File.txt", "r")) != NULL) {
		switch (choice)
		{
		case 1:
			while ((ch = getc(f)) != EOF) {
				buff += Atbash(ch);
			}
			break;
		case 2:
			int shift;
			cout << "Введите инвертированное смещение зашифрованного сообщения\n";
			cin >> shift;
			while ((ch = getc(f)) != EOF) {
				buff += Cezar(ch, shift);
			}
			break;
		case 3:
			string key;
			cout << "\nВведите ключ, которым зашифровано сообщение\n";
			cin >> key;
			for (int i = 0; (ch = getc(f)) != EOF; i++) {
				buff += Vernam(ch, key, i);
			}
			break;
		}
	}
	cout << "Расшифровано\n";
	if ((f = fopen("Lab5File.txt", "w")) != NULL) {
		for (int i = 0; i < buff.length(); i++) {
			if (buff[i] == '|') {
				putc('\n', f);
			}
			else {
				putc(buff[i], f);
			}
		}
	}
	cout << "Записано\n";
}