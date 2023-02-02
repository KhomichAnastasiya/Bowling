#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "bowler.h"
#include "game.h"

template <typename T, typename U>
void AssertEqualImpl(const T& t, const U& u, const std::string& t_str, const std::string& u_str, const std::string& file,
	const std::string& func, unsigned line, const std::string& hint) {
	if (t != u) {
		std::cerr << std::boolalpha;
		std::cerr << file << "(" << line << "): " << func << ": ";
		std::cerr << "ASSERT_EQUAL(" << t_str << ", " << u_str << ") failed: ";
		std::cerr << t << " != " << u << ".";
		if (!hint.empty()) {
			std::cerr << " Hint: " << hint;
		}
		std::cerr << std::endl;
		abort();
	}
}

template <typename TFunc>
void RunTestImpl(TFunc func_name_test, const std::string& func_name) {
	std::cerr << func_name << " OK" << std::endl;
	func_name_test();
}

#define ASSERT_EQUAL(a, b) AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, "")
#define RUN_TEST(func) RunTestImpl(func, #func)

void TestGeneralCase();
void TestSpareAndStrikeInMiddle();
void TestSpareInTheEnd();
void TestStrikeInTheEnd();
void TestMaxScore();
void TestBowling();