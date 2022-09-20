#pragma once

#include <array>
#include <algorithm>
#include "GlobalValues.hpp"

using namespace std;

class StateBoard
{
public:
	StateBoard();

//private:
	array<array<FieldState, NUMBER_OF_ROWS>, NUMBER_OF_COLUMNS> stateBoard_{};
};

