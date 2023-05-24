#include <iostream>
#include <random>
#include <ctime>

#include "types.h"
#include "gamestate.h"
#include "moves.h"


using namespace std;



int main() {
	srand(unsigned(time(NULL)));

	GAMESTATE gamestate;
	Start_game(&gamestate);

	while (1) {
		getchar();
		Print_gamestate(&gamestate);
		Turn_stock(&gamestate.stock);
		Stock_to_foundation(&gamestate);
	}
	return 0;
}
