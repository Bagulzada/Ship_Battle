#pragma once
#include "Data.h"
#include "Help_func.h"
#include "UI.h"

bool attack(int player[10][10], int num, int letter, int change[10][10], int& desck) {

	if (player[num][letter] >= 1 && player[num][letter] <= 4) {
		desck = change[num][letter];
		change[num][letter] = 6;
		return true;
	}

	change[num][letter] = 7;
	return false;

}

bool killed_ships_check(int player_field[10][10], int hit_numb, int hit_letter, int hit_decks) {

	int hit_decks_count = 1;

	if (hit_decks_count == hit_decks) return true;

	for (int i = 1; i < hit_decks; i++)
	{
		if (player_field[hit_numb + i][hit_letter] == 6)
		{
			hit_decks_count++;
		}
		else if (player_field[hit_numb + i][hit_letter] == 5 || player_field[hit_numb + i][hit_letter] == 7 || player_field[hit_numb + i][hit_letter] == 8 || hit_numb + i > 9)
		{
			break;
		}
	}
	for (int i = 1; i < hit_decks; i++)
	{
		if (player_field[hit_numb - i][hit_letter] == 6)
		{
			hit_decks_count++;
		}
		else if (player_field[hit_numb - i][hit_letter] == 5 || player_field[hit_numb - i][hit_letter] == 7 || player_field[hit_numb - i][hit_letter] == 8 || hit_numb - i < 0)
		{
			break;
		}
	}
	for (int i = 1; i < hit_decks; i++)
	{
		if (player_field[hit_numb][hit_letter + i] == 6)
		{
			hit_decks_count++;
		}
		else if (player_field[hit_numb][hit_letter + i] == 5 || player_field[hit_numb][hit_letter + i] == 7 || player_field[hit_numb][hit_letter + i] == 8 || hit_letter + i > 9)
		{
			break;
		}
	}
	for (int i = 1; i < hit_decks; i++)
	{
		if (player_field[hit_numb][hit_letter - i] == 6)
		{
			hit_decks_count++;
		}
		else if (player_field[hit_numb][hit_letter - i] == 5 || player_field[hit_numb][hit_letter - i] == 7 || player_field[hit_numb][hit_letter - i] == 8 || hit_letter - i < 0)
		{
			break;
		}
	}

	if (hit_decks_count == hit_decks) return true;

	return false;

}

void around_ship(int player[10][10], int hit_numb, int hit_letter, int hit_decks) {

	int number1{}, number2{}, col_start{}, col_end{};

	for (size_t i = 0; i <= hit_decks; i++)
	{
		if (player[hit_numb + i][hit_letter] != 6) {
			number2 = hit_numb + i - 1;
			break;
		}
	}
	for (size_t i = 0; i <= hit_decks; i++)
	{
		if (player[hit_numb - i][hit_letter] != 6) {
			number1 = hit_numb - i + 1;
			break;
		}
	}
	for (size_t i = 0; i <= hit_decks; i++)
	{
		if (player[hit_numb][hit_letter + i] != 6) {
			col_end = hit_letter + i - 1;
			break;
		}
	}
	for (size_t i = 0; i <= hit_decks; i++)
	{
		if (player[hit_numb][hit_letter - i] != 6) {
			col_start = hit_letter - i + 1;
			break;
		}
	}

	if (number1 == number2)
	{
		for (size_t i = 0; i < hit_decks; i++)
		{
			if (number1 != 0)
				player[number1 - 1][col_start + i] = 8;

			if (number1 != 9)
				player[number1 + 1][col_start + i] = 8;

		}

		if (col_start != 0) {
			player[number1][col_start - 1] = 8;

			if (number1 != 0)
				player[number1 - 1][col_start - 1] = 8;

			if (number1 != 9)
				player[number1 + 1][col_start - 1] = 8;
		}

		if (col_end != 9) {
			player[number1][col_end + 1] = 8;

			if (number1 != 0)
				player[number1 - 1][col_end + 1] = 8;

			if (number1 != 9)
				player[number1 + 1][col_end + 1] = 8;
		}

	}
	else if (col_start == col_end) {

		for (size_t i = 0; i < hit_decks; i++)
		{

			if (col_start != 0)
				player[number1 + i][col_start - 1] = 8;

			if (col_start != 9)
				player[number1 + i][col_start + 1] = 8;

		}

		if (number1 != 0) {

			player[number1 - 1][col_start] = 8;

			if (col_start != 0)
				player[number1 - 1][col_start - 1] = 8;

			if (col_start != 9)
				player[number1 - 1][col_start + 1] = 8;
		}

		if (number2 != 9) {

			player[number2 + 1][col_start] = 8;

			if (col_start != 0)
				player[number2 + 1][col_start - 1] = 8;

			if (col_start != 9)
				player[number2 + 1][col_start + 1] = 8;

		}
	}

}

