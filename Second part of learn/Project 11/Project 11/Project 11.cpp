#include <iostream>
#include <Windows.h>
#include "Header.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    KDS* test = new KDS;
	test->DisplayList();
	test->SetValues();
	test->DisplayList();
	test->AddElementAfter(4, 9);
	test->DisplayList();
	test->AddElementBefore(3, 6);
	test->DisplayList();
	test->DeleteNode(6);
	test->DisplayList();
	test->Clearing();
	test->DisplayList();
}