#pragma once

#include <array>
#include <algorithm>
#include "GlobalValues.hpp"
#include "Block.hpp"

using namespace std;

class BlockBoard
{
	friend class Block;
public:
	BlockBoard();

	//private:
	array<array<Block, NUMBER_OF_ROWS>, NUMBER_OF_COLUMNS> blockBoard_;
};

