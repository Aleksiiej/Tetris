#include "BlockBoard.hpp"
#include "Block1.hpp"
#include "GlobalValues.hpp"

Block1::Block1(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept 
	: block1Array_{ {RectangleShape{Vector2f{ GRID, GRID }},
	                 RectangleShape{Vector2f{ GRID, GRID }}, 
	                 RectangleShape{Vector2f{ GRID, GRID }}, 
	                 RectangleShape{Vector2f{ GRID, GRID }}} },
	  ptrToBlockBoard_(ptrToBlockBoard)
{
	block1Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2)* GRID, GRID); 
	block1Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2)* GRID + GRID, GRID); 
	block1Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2)* GRID, 2 * GRID); 
	block1Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2)* GRID + GRID, 2 * GRID);
	for_each(begin(block1Array_), end(block1Array_), [](auto& block) { block.setFillColor(Color::Red); });
}

const bool Block1::checkIfLost() const noexcept
{
	if (block1Array_.at(0).getPosition().y == GRID
	  and ( ptrToBlockBoard_->getBoardArrayRef().at(gridToX(2)).at(gridToY(2)) == Color::Red
	  or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3)).at(gridToY(3)) == Color::Red))
	{
	   return false;
	}
	return true;
}

void Block1::fall() noexcept
{
		for_each(begin(block1Array_), end(block1Array_), [](auto& block) { block.move(0, GRID); });
}

const bool Block1::isFallingPossible() noexcept
{
	if (block1Array_.at(2).getPosition().y >= GRID * NUMBER_OF_ROWS and block1Array_.at(3).getPosition().y >= GRID * NUMBER_OF_ROWS)
	{
		setColorsInBlockBoard();
		return false;
	}
	else if (ptrToBlockBoard_->getBoardArrayRef().at(gridToX(2)).at(gridToY(2) + 1) != Color::White
		     or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1) != Color::White)
	{
		setColorsInBlockBoard();
		return false;
	}
	return true;
}

void Block1::setColorsInBlockBoard() const noexcept
{
	for (uint8_t i = 0; i < 4; i++)
	{
		ptrToBlockBoard_->setFillColor(gridToX(i), gridToY(i), block1Array_.at(0).getFillColor());
	}
}

void Block1::moveRight() noexcept
{
	if (isMoveRightPossible())
	{
		for_each(begin(block1Array_), end(block1Array_), [](auto& block) { block.move(GRID, 0); });
	}
}

const bool Block1::isMoveRightPossible() const noexcept
{
	if (block1Array_.at(1).getPosition().x >= GRID * NUMBER_OF_COLUMNS
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) != Color::White
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
	{
		return false;
	}
	return true;
}

void Block1::moveLeft() noexcept
{
	if (isMoveLeftPossible())
	{
		for_each(begin(block1Array_), end(block1Array_), [](auto& block) { block.move(-GRID, 0); });
	}
}

const bool Block1::isMoveLeftPossible() const noexcept
{
	if (block1Array_.at(0).getPosition().x <= GRID
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(0) - 1).at(gridToY(0)) != Color::White
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(2) - 1).at(gridToY(2)) != Color::White)
	{
		return false;
	}
	return true;
}

void Block1::moveDown() noexcept
{
	while (isFallingPossible())
	{
		for_each(begin(block1Array_), end(block1Array_), [](auto& block) { block.move(0, GRID); });
	}
}

const array<RectangleShape, 4>& Block1::getBlock1ArrayRef() const noexcept
{
	return block1Array_;
}

void Block1::setColor(const Color& color) noexcept
{
	for_each(begin(block1Array_), end(block1Array_), [&] (auto& block) { block.setFillColor(color); });
}

const bool Block1::isRotationPossible() const noexcept
{
	return false;
}

void Block1::rotate() noexcept
{
	return;
}

const uint8_t Block1::gridToX(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block1Array_.at(0).getPosition().x - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block1Array_.at(1).getPosition().x - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block1Array_.at(2).getPosition().x - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block1Array_.at(3).getPosition().x - GRID) / GRID);
	default:
		return 255;
	}
}

const uint8_t Block1::gridToY(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block1Array_.at(0).getPosition().y - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block1Array_.at(1).getPosition().y - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block1Array_.at(2).getPosition().y - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block1Array_.at(3).getPosition().y - GRID) / GRID);
	default:
		return 255;
	}
}
