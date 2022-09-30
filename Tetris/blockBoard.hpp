#pragma once

#include <algorithm>
#include <array>
#include "GlobalValues.hpp"
#include "Block.hpp"

using namespace sf;
using namespace std;
using BoardArray = array<array<Block, NUMBER_OF_ROWS>, NUMBER_OF_COLUMNS>;

class BlockBoard
{
public:
	BlockBoard() noexcept;
	BlockBoard(const BlockBoard& other) = delete;
	BlockBoard(const BlockBoard&& other) = delete;
	~BlockBoard() = default;

	BoardArray& getBoardArrayRef() noexcept;
	void setFillColor(const uint8_t& x, const uint8_t& y, const Color& color) noexcept;

private:
	BoardArray blockBoard_;
};

