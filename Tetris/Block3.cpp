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
	block3Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2) * GRID - GRID, GRID);
	block3Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID);
	block3Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, GRID);
	block3Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, 2 * GRID);
	for_each(begin(block3Array_), end(block3Array_), [](auto& block) { block.setFillColor(Color::Red); });
}

const bool Block3::checkIfLost() const noexcept
{
	if (block3Array_.at(0).getPosition().y == GRID
		and (blockBoardRef_.getBoardArrayRef().at(gridToX(0)).at(gridToY(0)) == Color::Red
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1)) == Color::Red
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(3)) == Color::Red
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3)) == Color::Red))
	{
		return false;
	}
	return true;
}

void Block3::fall() noexcept
{
	for_each(begin(block3Array_), end(block3Array_), [](auto& block) { block.move(0, GRID); });
}

const bool Block3::isFallingPossible() noexcept
{
	if (currentPosition_ == Block3Position::FlatOnTop)
	{
		if (block3Array_.at(3).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			setColorsInBlockBoard();
			return false;
		}
		else if (blockBoardRef_.getBoardArrayRef().at(gridToX(0)).at(gridToY(0) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(2) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1) != Color::White)
		{
			setColorsInBlockBoard();
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block3Position::FlatOnRigth)
	{
		if (block3Array_.at(2).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			setColorsInBlockBoard();
			return false;
		}
		else if (blockBoardRef_.getBoardArrayRef().at(gridToX(2)).at(gridToY(2) + 1) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1) != Color::White) //TODO
		{
			setColorsInBlockBoard();
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block3Position::FlatOnBottom)
	{
		if (block3Array_.at(0).getPosition().y >= GRID * NUMBER_OF_ROWS)
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
	else if (currentPosition_ == Block3Position::FlatOnLeft)
	{
		if (block3Array_.at(0).getPosition().y >= GRID * NUMBER_OF_ROWS)
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
	if (currentPosition_ == Block3Position::FlatOnTop)
	{
		if (block3Array_.at(2).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block3Position::FlatOnRigth)
	{
		if (block3Array_.at(2).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) + 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(2)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block3Position::FlatOnBottom)
	{
		if (block3Array_.at(0).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) + 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block3Position::FlatOnLeft)
	{
		if (block3Array_.at(3).getPosition().x >= GRID * NUMBER_OF_COLUMNS
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) + 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) + 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
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
	if (currentPosition_ == Block3Position::FlatOnTop)
	{
		if (block3Array_.at(0).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) - 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block3Position::FlatOnRigth)
	{
		if (block3Array_.at(3).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(0) - 1).at(gridToY(0)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) - 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block3Position::FlatOnBottom)
	{
		if (block3Array_.at(2).getPosition().x <= GRID
			or blockBoardRef_.getBoardArrayRef().at(gridToX(2) - 1).at(gridToY(2)) != Color::White
			or blockBoardRef_.getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)) != Color::White)
		{
			return false;
		}
		return true;
	}
	else if (currentPosition_ == Block3Position::FlatOnLeft)
	{
		if (block3Array_.at(1).getPosition().x <= GRID
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

void Block3::moveDown() noexcept
{
	while (isFallingPossible())
	{
		for_each(begin(block3Array_), end(block3Array_), [](auto& block) { block.move(0, GRID); });
	}
}

const bool Block3::isRotationPossible() const noexcept
{
	if (block3Array_.at(0).getPosition().y == GRID)
	{
       		return false;
	}
	else if (currentPosition_ == Block3Position::FlatOnTop)
	{
		if (block3Array_.at(1).getPosition().y < GRID * NUMBER_OF_ROWS - GRID
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) - 1) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block3Position::FlatOnRigth)
	{
		if (block3Array_.at(1).getPosition().x < GRID * NUMBER_OF_COLUMNS
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) + 1).at(gridToY(1)) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block3Position::FlatOnBottom)
	{
		if (block3Array_.at(1).getPosition().y < GRID * NUMBER_OF_ROWS - GRID
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1)).at(gridToY(1) - 1) == Color::White)
		{
			return true;
		}
		else return false;
	}
	else if (currentPosition_ == Block3Position::FlatOnLeft)
	{
		if (block3Array_.at(1).getPosition().x > GRID
			and blockBoardRef_.getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1)) == Color::White)
		{
			return true;
		}
		else return false;
	}
	return false;
}

void Block3::rotate() noexcept
{
	if (isRotationPossible())
	{

		if (currentPosition_ == Block3Position::FlatOnTop)
		{
			block3Array_.at(0).setPosition(block3Array_.at(0).getPosition().x + GRID, block3Array_.at(0).getPosition().y - GRID);
			block3Array_.at(2).setPosition(block3Array_.at(2).getPosition().x - GRID, block3Array_.at(2).getPosition().y + GRID);
			block3Array_.at(3).setPosition(block3Array_.at(3).getPosition().x - GRID, block3Array_.at(3).getPosition().y - GRID);
			currentPosition_ = Block3Position::FlatOnRigth;
		}
		else if (currentPosition_ == Block3Position::FlatOnRigth)
		{
			block3Array_.at(0).setPosition(block3Array_.at(0).getPosition().x + GRID, block3Array_.at(0).getPosition().y + GRID);
			block3Array_.at(2).setPosition(block3Array_.at(2).getPosition().x - GRID, block3Array_.at(2).getPosition().y - GRID);
			block3Array_.at(3).setPosition(block3Array_.at(3).getPosition().x + GRID, block3Array_.at(3).getPosition().y - GRID);
			currentPosition_ = Block3Position::FlatOnBottom;
		}
		else if (currentPosition_ == Block3Position::FlatOnBottom)
		{
			block3Array_.at(0).setPosition(block3Array_.at(0).getPosition().x - GRID, block3Array_.at(0).getPosition().y + GRID);
			block3Array_.at(2).setPosition(block3Array_.at(2).getPosition().x + GRID, block3Array_.at(2).getPosition().y - GRID);
			block3Array_.at(3).setPosition(block3Array_.at(3).getPosition().x + GRID, block3Array_.at(3).getPosition().y + GRID);
			currentPosition_ = Block3Position::FlatOnLeft;
		}
		else if (currentPosition_ == Block3Position::FlatOnLeft)
		{
			block3Array_.at(0).setPosition(block3Array_.at(0).getPosition().x - GRID, block3Array_.at(0).getPosition().y - GRID);
			block3Array_.at(2).setPosition(block3Array_.at(2).getPosition().x + GRID, block3Array_.at(2).getPosition().y + GRID);
			block3Array_.at(3).setPosition(block3Array_.at(3).getPosition().x - GRID, block3Array_.at(3).getPosition().y + GRID);
			currentPosition_ = Block3Position::FlatOnTop;
		}
	}
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
