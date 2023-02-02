#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

#include "bowler.h"
#include "game.h"
#include <nlohmann/json.hpp>

void output(std::vector<Bowler>& result);
void output_file_txt(std::vector<Bowler>& result);
void output_file_json(std::vector<Bowler>& result);


