#pragma once

#include "Data.h"

bool check(int player[10][10], int num_start, int let_start, int num_end, int let_end) {

	for (size_t i = num_start; i <= num_end; i++)
	{
		for (size_t j = let_start; j <= let_end; j++)
		{
			if (player[i][j] != 0) {
				return false;
			}
		}
	}

	return true;
}

int numb_letter(char lt) {

	char col[10]{ 'A', 'B', 'C', 'D', 'E', 'F','G','H', 'I', 'J' };

	for (size_t i = 0; i < 10; i++)
	{
		if (lt == col[i] || lt == col[i] - 32)
		{
			return i;
		}
	}

}

