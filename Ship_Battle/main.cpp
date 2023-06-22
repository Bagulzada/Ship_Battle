#include"Data.h"
#include"UI.h"
#include"Help_func.h"
#include"Mechanicks.h"
#include"Ships_placement.h"

using namespace std;

int main() {

	srand(time(nullptr));

	int player[10][10]{};
	int ai[10][10]{};
	int player_ship{ 10 };
	int ai_ship{ 10 };
	us menuItem = 0;

	const char* startMenu[] = {
		"	New Game",
		"	Exit"
	};
	system("cls");
	intro();

	menuItem = menu(startMenu, 2);
	system("cls");

	switch (menuItem)
	{
	case 1:
		ship_placer(player, ships_place);
		break;
	case 2:
		return 0;
	}

	system("cls");
	board(player, ai, player_ship, ai_ship);
	starter(player, ai, player_ship, ai_ship);

}