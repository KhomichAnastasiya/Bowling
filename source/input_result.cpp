#include "input_result.h"

std::vector<std::vector<Frame>> input_file_json()
{
	nlohmann::json json_array;
	std::string filename = "result_game.json";
	std::ifstream inFile(filename);
	inFile.open(filename);

	if (!inFile.is_open()) {
		throw std::invalid_argument("File is not found");
	}

	inFile >> json_array;
	inFile.close();

	std::vector<Frame> frames;
	std::vector<std::vector<Frame>> all_frames;

	for (int bowler = 0; bowler < json_array.size(); ++bowler) {
		for (int frame = 0; frame < json_array[bowler]["first_roll"].size(); ++frame) {
			frames.push_back({ json_array[bowler]["first_roll"][frame], json_array[bowler]["second_roll"][frame] });
		}
		all_frames.push_back(frames);
		frames.clear();
	}
	return all_frames;
}