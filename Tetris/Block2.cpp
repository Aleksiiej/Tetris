#include "BlockBoard.hpp"
#include "Block2.hpp"
#include "GlobalValues.hpp"

Block2::Block2(BlockBoard& blockBoardRef) noexcept 
	: block2Array_{ {RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }}} },
	currentPosition_(Block2Position::Horizontal),
	blockBoardRef_(blockBoardRef)
{
	block2Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2)* GRID - GRID, GRID);
	block2Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2)* GRID, GRID);
	block2Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2)* GRID + GRID, GRID);
	block2Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2)* GRID + 2 * GRID, GRID);
	for_each(begin(block2Array_), end(block2Array_), [](auto& block) { block.setFillColor(Color::Red); });
}

const bool Block2::checkIfLost() const noexcept
{
	if (block2Array_.at(0).getPosition().y == GRID
		and ( blockBoardRef_.getBoardArrayRef().at(gridToX(0)).at(gridToY(0)) == Color::Red
		or blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1)) == Color::Red
		or blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(3)) == Color::Red
	    or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3)) == Color::Red ))	
	{
		return false;
	}
	return true;
}

void Block2::fall() noexcept
{
		for_each(begin(block2Array_), end(block2Array_), [](auto& block) { block.move(0, GRID); });
}

const bool Block2::isFallingPossible() noexcept
{
	if (currentPosition_ == Block2Position::Horizontal)
	{
		if (block2Array_.at(0).getPosition().y >= GRID * NUMBER_OF_ROWS or block2Array_.at(3).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			setColorsInBlockBoard();
			return false;
		}
		else if (blockBoardRef_.getBoardArrayRef().at(gridToX(0)).at(gridToY(0) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(2) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1) != Color::White)
		{
			setColorsInBlockBoard();
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block2Position::Vertical)
	{
		if (block2Array_.at(3).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			setColorsInBlockBoard();
			return false;
		}
		else if (blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1) != Color::White)
		{
			setColorsInBlockBoard();
			return false;
		}
		return true;
	}
	else return false;
}

void Block2::setColorsInBlockBoard() const noexcept
{
	for (uint8_t i = 0; i < 4; i++)
	{
		blockBoardRef_.setFillColor(gridToX(i), gridToY(i), block2Array_.at(0).getFillColor());
	}
}

void Block2::moveRight() noexcept
{
	if (isMoveRightPossible())
	{
		for_each(begin(block2Array_), end(block2Array_), [](auto& block) { block.move(GRID, 0); });
	}
}

const bool Block2::isMoveRightPossible() const noexcept
{
	if (currentPosition_ == Block2Position::Horizontal)
	{
		if (block2Array_.at(3).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block2Position::Vertical)
	{
		if (block2Array_.at(3).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) + 1).at(gridToY(3)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(3)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(3)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else return false;
}

void Block2::moveLeft() noexcept
{
	if (isMoveLeftPossible())
	{
		for_each(begin(block2Array_), end(block2Array_), [](auto& block) { block.move(-GRID, 0); });
	}
}

const bool Block2::isMoveLeftPossible() const noexcept
{
	if (currentPosition_ == Block2Position::Horizontal)
	{
		if (block2Array_.at(0).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block2Position::Vertical)
	{
		if (block2Array_.at(3).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) - 1).at(gridToY(3)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(3)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) - 1).at(gridToY(3)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else return false;
}

void Block2::moveDown() noexcept
{
	while (isFallingPossible())
	{
		for_each(begin(block2Array_), end(block2Array_), [](auto& block) { block.move(0, GRID); });
	}
}

const bool Block2::isRotationPossible() const noexcept
{
	if (currentPosition_ == Block2Position::Horizontal)
	{
		if (block2Array_.at(1).getPosition().y > GRID
			and block2Array_.at(1).getPosition().y < GRID * NUMBER_OF_ROWS - GRID
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) - 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 2) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block2Position::Vertical)
	{
		if (block2Array_.at(1).getPosition().x > GRID
			and block2Array_.at(1).getPosition().x < GRID * NUMBER_OF_COLUMNS - GRID
			and block2Array_.at(1).getPosition().y > GRID
			and block2Array_.at(1).getPosition().y < GRID * NUMBER_OF_ROWS - GRID
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1)) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 2).at(gridToY(1)) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else return false;
}

void Block2::rotate() noexcept
{
	if (isRotationPossible())
	{
		if (currentPosition_ == Block2Position::Horizontal)
		{
			block2Array_.at(0).setPosition(block2Array_.at(0).getPosition().x + GRID, block2Array_.at(0).getPosition().y - GRID);
			block2Array_.at(2).setPosition(block2Array_.at(2).getPosition().x - GRID, block2Array_.at(2).getPosition().y + GRID);
			block2Array_.at(3).setPosition(block2Array_.at(3).getPosition().x - 2 * GRID, block2Array_.at(3).getPosition().y + 2 * GRID);
			currentPosition_ = Block2Position::Vertical;
		}
		else if (currentPosition_ == Block2Position::Vertical)
		{ 
			block2Array_.at(0).setPosition(block2Array_.at(0).getPosition().x - GRID, block2Array_.at(0).getPosition().y + GRID);
			block2Array_.at(2).setPosition(block2Array_.at(2).getPosition().x + GRID, block2Array_.at(2).getPosition().y - GRID);
			block2Array_.at(3).setPosition(block2Array_.at(3).getPosition().x + 2 * GRID, block2Array_.at(3).getPosition().y - 2 * GRID);
			currentPosition_ = Block2Position::Horizontal;
		}
	}
}

const array<RectangleShape, 4>& Block2::getBlockArrayRef() const noexcept
{
	return block2Array_;
}

void Block2::setColor(const Color& color) noexcept
{
	for_each(begin(block2Array_), end(block2Array_), [&](auto& block) { block.setFillColor(color); });
}

const uint8_t Block2::gridToX(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block2Array_.at(0).getPosition().x - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block2Array_.at(1).getPosition().x - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block2Array_.at(2).getPosition().x - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block2Array_.at(3).getPosition().x - GRID) / GRID);
	default:
		return 255;
	}
}

const uint8_t Block2::gridToY(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block2Array_.at(0).getPosition().y - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block2Array_.at(1).getPosition().y - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block2Array_.at(2).getPosition().y - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block2Array_.at(3).getPosition().y - GRID) / GRID);
	default:
		return 255;
	}
}
