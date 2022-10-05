#include "Chunk1.hpp"
#include "BlockBoard.hpp"

Chunk1::Chunk1(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept : ptrToBlockBoard_(ptrToBlockBoard)
{
	block1_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID);
	block1_.setSize(Vector2f{ GRID, GRID });
	block1_.setFillColor(Color::Red);

	block2_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, GRID);
	block2_.setSize(Vector2f{ GRID, GRID });
	block2_.setFillColor(Color::Red);

	block3_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID, 2 * GRID);
	block3_.setSize(Vector2f{ GRID, GRID });
	block3_.setFillColor(Color::Red);

	block4_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, 2 * GRID);
	block4_.setSize(Vector2f{ GRID, GRID });
	block4_.setFillColor(Color::Red);
}

const bool Chunk1::checkIfLost() const noexcept
{
	if (block1_.getPosition().y == GRID // TODO: Make this condition shorter
	  and ( ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3)).at(gridToY(3)).getBlockRef().getFillColor() == Color::Red
	  or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(4)).at(gridToY(4)).getBlockRef().getFillColor() == Color::Red))
	{
	   return false;
	}
	return true;
}

void Chunk1::fall() noexcept
{
	if (isFallingPossible())
	{
		block1_.move(0, GRID);
		block2_.move(0, GRID);
		block3_.move(0, GRID);
		block4_.move(0, GRID);
	}
}

const bool Chunk1::isFallingPossible() noexcept
{
	if (block3_.getPosition().y >= GRID * NUMBER_OF_ROWS and block4_.getPosition().y >= GRID * NUMBER_OF_ROWS)
	{
		for (int i = 1; i < 5; i++)
		{
		    ptrToBlockBoard_->setFillColor(gridToX(i), gridToY(i), Color::Red);
		}
		block1_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID);
		block2_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, GRID);
		block3_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID, 2 * GRID);
		block4_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, 2 * GRID);
		return false;
	}
	else if (ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1).getBlockRef().getFillColor() != Color::White
		     or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(4)).at(gridToY(4) + 1).getBlockRef().getFillColor() != Color::White)
	{
		for (int i = 1; i < 5; i++)
		{
			ptrToBlockBoard_->setFillColor(gridToX(i), gridToY(i), Color::Red);
		}
		block1_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID);
		block2_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, GRID);
		block3_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID, 2 * GRID);
		block4_.setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, 2 * GRID);
		return false;
	}
	return true;
}


void Chunk1::moveRight() noexcept
{
	if (isMoveRightPossible())
	{
		block1_.move(GRID, 0);
		block2_.move(GRID, 0);
		block3_.move(GRID, 0);
		block4_.move(GRID, 0);
	}
}

const bool Chunk1::isMoveRightPossible() const noexcept
{
	if (block2_.getPosition().x >= GRID * NUMBER_OF_COLUMNS
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(2) + 1).at(gridToY(2)).getBlockRef().getFillColor() != Color::White
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(4) + 1).at(gridToY(4)).getBlockRef().getFillColor() != Color::White)
	{
		return false;
	}
	return true;
}

void Chunk1::moveLeft() noexcept
{
	if (isMoveLeftPossible())
	{
		block1_.move(-GRID, 0);
		block2_.move(-GRID, 0);
		block3_.move(-GRID, 0);
		block4_.move(-GRID, 0);
	}
}

const bool Chunk1::isMoveLeftPossible() const noexcept
{
	if (block1_.getPosition().x <= GRID
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(1) - 1).at(gridToY(1)).getBlockRef().getFillColor() != Color::White
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3) - 1).at(gridToY(3)).getBlockRef().getFillColor() != Color::White)
	{
		return false;
	}
	return true;
}

void Chunk1::moveDown() noexcept
{
	while (isFallingPossible())
	{
		block1_.move(0, GRID);
		block2_.move(0, GRID);
		block3_.move(0, GRID);
		block4_.move(0, GRID);
	}
}

RectangleShape& Chunk1::getBlock1Ref() noexcept
{
	return block1_;
}

RectangleShape& Chunk1::getBlock2Ref() noexcept
{
	return block2_;
}

RectangleShape& Chunk1::getBlock3Ref() noexcept
{
	return block3_;
}

RectangleShape& Chunk1::getBlock4Ref() noexcept
{
	return block4_;
}


const uint8_t Chunk1::gridToX(uint8_t blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 1:
		return static_cast<uint8_t>((block1_.getPosition().x - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block2_.getPosition().x - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block3_.getPosition().x - GRID) / GRID);
	case 4:
		return static_cast<uint8_t>((block4_.getPosition().x - GRID) / GRID);
	default:
		return 0;
	}
}

const uint8_t Chunk1::gridToY(uint8_t blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 1:
		return static_cast<uint8_t>((block1_.getPosition().y - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block2_.getPosition().y - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block3_.getPosition().y - GRID) / GRID);
	case 4:
		return static_cast<uint8_t>((block4_.getPosition().y - GRID) / GRID);
	default:
		return 0;
	}
}