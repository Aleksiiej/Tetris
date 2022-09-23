#pragma once

#include <algorithm>
#include <array>
#include "GlobalValues.hpp"
#include "Block.hpp"

using namespace std;
using BoardArray = array<array<Block, NUMBER_OF_ROWS>, NUMBER_OF_COLUMNS>;

class BlockBoard
{
	friend class Block;
public:
	BlockBoard() noexcept;
	~BlockBoard() = default;

	BoardArray& getBoardArrayRef() noexcept;

private:
	BoardArray blockBoard_;
};

