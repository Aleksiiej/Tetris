#include "BlockBoard.hpp"
#include "Block2.hpp"

#define SET_BLOCK1_STARTING_POSITION {\
block2Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID); \
block2Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2)* GRID + GRID, GRID); \
block2Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2)* GRID, 2 * GRID); \
block2Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2)* GRID + GRID, 2 * GRID); \
}

Block2::Block2(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept
	: block2Array_{ {RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }}} },
	ptrToBlockBoard_(ptrToBlockBoard)
{
	SET_BLOCK1_STARTING_POSITION;
	for_each(begin(block2Array_), end(block2Array_), [](auto& block) { block.setFillColor(Color::Red); });
}

const bool Block2::checkIfLost() const noexcept
{
	return true;
}

void Block2::fall() noexcept
{

}

const bool Block2::isFallingPossible() noexcept
{
	return true;
}

void Block2::moveRight() noexcept
{

}

const bool Block2::isMoveRightPossible() const noexcept
{
	return true;
}

void Block2::moveLeft() noexcept
{

}

const bool Block2::isMoveLeftPossible() const noexcept
{
	return true;
}

void Block2::moveDown() noexcept
{

}

const array<RectangleShape, 4>& Block2::getBlock1ArrayRef() const noexcept
{
	return block2Array_;
}

const uint8_t Block2::gridToX(const uint8_t& blockNumber) const noexcept
{

}

const uint8_t Block2::gridToY(const uint8_t& blockNumber) const noexcept
{

}
