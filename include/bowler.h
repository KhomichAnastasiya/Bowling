#pragma once

#include <vector>

struct Frame{
	int first_roll_;
	int second_roll_;
};

struct Bowler{
	int id;
	std::vector<Frame> frames_;
	int total;
};