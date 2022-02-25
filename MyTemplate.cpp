// MyTemplate
#include <iostream>
#include "Header.h"
// #include<windows.h>
using namespace std;

void main()
{
	const int size = 10;
	int arr[size] = { 0 };
	int key = 4;
	Init(arr, size);

	// MassOutPut(arr, 0, size - 1);
	MazeOutPut(arr, key, size,20,5);

	// Color();

	// cout << "Key = " << key << endl;
	// cout << "iKey = " << Search(arr, size, key) << endl;

	 // VisualOutPut(arr, size, 10, 5);

}
