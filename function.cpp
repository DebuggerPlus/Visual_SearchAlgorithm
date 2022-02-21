 #include "Header.h"
#include <iostream>
#include <windows.h>
#include<iomanip>
using namespace std;


void Init(int* arr, const int size)
{
	int range = 10;
	for (int i = 0; i < size; i++) arr[i] = rand() % range;
}

void MassOutPut(int* arr, int first, int last)
{
	int size = last - first;
	cout << endl << (char)201;
	for (int i = 0; i < 8; i++)cout << (char)205;
	cout << (char)203;
	for (int i = 0; i < size; i++) cout << (char)205 << (char)205 << (char)205 << (char)209;
	cout << (char)205 << (char)205 << (char)205 << (char)187 << endl;
	cout << (char)186 << "   i    " << (char)186;
	for (int i = first; i < last; i++) { cout << " " << i << " " << (char)179; }
	cout << " " << last << " " << (char)186 << endl;

	cout << (char)204;
	for (int i = 0; i < 8; i++)cout << (char)205;
	cout << (char)206;
	for (int i = 0; i < size; i++) cout << (char)196 << (char)196 << (char)196 << (char)197;
	cout << (char)196 << (char)196 << (char)196 << (char)182 << endl;
	cout << (char)186 << " arr[i] " << (char)186 << " ";
	for (int i = first; i < last; i++) cout << arr[i] << " " << (char)179 << " ";

	cout << arr[last] << " " << (char)186 << endl;

	cout << (char)200;
	for (int i = 0; i < 8; i++)cout << (char)205;
	cout << (char)202;
	for (int i = 0; i < size; i++) cout << (char)205 << (char)205 << (char)205 << (char)207;
	cout << (char)205 << (char)205 << (char)205 << (char)188 << endl << endl << endl;
}

int Search(int* arr, const int size, int key)
{
	int iKey=-1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) { iKey = i; break; }
	}
	return iKey;
}


void MazeOutPut(int* arr, int key, const int size) {

	//COORD output;
	//output.X = 65;
	//output.Y = 2;

	COORD coord_arr;

	enum maze_objects { HALL, WALL, GOLD, VRAG };
	enum direction { DOWN = 80, UP = 72, LEFT = 75, RIGHT = 77 };
	enum colors { BLUE = 9, RED = 12, YELLOW = 14, DARKGREEN = 2, WHITE = 7 };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int height = 5;
	int width=size*4+1;

	// объ€вление двумерного динамического массива
	int** maze = new int*[height];
	for (int i = 0; i < height; i++) maze[i] = new int[width];
	
	for (int i = 0; i<height; i++) {
		for (int j = 0; j <width; j++) {
			if (i == 0 || i == height-1 || j == 0 || /*j == width-1||*/!(j%4)) maze[i][j] = WALL;
		}
	}



	for (int y = 0; y < height; y++) {
		for (int x = 0; x <width; x++)
			if (maze[y][x] == WALL)
			{

				SetConsoleTextAttribute(h, DARKGREEN);
				// cout << "y = " << y << " x = " << x;
				cout << (char)178;
			}
			else cout << " ";
			
		cout << endl;
	}

	coord_arr.Y = 2;
	for (int i = 0; i < size; i++) {
		coord_arr.X = i * 4 + 2;
		SetConsoleCursorPosition(h, coord_arr);
		SetConsoleTextAttribute(h, WHITE);
		cout << arr[i];
	}

	coord_arr.Y = 10;
		SetConsoleCursorPosition(h, coord_arr);

}

void Color() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 8; i++) {
				SetConsoleTextAttribute(h, i);
				cout << i << endl;
	}
}
