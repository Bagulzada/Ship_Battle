#pragma once
#include"Data.h"

void intro() {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 11);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tSHIP BATTLE";
	Sleep(2000);
	system("cls");
}

us menu(const char* Menu[], us length) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char key{};
	short menuPos = 0;

	while (true)
	{

		menuPos %= length;
		if (menuPos < 0) menuPos = length;

		for (size_t i = 0; i < length; i++)
		{
			if (i == menuPos) {
				SetConsoleTextAttribute(h, 11);
			}
			else
			{
				SetConsoleTextAttribute(h, 15);
			}
			cout << Menu[i] << ' ' << endl;
		}

		key = _getch();
		if (key == 224) 
		{

			key = _getch();
			switch (key)
			{
			case UP:
				menuPos--;
				break;
			case DOWN:
				menuPos++;
				break;
			}
		}
		else 
		{
			if (key == 13) 
			{
				return menuPos + 1;
			}
		}
		SetConsoleTextAttribute(h, 15);
		system("cls");
	}
}

void board(int player[10][10], int ai[10][10], int player_ship, int ai_ship) {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	for (size_t i = 0; i < 2; i++)
	{
		cout << setw(4) << 'A';
		for (size_t j = 0; j < 9; j++)
		{
			cout << ' ' << char('B' + j);
		}
		cout << "\t\t\t";
	}
	cout << '\n';

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			SetConsoleTextAttribute(h, 15);
			if (j == 0) {
				cout << setw(2) << i + 1 << ' ';
			}

			if (player[i][j] == 0)
			{
				SetConsoleTextAttribute(h, 187);
				cout << char(176) << char(176);
			}
			else if (player[i][j] >= 1 && player[i][j] <= 4)
			{
				SetConsoleTextAttribute(h, 8);
				cout << char(219) << char(219);
			}
			else if (player[i][j] == 5)
			{ 
				SetConsoleTextAttribute(h, 187);
				cout << char(177) << char(177);
			}
			else if (player[i][j] == 6)
			{
				SetConsoleTextAttribute(h, 10);
				cout << char(219) << char(219);
			}
			else if (player[i][j] == 7)
			{
				SetConsoleTextAttribute(h, 68);
				cout << char(176) << char(176);
			}
			else if (player[i][j] == 8)
			{
				SetConsoleTextAttribute(h, 74);
				cout << char(176) << char(176);
			}
		}

		cout << "\t\t\t";

		for (size_t j = 0; j < 10; j++)
		{
			SetConsoleTextAttribute(h, 11);
			if (j == 0)
			{
				cout << setw(2) << i + 1 << ' ';
			}
			if (ai[i][j] == 6)
			{
				SetConsoleTextAttribute(h, 4 | 0);
				cout << char(219) << char(219);
			}

			else if (ai[i][j] == 7)
			{
				SetConsoleTextAttribute(h, 4 | 0);
				cout << char(176) << char(176);
			}

			else if (ai[i][j] == 8)
			{
				SetConsoleTextAttribute(h, 74);
				cout << char(176) << char(176);
			}

			else
			{
				cout << char(176) << char(176);
			}

		}
		cout << '\n';
	}
}
