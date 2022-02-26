// debuggerplus.com
#include <iostream>
#include "Header.h"
#include<windows.h>
#include<conio.h>
using namespace std;

void main()
{
	system("pause");
	system("cls");
	const int size = 10;
	int arr[size] = { 0 };
	int key = 4;
	srand(time(0));
	int direct = 0;

	do {
		Init(arr, size);

		MazeOutPut(arr, key, size, 20, 5);

		cout << "Press any key for repeat! Esc for exit!";
		direct = _getch();
		Sleep(1000);
		system("cls");
	} while (direct!=27);
	
}
