#include "BlockBoard.hpp"
#include "Block3.hpp"
#include "GlobalValues.hpp"

Block3::Block3(BlockBoard& blockBoardRef) noexcept
	: block3Array_{ {RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }}} },
	currentPosition_(Block3Position::FlatOnTop),
	blockBoardRef_(blockBoardRef)
{
	block3Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2)* GRID - GRID, GRID);
	block3Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2)* GRID, GRID);
	block3Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2)* GRID + GRID, GRID);
	block3Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2)* GRID + 2 * GRID, GRID);
	for_each(begin(block3Array_), end(block3Array_), [](auto& block) { block.setFillColor(Color::Red); });
}

const bool Block3::checkIfLost() const noexcept
{
	return false;;
}

void Block3::fall() noexcept
{
	for_each(begin(block3Array_), end(block3Array_), [](auto& block) { block.move(0, GRID); });
}

const bool Block3::isFallingPossible() noexcept
{
	return false;
}

void Block3::setColorsInBlockBoard() const noexcept
{
	for (uint8_t i = 0; i < 4; i++)
	{
		blockBoardRef_.setFillColor(gridToX(i), gridToY(i), block3Array_.at(0).getFillColor());
	}
}

void Block3::moveRight() noexcept
{
	if (isMoveRightPossible())
	{
		for_each(begin(block3Array_), end(block3Array_), [](auto& block) { block.move(GRID, 0); });
	}
}

const bool Block3::isMoveRightPossible() const noexcept
{
	return false;
}

void Block3::moveLeft() noexcept
{
	if (isMoveLeftPossible())
	{
		for_each(begin(block3Array_), end(block3Array_), [](auto& block) { block.move(-GRID, 0); });
	}
}

const bool Block3::isMoveLeftPossible() const noexcept
{
	return false;
}

void Block3::moveDown() noexcept
{
	while (isFallingPossible())
	{
		for_each(begin(block3Array_), end(block3Array_), [](auto& block) { block.move(0, GRID); });
	}
}

const bool Block3::isRotationPossible() const noexcept
{
	return false;
}

void Block3::rotate() noexcept
{

}

const array<RectangleShape, 4>& Block3::getBlockArrayRef() const noexcept
{
	return block3Array_;
}

void Block3::setColor(const Color& color) noexcept
{
	for_each(begin(block3Array_), end(block3Array_), [&](auto& block) { block.setFillColor(color); });
}

const uint8_t Block3::gridToX(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block3Array_.at(0).getPosition().x - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block3Array_.at(1).getPosition().x - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block3Array_.at(2).getPosition().x - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block3Array_.at(3).getPosition().x - GRID) / GRID);
	default:
		return 255;
	}
}

const uint8_t Block3::gridToY(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block3Array_.at(0).getPosition().y - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block3Array_.at(1).getPosition().y - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block3Array_.at(2).getPosition().y - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block3Array_.at(3).getPosition().y - GRID) / GRID);
	default:
		return 255;
	}
}
