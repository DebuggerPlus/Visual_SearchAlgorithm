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


void MazeOutPut(int* arr, int key, const int size, int x,int y) {

	VisualOutPut(arr, size, x, y);
	int* iKeys = new int[size];
	int qKeys = 0;
	int matches = 0;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		// скрыть курсор
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(h, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(h, &structCursorInfo);
	COORD Start;
	COORD coord_arr;
	COORD ckey = { 1,3 };
	COORD iKey;

	enum maze_objects { HALL, WALL, GOLD, VRAG };
	enum colors { BLUE = 9, RED = 12, YELLOW = 14, DARKGREEN = 2, WHITE = 7 };

	int key_color = BLUE;
	int index_color = YELLOW;

	SetConsoleCursorPosition(h, ckey);
	cout << "key = ";
	SetConsoleTextAttribute(h, key_color);
	cout << key;
	SetConsoleTextAttribute(h, WHITE);

	for (int i = 0; i < size; i++) {
		ckey.X = i*4+x+11;
		ckey.Y = y+10;
		Start.X = ckey.X;
		Start.Y = ckey.Y - 4;
		iKey.X = ckey.X;
		iKey.Y = ckey.Y - 8;
		SetConsoleCursorPosition(h, ckey);
		if (arr[i] == key) {
			matches++;
			iKeys[qKeys] = i;
			qKeys++;

			SetConsoleTextAttribute(h, key_color);
			cout << key;
			SetConsoleTextAttribute(h, WHITE);
			Sleep(500);
			for (int j = 0; j < 3; j++) {


				SetConsoleCursorPosition(h, ckey);
				cout << " ";
				SetConsoleCursorPosition(h, Start);
				cout << " ";
				Sleep(200);
				SetConsoleCursorPosition(h, ckey);
				SetConsoleTextAttribute(h, key_color);
				cout << key;
				SetConsoleTextAttribute(h, WHITE);
				SetConsoleCursorPosition(h, Start);
				cout << key;
				Sleep(500);

			}

			SetConsoleTextAttribute(h, key_color);
			SetConsoleCursorPosition(h, Start);
			cout << key;
			SetConsoleCursorPosition(h, iKey);
			SetConsoleTextAttribute(h, index_color);
			cout << i;
			SetConsoleCursorPosition(h, ckey);
			cout << " ";
			SetConsoleTextAttribute(h, WHITE);
		}
		else {

			SetConsoleTextAttribute(h, key_color);
			cout << key;
			SetConsoleTextAttribute(h, WHITE);
			Sleep(1000);
			SetConsoleCursorPosition(h, ckey);
			cout << " ";
		}
		

	}


	Sleep(1000);


	coord_arr.X = 0;
	coord_arr.Y = 5;
		SetConsoleCursorPosition(h, coord_arr);

		if (matches > 1) {

			cout << matches << " matches" << endl << endl;
			for (int i = 0; i < qKeys; i++) {
				cout << "iKeys[" << i << "] = ";
				SetConsoleTextAttribute(h, index_color);
				cout << iKeys[i] << endl;
				SetConsoleTextAttribute(h, WHITE);
			}
		}
		else if (matches == 1) {
			cout << "iKey = ";
			SetConsoleTextAttribute(h, index_color);
			cout << iKeys[0] << endl;
			SetConsoleTextAttribute(h, WHITE);
		}
			else cout << "No matches!" << endl;
			

		Start.X = 0;
		Start.Y = 20;

		SetConsoleCursorPosition(h, Start);

}

void Color() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 8; i++) {
				SetConsoleTextAttribute(h, i);
				cout << i << endl;
	}
}

void VisualOutPut(int* arr, const int size, int x, int y) {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	 // скрыть курсор
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(h, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(h, &structCursorInfo);

	COORD Start = { x,y };
	COORD coord_arr;

	SetConsoleCursorPosition(h, Start);

	enum maze_objects { HALL, WALL, GOLD, VRAG };
	enum colors { BLUE = 9, RED = 12, YELLOW = 14, DARKGREEN = 2, WHITE = 7 };

	int height = 9;
	int width = size * 4 + 1 + 9;

	// объявление двумерного динамического массива
	int** maze = new int* [height];
	for (int i = 0; i < height; i++) maze[i] = new int[width];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == height - 1 || j == 0 || !((j - 1) % 4) && j != 1 && j != 5 || i == height / 2) maze[i][j] = WALL;
		}
	}

	for (int dy = 0; dy < height; dy++) {
		Start.Y = dy + y;
		SetConsoleCursorPosition(h, Start);
		for (int dx = 0; dx < width; dx++)
			if (maze[dy][dx] == WALL)
			{
				SetConsoleTextAttribute(h, DARKGREEN);
				cout << (char)178;
			}
			else cout << " ";
		cout << endl;
	}

	coord_arr.X = x + 2;
	coord_arr.Y = y + 2;
	SetConsoleTextAttribute(h, WHITE);
	SetConsoleCursorPosition(h, coord_arr);
	cout << "index";
	coord_arr.Y = y + 6;
	SetConsoleCursorPosition(h, coord_arr);
	cout << "arr[i]";


	for (int i = 0; i < size; i++) {
		coord_arr.X = i * 4 + 2 + x + 9;
		coord_arr.Y = 6 + y;
		SetConsoleCursorPosition(h, coord_arr);
		SetConsoleTextAttribute(h, WHITE);
		cout << arr[i];
		coord_arr.Y = 2 + y;
		SetConsoleCursorPosition(h, coord_arr);
		cout << i;

	}

	Sleep(1000);
}