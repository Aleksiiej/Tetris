#include "BlockBoard.hpp"
#include "Block5.hpp"
#include "GlobalValues.hpp"

Block5::Block5(BlockBoard& blockBoardRef) noexcept
	: block5Array_{ {RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }}} },
	currentPosition_(Block5Position::FlatOnTop),
	blockBoardRef_(blockBoardRef)
{
	block5Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2) * GRID - GRID, GRID);
	block5Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID);
	block5Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, GRID);
	block5Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, 2 * GRID);
	for_each(begin(block5Array_), end(block5Array_), [](auto& block) { block.setFillColor(Color::Red); });
}

const bool Block5::checkIfLost() const noexcept
{
	if (block5Array_.at(0).getPosition().y == GRID
		and (blockBoardRef_.getBoardArrayRef().at(gridToX(0)).at(gridToY(0)) == Color::Red
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1)) == Color::Red
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(3)) == Color::Red
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3)) == Color::Red))
	{
		return false;
	}
	return true;
}

void Block5::fall() noexcept
{
	for_each(begin(block5Array_), end(block5Array_), [](auto& block) { block.move(0, GRID); });
}

const bool Block5::isFallingPossible() noexcept
{
	if (currentPosition_ == Block5Position::FlatOnTop)
	{
		if (block5Array_.at(3).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			setColorsInBlockBoard();
			return false;
		}
		else if (blockBoardRef_.getBoardArrayRef().at(gridToX(0)).at(gridToY(0) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1) != Color::White)
		{
			setColorsInBlockBoard();
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block5Position::FlatOnRigth)
	{
		if (block5Array_.at(2).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			setColorsInBlockBoard();
			return false;
		}
		else if (blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(2) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1) != Color::White)
		{
			setColorsInBlockBoard();
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block5Position::FlatOnBottom)
	{
		if (block5Array_.at(1).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			setColorsInBlockBoard();
			return false;
		}
		else if (blockBoardRef_.getBoardArrayRef().at(gridToX(0)).at(gridToY(0) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(2) + 1) != Color::White)
		{
			setColorsInBlockBoard();
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block5Position::FlatOnLeft)
	{
		if (block5Array_.at(0).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			setColorsInBlockBoard();
			return false;
		}
		else if (blockBoardRef_.getBoardArrayRef().at(gridToX(0)).at(gridToY(0) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1) != Color::White)
		{
			setColorsInBlockBoard();
			return false;
		}
		return true;
	}
	return false;
}

void Block5::setColorsInBlockBoard() const noexcept
{
	for (uint8_t i = 0; i < 4; i++)
	{
		blockBoardRef_.setFillColor(gridToX(i), gridToY(i), block5Array_.at(0).getFillColor());
	}
}

void Block5::moveRight() noexcept
{
	if (isMoveRightPossible())
	{
		for_each(begin(block5Array_), end(block5Array_), [](auto& block) { block.move(GRID, 0); });
	}
}

const bool Block5::isMoveRightPossible() const noexcept
{
	if (currentPosition_ == Block5Position::FlatOnTop)
	{
		if (block5Array_.at(2).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block5Position::FlatOnRigth)
	{
		if (block5Array_.at(1).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) + 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(2)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block5Position::FlatOnBottom)
	{
		if (block5Array_.at(0).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) + 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block5Position::FlatOnLeft)
	{
		if (block5Array_.at(3).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) + 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	return false;
}

void Block5::moveLeft() noexcept
{
	if (isMoveLeftPossible())
	{
		for_each(begin(block5Array_), end(block5Array_), [](auto& block) { block.move(-GRID, 0); });
	}
}

const bool Block5::isMoveLeftPossible() const noexcept
{
	if (currentPosition_ == Block5Position::FlatOnTop)
	{
		if (block5Array_.at(0).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) - 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block5Position::FlatOnRigth)
	{
		if (block5Array_.at(3).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) - 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block5Position::FlatOnBottom)
	{
		if (block5Array_.at(2).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) - 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block5Position::FlatOnLeft)
	{
		if (block5Array_.at(1).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) - 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) - 1).at(gridToY(2)) != Color::White)
		{
			return false;
		}
		return true;
	}
	return false;
}

void Block5::moveDown() noexcept
{
	while (isFallingPossible())
	{
		for_each(begin(block5Array_), end(block5Array_), [](auto& block) { block.move(0, GRID); });
	}
}

const bool Block5::isRotationPossible() const noexcept
{
	if (block5Array_.at(0).getPosition().y >= GRID * NUMBER_OF_ROWS + GRID
		or block5Array_.at(1).getPosition().y >= GRID * NUMBER_OF_ROWS + GRID
		or block5Array_.at(2).getPosition().y >= GRID * NUMBER_OF_ROWS + GRID
		or block5Array_.at(3).getPosition().y == GRID * NUMBER_OF_ROWS + GRID
		or block5Array_.at(0).getPosition().y == GRID)
	{
     		return false;
	}
	else if (currentPosition_ == Block5Position::FlatOnTop)
	{
		if (block5Array_.at(1).getPosition().y < GRID * NUMBER_OF_ROWS
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) - 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1) + 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block5Position::FlatOnRigth)
	{
		if (block5Array_.at(1).getPosition().x > GRID
			and block5Array_.at(1).getPosition().x < GRID * NUMBER_OF_COLUMNS
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1)) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1) - 1) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block5Position::FlatOnBottom)
	{
		if (blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) - 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1) - 1) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block5Position::FlatOnLeft)
	{
		if (block5Array_.at(1).getPosition().x > GRID
			and block5Array_.at(1).getPosition().x < GRID * NUMBER_OF_COLUMNS
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1)) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1) + 1) == Color::White)
		{
			return true;
		}
		else return false;
	}
	return false;
}

