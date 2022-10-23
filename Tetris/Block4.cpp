#include "BlockBoard.hpp"
#include "Block4.hpp"
#include "GlobalValues.hpp"

Block4::Block4(BlockBoard& blockBoardRef) noexcept
	: block4Array_{ {RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }}} },
	currentPosition_(Block4Position::FlatOnTop),
	blockBoardRef_(blockBoardRef)
{
	block4Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2) * GRID - GRID, GRID);
	block4Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID);
	block4Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, GRID);
	block4Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2) * GRID - GRID, 2 * GRID);
	for_each(begin(block4Array_), end(block4Array_), [](auto& block) { block.setFillColor(Color::Red); });
}

const bool Block4::checkIfLost() const noexcept
{
	if (block4Array_.at(0).getPosition().y == GRID
		and (blockBoardRef_.getBoardArrayRef().at(gridToX(0)).at(gridToY(0)) == Color::Red
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1)) == Color::Red
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(3)) == Color::Red
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3)) == Color::Red))
	{
		return false;
	}
	return true;
}

void Block4::fall() noexcept
{
	for_each(begin(block4Array_), end(block4Array_), [](auto& block) { block.move(0, GRID); });
}

const bool Block4::isFallingPossible() noexcept
{
	if (currentPosition_ == Block4Position::FlatOnTop)
	{
		if (block4Array_.at(3).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			setColorsInBlockBoard();
			return false;
		}
		else if (blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(2) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1) != Color::White)
		{
			setColorsInBlockBoard();
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block4Position::FlatOnRigth)
	{
		if (block4Array_.at(2).getPosition().y >= GRID * NUMBER_OF_ROWS)
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
	else if (currentPosition_ == Block4Position::FlatOnBottom)
	{
		if (block4Array_.at(1).getPosition().y >= GRID * NUMBER_OF_ROWS)
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
	else if (currentPosition_ == Block4Position::FlatOnLeft)
	{
		if (block4Array_.at(0).getPosition().y >= GRID * NUMBER_OF_ROWS)
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

void Block4::setColorsInBlockBoard() const noexcept
{
	for (uint8_t i = 0; i < 4; i++)
	{
		blockBoardRef_.setFillColor(gridToX(i), gridToY(i), block4Array_.at(0).getFillColor());
	}
}

void Block4::moveRight() noexcept
{
	if (isMoveRightPossible())
	{
		for_each(begin(block4Array_), end(block4Array_), [](auto& block) { block.move(GRID, 0); });
	}
}

const bool Block4::isMoveRightPossible() const noexcept
{
	if (currentPosition_ == Block4Position::FlatOnTop)
	{
		if (block4Array_.at(2).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block4Position::FlatOnRigth)
	{
		if (block4Array_.at(1).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) + 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(2)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block4Position::FlatOnBottom)
	{
		if (block4Array_.at(0).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) + 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block4Position::FlatOnLeft)
	{
		if (block4Array_.at(3).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	return false;
}

void Block4::moveLeft() noexcept
{
	if (isMoveLeftPossible())
	{
		for_each(begin(block4Array_), end(block4Array_), [](auto& block) { block.move(-GRID, 0); });
	}
}

const bool Block4::isMoveLeftPossible() const noexcept
{
	if (currentPosition_ == Block4Position::FlatOnTop)
	{
		if (block4Array_.at(0).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) - 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block4Position::FlatOnRigth)
	{
		if (block4Array_.at(3).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) - 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block4Position::FlatOnBottom)
	{
		if (block4Array_.at(2).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) - 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block4Position::FlatOnLeft)
	{
		if (block4Array_.at(1).getPosition().x <= GRID
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

void Block4::moveDown() noexcept
{
	while (isFallingPossible())
	{
		for_each(begin(block4Array_), end(block4Array_), [](auto& block) { block.move(0, GRID); });
	}
}

const bool Block4::isRotationPossible() const noexcept
{
	if (currentPosition_ == Block4Position::FlatOnTop)
	{
		if (blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) - 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1) - 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block4Position::FlatOnRigth)
	{
		if (blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1) - 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1)) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block4Position::FlatOnBottom)
	{
		if (blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1) + 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) - 1) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block4Position::FlatOnLeft)
	{
		if (blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1) + 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1) - 1) == Color::White
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 2).at(gridToY(1)) == Color::White)
		{
			return true;
		}
		else return false;
	}
	return false;
}

void Block4::rotate() noexcept
{
	if (isRotationPossible())
	{

		if (currentPosition_ == Block4Position::FlatOnTop)
		{
			block4Array_.at(0).setPosition(block4Array_.at(0).getPosition().x + GRID, block4Array_.at(0).getPosition().y - GRID);
			block4Array_.at(2).setPosition(block4Array_.at(2).getPosition().x - GRID, block4Array_.at(2).getPosition().y + GRID);
			block4Array_.at(3).setPosition(block4Array_.at(3).getPosition().x, block4Array_.at(3).getPosition().y - 2 * GRID);
			currentPosition_ = Block4Position::FlatOnRigth;
		}
		else if (currentPosition_ == Block4Position::FlatOnRigth)
		{
			block4Array_.at(0).setPosition(block4Array_.at(0).getPosition().x + GRID, block4Array_.at(0).getPosition().y + GRID);
			block4Array_.at(2).setPosition(block4Array_.at(2).getPosition().x - GRID, block4Array_.at(2).getPosition().y - GRID);
			block4Array_.at(3).setPosition(block4Array_.at(3).getPosition().x + 2 * GRID, block4Array_.at(3).getPosition().y);
			currentPosition_ = Block4Position::FlatOnBottom;
		}
		else if (currentPosition_ == Block4Position::FlatOnBottom)
		{
			block4Array_.at(0).setPosition(block4Array_.at(0).getPosition().x - GRID, block4Array_.at(0).getPosition().y + GRID);
			block4Array_.at(2).setPosition(block4Array_.at(2).getPosition().x + GRID, block4Array_.at(2).getPosition().y - GRID);
			block4Array_.at(3).setPosition(block4Array_.at(3).getPosition().x, block4Array_.at(3).getPosition().y + 2 * GRID);
			currentPosition_ = Block4Position::FlatOnLeft;
		}
		else if (currentPosition_ == Block4Position::FlatOnLeft)
		{
			block4Array_.at(0).setPosition(block4Array_.at(0).getPosition().x - GRID, block4Array_.at(0).getPosition().y - GRID);
			block4Array_.at(2).setPosition(block4Array_.at(2).getPosition().x + GRID, block4Array_.at(2).getPosition().y + GRID);
			block4Array_.at(3).setPosition(block4Array_.at(3).getPosition().x - 2 * GRID, block4Array_.at(3).getPosition().y);
			currentPosition_ = Block4Position::FlatOnTop;
		}
	}
}

const array<RectangleShape, 4>& Block4::getBlockArrayRef() const noexcept
{
	return block4Array_;
}

void Block4::setColor(const Color& color) noexcept
{
	for_each(begin(block4Array_), end(block4Array_), [&](auto& block) { block.setFillColor(color); });
}

const uint8_t Block4::gridToX(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block4Array_.at(0).getPosition().x - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block4Array_.at(1).getPosition().x - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block4Array_.at(2).getPosition().x - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block4Array_.at(3).getPosition().x - GRID) / GRID);
	default:
		return 255;
	}
}

const uint8_t Block4::gridToY(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block4Array_.at(0).getPosition().y - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block4Array_.at(1).getPosition().y - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block4Array_.at(2).getPosition().y - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block4Array_.at(3).getPosition().y - GRID) / GRID);
	default:
		return 255;
	}
}
