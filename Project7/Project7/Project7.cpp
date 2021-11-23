#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

float Vvod_chislo(string s, string b = "", float n = 0) {
    do {
        do {
            cout << s << " = ";
            getline(cin, b);
        } while ((b.find_last_not_of("-0123456789.") != -1) or (b.find_last_of("-") != -1 and b.find_last_of("-") != 0) or (b.find_last_of(".") - b.find_first_of(".") != 0));
        n = atof(b.c_str());
    } while (n < 0.1);
    return n;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float N, V, t;
    float const g = 9.8;
    float* Height = new float[];
    float* Speed = new float[];
    float* Time = new float[];
    N = Vvod_chislo("Введите высоту(м)");
    V = Vvod_chislo("Введите начальную скорость(м/c)");
    t = Vvod_chislo("Введите время(сек)");
    for (int i = 0, el = 0; i < t; i += 0.25, el++) {

    }
}