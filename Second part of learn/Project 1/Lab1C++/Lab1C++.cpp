#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class student {
private:
	string FIO;
	float ResultFloat;
	int CountAllNumber;
	int* arr;
	void SrB() {
		for (int i = 0; i < CountAllNumber; i++) {
			ResultFloat += arr[i];
		}
		ResultFloat /= CountAllNumber;
	}
public:
	student() {
		cout << "Input FIO of student: ";
		getline(cin, FIO);
		cout << "\nInput number of marks: ";
		cin >> CountAllNumber;
		arr = new int[CountAllNumber];
		for (int i = 0; i < CountAllNumber; i++) {
			cout << "Input mark " << i + 1 << ": ";
			cin >> arr[i];
		}
		ResultFloat = 0;
		SrB();
	}
	void display() {
		cout << "FIO: " << FIO << endl;
		cout << "Marks: ";
		for (int i = 0; i < CountAllNumber; i++) {
			cout << arr[i] << " ";
		}
		cout << "\nAverage score: " << ResultFloat;
	}
	~student() {
		delete[] arr;
	}
};
	
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	student A;
	A.display();
}