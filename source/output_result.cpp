#include "output_result.h"

void output(std::vector<Bowler>& result)
{
	for (const auto& bowler_result : result) {
		std::cout << "\nid = " << bowler_result.id << "\n";
		int num_frame = 1;
		for (const auto& frame : bowler_result.frames_) {
			std::cout << "Frame " << num_frame << ", ";
			std::cout << "ball 1: " << frame.first_roll_ << " pins\n";
			if (frame.second_roll_ != -1) {
				std::cout << "Frame " << num_frame << ", ";
				std::cout << "ball 2: " << frame.second_roll_ << " pins\n";
			}
			++num_frame;
		}
		std::cout << "TOTAL = " << bowler_result.total << "\n\n\n";
	}
}

void output_file_txt(std::vector<Bowler>& result)
{
	std::string filename = "result_game.txt";
	std::ofstream outFile;
	outFile.open(filename);

	if (!outFile.is_open()) {
		throw std::invalid_argument("Invalid file");
	}

	for (const auto& bowler_result : result) {
		outFile << "id = " << bowler_result.id << "\n";
		int num_frame = 1;
		for (const auto& frame : bowler_result.frames_) {
			outFile << "Frame " << num_frame << ", ";
			outFile << "ball 1: " << frame.first_roll_ << " pins\n";
			if (frame.second_roll_ != -1) {
				outFile << "Frame " << num_frame << ", ";
				outFile << "ball 2: " << frame.second_roll_ << " pins\n";
			}
			++num_frame;
		}
		outFile << "TOTAL = " << bowler_result.total << "\n\n\n";
	}
	outFile.close();
}

void output_file_json(std::vector<Bowler>& result)
{
	std::string filename = "result_game.json";
	std::ofstream outFile;
	outFile.open(filename);

	if (!outFile.is_open()) {
		throw std::invalid_argument("File is not found");
	}

	std::vector<int> first_roll;
	std::vector<int> second_roll;
	nlohmann::json json_obj;
	auto json_array = nlohmann::json::array();

	for (int bowler = 0; bowler < result.size(); ++bowler){
		
		json_obj["id"] = result[bowler].id;
		for (int frame = 0; frame < result[bowler].frames_.size(); ++frame){
			first_roll.push_back(result[bowler].frames_[frame].first_roll_);
			second_roll.push_back(result[bowler].frames_[frame].second_roll_);
		}
		json_obj["first_roll"] = first_roll;
		json_obj["second_roll"] = second_roll;
		first_roll.clear();
		second_roll.clear();
		json_obj["total"] = result[bowler].total;
		json_array.push_back(json_obj);
		json_obj.clear();
	}
	outFile << json_array;
	outFile.close();
}
