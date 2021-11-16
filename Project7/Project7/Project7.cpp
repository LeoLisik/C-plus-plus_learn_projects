#include <iostream>
#include <Windows.h>
using namespace std;

float hight(float V, float t) {
    return (V * t) / 2;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float N, V, t, h, const g = 9.8, v2;
    cout << "Введите высоту(м) = ";
    cin >> N;
    cout << "Введите начальную скорость(м/c) = ";
    cin >> V;
    cout << "Введите время подъёма тела на максимальную высоту(сек) = ";
    cin >> t;
    h = hight(V, t);
    v2 = 2 * g * h;
}