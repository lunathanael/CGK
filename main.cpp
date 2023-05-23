#include <iostream>
#include <random>
#include <ctime>

#include "types.h"
#include "gamestate.h"


using namespace std;



int main() {
	srand(unsigned(time(NULL)));

	GAMESTATE gamestate;
	Start_game(&gamestate);
	Print_gamestate(&gamestate);
	return 0;
}
