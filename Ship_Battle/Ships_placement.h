#pragma once

#include "Data.h"
#include "UI.h"
#include "Help_func.h"

void ship_placer(int player[10][10], void(*placement)(int player[10][10], int, int)) {

	int decks{ 4 }, ships{ 1 };

	while (decks > 0 && ships < 5)
	{
		placement(player, decks, ships);
		decks--;
		ships++;
	}
}

void space_located(int player[10][10], int decks, int number1, int number2, int col_start, int col_end, bool& ship_placed) {

	ship_placed = false;

	if (number1 == number2)
	{
		for (size_t i = 0; i < decks; i++)
		{
			player[number1 - 1][col_start + i] = decks;

			if (number1 != 1)
				player[number1 - 1 - 1][col_start + i] = 5;

			if (number1 != 10)
				player[number1 - 1 + 1][col_start + i] = 5;

		}
		ship_placed = true;

		if (col_start != 0) {
			player[number1 - 1][col_start - 1] = 5;

			if (number1 != 1)
				player[number1 - 1 - 1][col_start - 1] = 5;

			if (number1 != 10)
				player[number1 - 1 + 1][col_start - 1] = 5;
		}

		if (col_end != 9) {
			player[number1 - 1][col_end + 1] = 5;

			if (number1 != 1)
				player[number1 - 1 - 1][col_end + 1] = 5;

			if (number1 != 10)
				player[number1 - 1 + 1][col_end + 1] = 5;
		}


	}
	else if (col_start == col_end) {

		for (size_t i = 0; i < decks; i++)
		{
			player[number1 - 1 + i][col_start] = decks;

			if (col_start != 0)
				player[number1 - 1 + i][col_start - 1] = 5;

			if (col_start != 9)
				player[number1 - 1 + i][col_start + 1] = 5;

		}
		ship_placed = true;

		if (number1 != 1) {

			player[number1 - 1 - 1][col_start] = 5;

			if (col_start != 0)
				player[number1 - 1 - 1][col_start - 1] = 5;

			if (col_start != 9)
				player[number1 - 1 - 1][col_start + 1] = 5;
		}

		if (number2 != 10) {

			player[number2 - 1 + 1][col_start] = 5;

			if (col_start != 0)
				player[number2 - 1 + 1][col_start - 1] = 5;

			if (col_start != 9)
				player[number2 - 1 + 1][col_start + 1] = 5;

		}
	}
}


void ships_place(int field[10][10], int decks, int ships) {

	int count{};
	int start_numb{}, end_numb{}, start_let{}, end_let{};
	bool ship_placed{};

	while (count != ships)
	{
		do {
			start_numb = rand() % 10 + 1;
			end_numb = rand() % 10 + 1;
			start_let = rand() % 10;
			end_let = rand() % 10;
		} while (start_numb != end_numb && start_let != end_let);


		if (start_numb == end_numb && end_let - start_let != decks - 1) {

			while (end_let - start_let != decks - 1) {
				start_let = rand() % 10;
				end_let = rand() % 10;
			}
		}
		else if (end_let == start_let && end_numb - start_numb != decks - 1) {
			while (end_numb - start_numb != decks - 1) {
				start_numb = rand() % 10 + 1;
				end_numb = rand() % 10 + 1;
			}
		}

		if (check(field, start_numb - 1, start_let, end_numb - 1, end_let) != true) {
			continue;
		}

		space_located(field, decks, start_numb, end_numb, start_let, end_let, ship_placed);

		if (ship_placed) {
			count++;
		}
	}
}