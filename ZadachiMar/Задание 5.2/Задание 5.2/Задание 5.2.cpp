#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;


int main()
{
    const int n = 8;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите текст: ";
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'А') { s[i] = 'Е'; }
        if (s[i] == 'Б') { s[i] = 'Ж'; }
        if (s[i] == 'В') { s[i] = 'Ч'; }
        if (s[i] == 'Г') { s[i] = 'Б'; }
    }
    cout << s << endl;
    system("pause");
    return 0;

}