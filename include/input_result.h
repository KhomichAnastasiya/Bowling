#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

#include "bowler.h"
#include "game.h"
#include <nlohmann/json.hpp>

std::vector<std::vector<Frame>> input_file_json();
