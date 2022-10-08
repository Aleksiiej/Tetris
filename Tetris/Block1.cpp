#include "BlockBoard.hpp"
#include "Block1.hpp"

Block1::Block1(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept 
	: block1Array_{ {RectangleShape(),RectangleShape(),RectangleShape(),RectangleShape() } }, 
	  ptrToBlockBoard_(ptrToBlockBoard)
{
	block1Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID);
	block1Array_.at(0).setSize(Vector2f{ GRID, GRID });
	block1Array_.at(0).setFillColor(Color::Red);

	block1Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, GRID);
	block1Array_.at(1).setSize(Vector2f{ GRID, GRID });
	block1Array_.at(1).setFillColor(Color::Red);

	block1Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, 2 * GRID);
	block1Array_.at(2).setSize(Vector2f{ GRID, GRID });
	block1Array_.at(2).setFillColor(Color::Red);

	block1Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, 2 * GRID);
	block1Array_.at(3).setSize(Vector2f{ GRID, GRID });
	block1Array_.at(3).setFillColor(Color::Red);
}

const bool Block1::checkIfLost() const noexcept
{
	if (block1Array_.at(0).getPosition().y == GRID // TODO: Make this condition shorter
	  and ( ptrToBlockBoard_->getBoardArrayRef().at(gridToX(2)).at(gridToY(2)).getFillColor() == Color::Red
	  or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3)).at(gridToY(3)).getFillColor() == Color::Red))
	{
	   return false;
	}
	return true;
}

void Block1::fall() noexcept
{
	if (isFallingPossible())
	{
		for (int i = 0; i < 4; i++)
		{
			block1Array_.at(i).move(0, GRID);
		}
	}
}

const bool Block1::isFallingPossible() noexcept
{
	if (block1Array_.at(2).getPosition().y >= GRID * NUMBER_OF_ROWS and block1Array_.at(3).getPosition().y >= GRID * NUMBER_OF_ROWS)
	{
		for (int i = 0; i < 4; i++)
		{
		    ptrToBlockBoard_->setFillColor(gridToX(i + 1), gridToY(i), Color::Red);
		}
		setBLockAtStartingPosition();
		return false;
	}
	else if (ptrToBlockBoard_->getBoardArrayRef().at(gridToX(2)).at(gridToY(2) + 1).getFillColor() != Color::White
		     or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1).getFillColor() != Color::White)
	{
		for (int i = 0; i < 4; i++)
		{
			ptrToBlockBoard_->setFillColor(gridToX(i + 1), gridToY(i), Color::Red);
		}
		setBLockAtStartingPosition();
		return false;
	}
	return true;
}


void Block1::moveRight() noexcept
{
	if (isMoveRightPossible())
	{
		for (int i = 0; i < 4; i++)
		{
			block1Array_.at(i).move(GRID, 0);
		}
	}
}

const bool Block1::isMoveRightPossible() const noexcept
{
	if (block1Array_.at(1).getPosition().x >= GRID * NUMBER_OF_COLUMNS
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(1)).at(gridToY(1)).getFillColor() != Color::White
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3)).at(gridToY(3)).getFillColor() != Color::White)
	{
		return false;
	}
	return true;
}

void Block1::moveLeft() noexcept
{
	if (isMoveLeftPossible())
	{
		for (int i = 0; i < 4; i++)
		{
			block1Array_.at(i).move(-GRID, 0);
		}
	}
}

const bool Block1::isMoveLeftPossible() const noexcept
{
	if (block1Array_.at(0).getPosition().x <= GRID
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(0)).at(gridToY(0)).getFillColor() != Color::White
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(2)).at(gridToY(2)).getFillColor() != Color::White)
	{
		return false;
	}
	return true;
}

void Block1::moveDown() noexcept
{
	while (isFallingPossible())
	{
		for (int i = 0; i < 4; i++)
		{
			block1Array_.at(i).move(0, GRID);
		}
	}
}

const array<RectangleShape, 4>& Block1::getBlock1ArrayRef() const noexcept
{
	return block1Array_;
}

const uint8_t Block1::gridToX(uint8_t blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 1:
		return static_cast<uint8_t>((block1Array_.at(0).getPosition().x - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block1Array_.at(1).getPosition().x - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block1Array_.at(2).getPosition().x - GRID) / GRID);
	case 4:
		return static_cast<uint8_t>((block1Array_.at(3).getPosition().x - GRID) / GRID);
	default:
		return 0;
	}
}

const uint8_t Block1::gridToY(uint8_t blockNumber) const noexcept
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
		return 0;
	}
}

void Block1::setBLockAtStartingPosition() noexcept
{
	block1Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID);
	block1Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, GRID);
	block1Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, 2 * GRID);
	block1Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, 2 * GRID);
}