bool is_win(int player_ships, int ai_ships) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (ai_ships == 0) {

		for (size_t i = 0; i < 10; i++)
		{
			SetConsoleTextAttribute(h, 79);
			cout << "";
			Sleep(1000);
			cout << "\nYOU WIN" << endl;
			Sleep(500);
			SetConsoleTextAttribute(h, 7);
			system("cls");
		}

		return true;
	}
	if (player_ships == 0) {

		SetConsoleTextAttribute(h, 192);
		cout << "\nLOSE" << endl;
		SetConsoleTextAttribute(h, 7);
		return true;
	}
}

void starter(int player[10][10], int ai[10][10], int& ai_ships, int& player_ships) {

	bool win{}, player_move{ true }, ai_move{ false };
	int hit_numb{}, hit_letter{};
	char letter{};
	bool ship_hitted{};
	int prev_numb{}, prev_let{};
	int hit_decks{};

	while (player_ships > 0 && ai_ships > 0) {

		while (player_move) {
			do {
				cout << "\n\n\n\t\t\tLet's Attack: ";
				cin >> letter >> hit_numb;

				hit_numb--;

				hit_letter = numb_letter(letter);
			} while (hit_numb > 9 || hit_numb < 0 || hit_letter > 9 || hit_letter < 0 ||
				ai[hit_numb][hit_letter] == 6 || ai[hit_numb][hit_letter] == 7 || ai[hit_numb][hit_letter] == 8);

			player_move = attack(ai, hit_numb, hit_letter, ai, hit_decks);

			if (player_move != true) {
				ai_move = true;
			}
			else {
				if (killed_ships_check(ai, hit_numb, hit_letter, hit_decks)) {
					around_ship(ai, hit_numb, hit_letter, hit_decks);
					ai_ships--;
				}
			}


			system("cls");
			board(player, ai, player_ships, ai_ships);

			if (is_win(player_ships, ai_ships)) break;
		}
		while (ai_move) {

			hit_numb = 0;
			hit_letter = 0;
			cout << "\n\n\n\t\t\t\tWait" << endl;

			do {
				if (ship_hitted) {
					do {
						hit_numb = prev_numb + rand() % 7 - 3;
						hit_letter = prev_let + rand() % 7 - 3;
					} while (hit_numb != prev_numb && hit_letter != prev_let ||
						hit_numb > 9 || hit_numb < 0 || hit_letter > 9 || hit_letter < 0);
				}
				else {
					hit_numb = rand() % 10;
					hit_letter = rand() % 10;
				}
			} while (player[hit_numb][hit_letter] == 6 || player[hit_numb][hit_letter] == 7 || player[hit_numb][hit_letter] == 8);

			ai_move = attack(player, hit_numb, hit_letter, player, hit_decks);

			if (ai_move) {
				ship_hitted = true;
				prev_numb = hit_numb;
				prev_let = hit_letter;

				if (killed_ships_check(player, hit_numb, hit_letter, hit_decks)) {
					ship_hitted = false;
					around_ship(player, hit_numb, hit_letter, hit_decks);
					player_ships--;

				}

			}
			else {
				player_move = true;
			}
			system("cls");
			board(player, ai, player_ships, ai_ships);


			if (is_win(player_ships, ai_ships)) break;
		}
	}
}
