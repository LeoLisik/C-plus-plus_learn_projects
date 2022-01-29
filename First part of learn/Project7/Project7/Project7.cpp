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

float FuncH(float i, float g, float V) {
    return V * i - ((i * i * g) / 2);
}

void maxEl(float* Speed, int el, int& iskEl, int length) {
    float maxSpeed = 0;
    for (int i = 0; i < length; i++) {
        if (Speed[i] < 0) { Speed[i] *= -1; }
        if (maxSpeed < Speed[i]) { maxSpeed = Speed[i]; iskEl = i; }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float N, V, t;
    float const g = 9.8;
    float* Height = new float[10000];
    float* Speed = new float[10000];
    float* Time = new float[10000];
    N = Vvod_chislo("Введите высоту(м)");
    V = Vvod_chislo("Введите начальную скорость(м/c)");
    t = Vvod_chislo("Введите время(сек)");
    Height[0] = N;
    Speed[0] = V;
    Time[0] = 0;
    int el = 1, iskEl = 1, length = 1;
    for (float i = 0.25; i < t; i += 0.25, el++) {
        if (-N > FuncH(i, g, V)) {
            break;
        }
        length++;
        Height[el] = FuncH(i, g, V);
        Speed[el] = V - g * i;
        Time[el] = i;
    }
    maxEl(Speed, el, iskEl, length);
    cout << "Высота = " << Height[iskEl] + N << "\nСкорость = " << Speed[iskEl] << "\nВремя = " << Time[iskEl] << endl;
    delete[]Height;
    delete[]Speed;
    delete[]Time;
}