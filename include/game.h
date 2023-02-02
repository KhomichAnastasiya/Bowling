#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "bowler.h"

class Game
{
public:
	Game(int num_bowlers);
	void play();
	void play(std::vector<std::vector<Frame>> bowler_frames);
	void score(bool flag_restart_game);
	std::vector<Bowler> output_result();
	void win();
private:
	int num_bowlers_;
	int num_frames_;

	std::vector<Bowler> bowlers_;
	const int max_pins_ = 10;
	bool strike_end_ = false;
	bool spare_end_ = false;

	int roll(int pins);
	void extra_frame(int num_bowlers);
	int strike(int frame, int count_frames, int num_bowler);
	int spare(int frame, int count_frames, int num_bowler);

	void bowler_id() {
		for (int num_bowler = 0; num_bowler < num_bowlers_; ++num_bowler)
			bowlers_[num_bowler].id = num_bowler + 1;
	}
};