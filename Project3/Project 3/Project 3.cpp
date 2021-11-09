#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int i = 0, t = 0;
    float N = 10, A = 0, Y = 10;
    cout << "Введите cymarni pyt = ";
    cin >> A;
    if (A < 10) {
        cout << "\x1b[31mПожалуйста перезапустите программу и введите число больше 9\x1b[0m" << endl;
    }
    else {
        for (i = 1; N < 21; i++) {
            N = N + N / 10;
        }
        cout << "On probejal bolshe 21 km na " << i << " den." << endl;

        for (i = 1, N = 10; Y < A; i++) {
            N = N + N / 10;
            Y += N;
        }
        cout << A << "km on probejal za " << i << " dnei.";
    }
}