void Block5::rotate() noexcept
{
	if (isRotationPossible())
	{
		if (currentPosition_ == Block5Position::FlatOnTop)
		{
			block5Array_.at(0).setPosition(block5Array_.at(0).getPosition().x + GRID, block5Array_.at(0).getPosition().y - GRID);
			block5Array_.at(2).setPosition(block5Array_.at(2).getPosition().x - GRID, block5Array_.at(2).getPosition().y + GRID);
			block5Array_.at(3).setPosition(block5Array_.at(3).getPosition().x - 2 * GRID, block5Array_.at(3).getPosition().y);
			currentPosition_ = Block5Position::FlatOnRigth;
		}
		else if (currentPosition_ == Block5Position::FlatOnRigth)
		{
			block5Array_.at(0).setPosition(block5Array_.at(0).getPosition().x + GRID, block5Array_.at(0).getPosition().y + GRID);
			block5Array_.at(2).setPosition(block5Array_.at(2).getPosition().x - GRID, block5Array_.at(2).getPosition().y - GRID);
			block5Array_.at(3).setPosition(block5Array_.at(3).getPosition().x, block5Array_.at(3).getPosition().y - 2 * GRID);
			currentPosition_ = Block5Position::FlatOnBottom;
		}
		else if (currentPosition_ == Block5Position::FlatOnBottom)
		{
			block5Array_.at(0).setPosition(block5Array_.at(0).getPosition().x - GRID, block5Array_.at(0).getPosition().y + GRID);
			block5Array_.at(2).setPosition(block5Array_.at(2).getPosition().x + GRID, block5Array_.at(2).getPosition().y - GRID);
			block5Array_.at(3).setPosition(block5Array_.at(3).getPosition().x + 2 * GRID, block5Array_.at(3).getPosition().y);
			currentPosition_ = Block5Position::FlatOnLeft;
		}
		else if (currentPosition_ == Block5Position::FlatOnLeft)
		{
			block5Array_.at(0).setPosition(block5Array_.at(0).getPosition().x - GRID, block5Array_.at(0).getPosition().y - GRID);
			block5Array_.at(2).setPosition(block5Array_.at(2).getPosition().x + GRID, block5Array_.at(2).getPosition().y + GRID);
			block5Array_.at(3).setPosition(block5Array_.at(3).getPosition().x, block5Array_.at(3).getPosition().y + 2 * GRID);
			currentPosition_ = Block5Position::FlatOnTop;
		}
	}
}

const array<RectangleShape, 4>& Block5::getBlockArrayRef() const noexcept
{
	return block5Array_;
}

void Block5::setColor(const Color& color) noexcept
{
	for_each(begin(block5Array_), end(block5Array_), [&](auto& block) { block.setFillColor(color); });
}

const uint8_t Block5::gridToX(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block5Array_.at(0).getPosition().x - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block5Array_.at(1).getPosition().x - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block5Array_.at(2).getPosition().x - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block5Array_.at(3).getPosition().x - GRID) / GRID);
	default:
		return 255;
	}
}

const uint8_t Block5::gridToY(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block5Array_.at(0).getPosition().y - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block5Array_.at(1).getPosition().y - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block5Array_.at(2).getPosition().y - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block5Array_.at(3).getPosition().y - GRID) / GRID);
	default:
		return 255;
	}
}
