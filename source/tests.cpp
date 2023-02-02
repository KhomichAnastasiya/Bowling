#include "tests.h"

void TestGeneralCase()
{
	std::vector<Frame> frames_1 = { {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0} };
	std::vector<Frame> frames_2 = { {1, 1},{1, 1},{1, 1},{1, 1},{1, 1},{1, 1},{1, 1},{1, 1},{1, 1},{1, 1} };

	std::vector<std::vector<Frame>> frames;
	frames.push_back(frames_1);
	frames.push_back(frames_2);

	Game game(2);
	game.play(frames);
	game.score(true);
	std::vector<Bowler> result = game.output_result();

	ASSERT_EQUAL(result[0].id, 1);
	ASSERT_EQUAL(result[1].id, 2);
	ASSERT_EQUAL(result[0].total, 0);
	ASSERT_EQUAL(result[1].total, 20);
}

void TestSpareAndStrikeInMiddle()
{
	std::vector<Frame> frames_1 = { {8, 2},{7, 1},{7, 0},{2, 0},{5, 5},{4, 4},{7, 2},{3, 0},{6, 3},{5, 4} };
	std::vector<Frame> frames_2 = { {7, 0},{6, 1},{6, 2},{10, -1},{6, 3},{10, -1},{3, 2},{6, 2},{5, 4},{8, 1} };

	std::vector<std::vector<Frame>> frames;
	frames.push_back(frames_1);
	frames.push_back(frames_2);

	Game game(2);
	game.play(frames);
	game.score(true);
	std::vector<Bowler> result = game.output_result();

	ASSERT_EQUAL(result[0].id, 1);
	ASSERT_EQUAL(result[1].id, 2);
	ASSERT_EQUAL(result[0].total, 86);
	ASSERT_EQUAL(result[1].total, 96);
}

void TestSpareInTheEnd()
{
	std::vector<Frame> frames_1 = { {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{8, 2} ,{5, -1} };
	std::vector<Frame> frames_2 = { {5, 0},{3, 6},{8, 1},{2, 5},{0, 5},{6, 1},{2, 1},{5, 2},{1, 0},{4, 6},{5, -1} };

	std::vector<std::vector<Frame>> frames;
	frames.push_back(frames_1);
	frames.push_back(frames_2);

	Game game(2);
	game.play(frames);
	game.score(true);
	std::vector<Bowler> result = game.output_result();

	ASSERT_EQUAL(result[0].id, 1);
	ASSERT_EQUAL(result[1].id, 2);
	ASSERT_EQUAL(result[0].total, 20);
	ASSERT_EQUAL(result[1].total, 73);
}

void TestStrikeInTheEnd()
{
	std::vector<Frame> frames_1 = { {0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{0, 0},{10, -1} ,{5, 2} };
	std::vector<Frame> frames_2 = { {5, 0},{3, 6},{8, 1},{2, 5},{0, 5},{6, 1},{2, 1},{5, 2},{1, 0},{10, -1},{2, 2} };

	std::vector<std::vector<Frame>> frames;
	frames.push_back(frames_1);
	frames.push_back(frames_2);

	Game game(2);
	game.play(frames);
	game.score(true);
	std::vector<Bowler> result = game.output_result();

	ASSERT_EQUAL(result[0].id, 1);
	ASSERT_EQUAL(result[1].id, 2);
	ASSERT_EQUAL(result[0].total, 24);
	ASSERT_EQUAL(result[1].total, 71);
}

void TestMaxScore()
{
	std::vector<Frame> frames_1 = {{10, -1},{10, -1},{10, -1},{10, -1},{10, -1},{10, -1},{10, -1},{10, -1},{10, -1},{10, -1} ,{10, 10}};
	std::vector<Frame> frames_2 = { {9, 1},{9, 1},{9, 1},{9, 1},{9, 1},{9, 1},{9, 1},{9, 1},{9, 1},{9, 1},{10, -1} };

	std::vector<std::vector<Frame>> frames;
	frames.push_back(frames_1);
	frames.push_back(frames_2);

	Game game(2);
	game.play(frames);
	game.score(true);
	std::vector<Bowler> result = game.output_result();

	ASSERT_EQUAL(result[0].id, 1);
	ASSERT_EQUAL(result[1].id, 2);
	ASSERT_EQUAL(result[0].total, 300);
	ASSERT_EQUAL(result[1].total, 191);
}

void TestBowling() {
	RUN_TEST(TestGeneralCase);
	RUN_TEST(TestSpareAndStrikeInMiddle);
	RUN_TEST(TestSpareInTheEnd);
	RUN_TEST(TestStrikeInTheEnd);
	RUN_TEST(TestMaxScore);
}