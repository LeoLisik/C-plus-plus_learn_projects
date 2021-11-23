#include <iostream>
using namespace std;

int main()
{   
    double R, R1, R2, n, N;
    do {
        cout << "Vvedite soprotivlenie R1\n";
        cin >> R1;
     } while (R1 < 0 );
    do {
        cout << "Vvedite soprotivlenie R2\n";
        cin >> R2;
     } while ( R2 < 0 );
    do {
        cout << "Vvedite kolichestvo soedinitelnih provodov N\n";
        cin >> N;
     } while ( N < 1);
    do {
        cout << "Vvedite kolichestvo paralelno soedinennih odinnakovih lampochek n\n";
        cin >> n;
     } while (n < 1);
    R = (1 / (R2 * n)) + (1 / (R1 * N));
    if (R >= 0) {
        cout << "Tok est. On poloshitelni R = " << R << endl;
    }
    else cout << "Toka net, esli soprotivlenie otricatelnoe...\n";
}
