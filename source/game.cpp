#include "game.h"

Game::Game(int num_bowlers) : num_bowlers_(num_bowlers)
{
	Frame frame;
	frame.first_roll_ = -1;
	frame.second_roll_ = -1;
	num_frames_ = 10;
	bowlers_.resize(num_bowlers_);
	bowler_id();
}

int Game::roll(int pins)
{
	int knocked_down_pins = rand() % (pins + 1) + 0;
	return knocked_down_pins;
}

//Replay of the stored game
void Game::play(std::vector<std::vector<Frame>> bowler_frames)
{
	for (int bowler = 0; bowler < bowler_frames.size(); ++bowler){
		for (int frame = 0; frame < bowler_frames[bowler].size(); ++frame){
			int first_roll = bowler_frames[bowler][frame].first_roll_;
			int second_roll = bowler_frames[bowler][frame].second_roll_;
			bowlers_[bowler].frames_.push_back({ first_roll, second_roll });
		}
	}
}

//New game
void Game::play()
{
	for (int frame = 0; frame < num_frames_; ++frame){
		for (int bowler = 0; bowler < num_bowlers_; ++bowler){
			int roll1 = -1;
			int roll2 = -1;
			roll1 = roll(max_pins_);
			if ((frame == num_frames_ - 1) && (bowlers_[bowler].frames_[frame - 1].first_roll_ == max_pins_)) {
				roll2 = roll(max_pins_);
			}
			else {
				if (roll1 < max_pins_) {
					int remaining_pins = max_pins_ - roll1;
					roll2 = roll(remaining_pins);
				}
			}
			bowlers_[bowler].frames_.push_back({ roll1, roll2 });
		}
	}
}

//Used if strike or spare in the end
void Game::extra_frame(int num_bowler)
{
	int roll1 = roll(max_pins_);
	int roll2 = -1;
	if (strike_end_ == true) {
		roll2 = roll(max_pins_);
	}
	bowlers_[num_bowler].frames_.push_back({ roll1, roll2 });
}

int Game::strike(int frame, int count_frames, int num_bowler)
{
	int total = 10;
	if (frame == count_frames - 2){
		total += bowlers_[num_bowler].frames_[frame + 1].first_roll_;
		total += bowlers_[num_bowler].frames_[frame + 1].second_roll_;
		return total;
	}
	if (strike_end_ == true) {
		extra_frame(num_bowler);
		total += bowlers_[num_bowler].frames_[count_frames].first_roll_*2;
		total += bowlers_[num_bowler].frames_[count_frames].second_roll_*2;
		strike_end_ = false;
		return total;
	}
	total += bowlers_[num_bowler].frames_[frame + 1].first_roll_;
	if (bowlers_[num_bowler].frames_[frame + 1].second_roll_ != -1) {
		total += bowlers_[num_bowler].frames_[frame + 1].second_roll_;
	}
	else {
		total += bowlers_[num_bowler].frames_[frame + 2].first_roll_;
	}
	return total;
}

int Game::spare(int frame, int count_frames, int num_bowler)
{
	int total = 10;
	if (spare_end_ == true) {
		extra_frame(num_bowler);
		total += bowlers_[num_bowler].frames_[count_frames].first_roll_*2;
		spare_end_ = false;
		return total;
	}
	total += bowlers_[num_bowler].frames_[frame + 1].first_roll_;
	return total;
}

void Game::score(bool flag_restart_game)
{
	for (int bowler = 0; bowler < bowlers_.size(); ++bowler){
		int total = 0;
		int count_frames = bowlers_[bowler].frames_.size();
		for (int frame = 0; frame < count_frames; ++frame) {
			if ((frame <= count_frames - 2) && (bowlers_[bowler].frames_[frame].first_roll_ == max_pins_)){
				total += strike(frame, count_frames, bowler);
			}
			else if ((frame == count_frames - 1) && (bowlers_[bowler].frames_[frame].first_roll_ == max_pins_)){
				if (flag_restart_game == true) {
					break;
				}
				strike_end_ = true;
				total += strike(frame, count_frames, bowler);
			}
			else {
				if ((bowlers_[bowler].frames_[frame].first_roll_ + bowlers_[bowler].frames_[frame].second_roll_) == max_pins_){
					if (frame < count_frames - 1) {
						total += spare(frame, count_frames, bowler);
					}
					else {
						if (flag_restart_game == true) {
							break;
						}
						spare_end_ = true;
						total += spare(frame, count_frames, bowler);
					}
				}
				else {
					total += bowlers_[bowler].frames_[frame].first_roll_;
					if (bowlers_[bowler].frames_[frame].second_roll_ != -1){
						total += bowlers_[bowler].frames_[frame].second_roll_;
					}
				}
			}
		}
		bowlers_[bowler].total = total;
	}
}

void Game::win()
{
	sort(bowlers_.begin(), bowlers_.end(),
		[](const Bowler& bw_left, const Bowler& bw_right) {
			return bw_left.total > bw_right.total;
		});

	std::cout << "\nWinners: ";
	for (const auto& bowler : bowlers_) {
		if (bowler.id == bowlers_[0].id)
			std::cout << "id = " << bowler.id << '\n';
		}
}

std::vector<Bowler> Game::output_result()
{
	return bowlers_;
}

