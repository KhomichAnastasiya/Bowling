#include <iostream>
#include <vector>
#include <conio.h>

#include "bowler.h"
#include "game.h"
#include "tests.h"
#include "output_result.h"
#include "input_result.h"

int code_press_key(char ch_press_key)
{
	return (int)ch_press_key;
}

bool file_is_exist(std::string filename)
{
	bool is_exist = false;
	std::ifstream file(filename.c_str());
	if (file.is_open())
		is_exist = true;
	file.close();
	return is_exist;
}

void main()
{
	TestBowling();
	std::vector<Bowler> result;

	int press_key = 0;
	while (press_key != 27) //Esc
	{
		std::cout << "\nNew game: Press N\n";
		std::cout << "Replay saved game: Press R\n";
		std::cout << "Exit: Press Esc\n";

		press_key = _getch();
		int key = code_press_key(press_key);
		bool flag_restart_game = false;

		switch (key){
		case('N'): case('n'): {
			int num_bowlers = 0;
			std::cout << "Enter the number of players from two to five: ";
			std::cin >> num_bowlers;
			if ((num_bowlers < 2) || (num_bowlers > 5)){
				while ((num_bowlers < 2) || (num_bowlers > 5)){
					std::cout << "Enter the number of players from two to five: ";
					std::cin >> num_bowlers;
				}
			}
			Game game(num_bowlers);
			game.play();
			game.score(flag_restart_game);
			result = game.output_result();
			std::cout << "\nSave result: Press s";
			output(result);
			game.win();
			std::cout << "\nSave result in a file: Press S\n\n";
			continue;
		}
		case('R'): case('r'): {
			if (file_is_exist("result_game.json") == false) {
				std::cout << "\nThere is no saved game\n";
				continue;
			}
			bool flag_restart_game = true;

			std::vector<std::vector<Frame>> bowler_frames = input_file_json();
			size_t num_bowlers = bowler_frames.size();
			Game game(static_cast<int>(num_bowlers));
			game.play(bowler_frames);
			game.score(flag_restart_game);
			result = game.output_result();
			output(result);
			game.win();
			std::cout << "\nSave result in a file: Press S\n";
			continue;
		}
		case('S'): case('s'): {
			output_file_txt(result);
			output_file_json(result);
			continue;
		}
		default: {
			continue;
		}
		}
	}
}