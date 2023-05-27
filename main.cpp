#include "types.h"
#include "gamestate.h"
#include "moves.h"
#include "init.h"
#include "io.h"

#include <iostream>
#include <map>


using namespace std;

enum COMMANDS
{
	unrecognized_command, new_game, display_screen, help, quit, move_command, search_command
};


static map<string, COMMANDS> MAP_COMMANDS =
{
	{"newgame", new_game}, {"d", display_screen}, {"help", help}, {"quit", quit}, {"move", move_command}, {"search", search_command}
};



int main() {
	Init_all();

	cout << "Welcome to CGK, a command-line game tutorial by Nathanael Lu.\n";
	cout << "Type \"help\" for command options.\n";

	GAMESTATE gamestate;
	bool gamestarted = false;

	while (true) {
		string input;


		// get user / GUI input
		if (!getline(cin, input))
		{
			// continue the loop
			break;
		}

		// make sure input is available
		if (!input.length())
		{
			// continue the loop
			continue;
		}

		//Split the string into tokens to make it easier to work with
		vector<string> tokens = split_command(input);

		switch (MAP_COMMANDS[tokens[0]])
		{
		case (quit):
		{
			return 0;
		}
		case (help):
		{
			//Parse_help(tokens);
			break;
		}
		case (display_screen):
		{
			if (gamestarted) {
				Print_gamestate(&gamestate);
			}
			else {
				cout << "No game available!\n";
			}
			break;
		}
		case (new_game):
		{
			Start_game(&gamestate);
			gamestarted = true;
			break;
		}
		case (move_command):
		{
			if (gamestarted) {
				//Parse_move(tokens, &gamestate);
			}
			else {
				cout << "No game available!\n";
			}
			break;
		}
		case (search_command):
		{
			//Parse_search(input, &gamestate);
			break;
		}
		case (unrecognized_command):
		{
			cout << "Unknown command\n";
			break;
		}
		}
	}

	return 0;
}
