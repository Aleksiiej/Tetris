#include "Block.hpp"
#include "blockBoard.hpp"

Block::Block(const int& blockX, const int& blockY, BlockBoard* ptrToBlockBoard) : ptrToBlockBoard_(ptrToBlockBoard)
{
	block_.setPosition(blockX, blockY);
	block_.setSize(size_);
	block_.setFillColor(Color::Red);
}

Block::Block()
{
	block_.setFillColor(Color::White);
}

void Block::fall()
{
	if (isFallingPossible())
	{
	   block_.move(0, GRID);
	}
}

bool Block::isFallingPossible()
{
	if (block_.getPosition().y >= GRID * NUMBER_OF_ROWS)
	{
		ptrToBlockBoard_->blockBoard_.at((block_.getPosition().x - GRID) / GRID).at((block_.getPosition().y - GRID) / GRID).block_.setFillColor(Color::Red);
		block_.setPosition(5 * GRID, 0);
		return false;
	}
	return true;
}

void Block::moveRight()
{
	if (isMoveRightPossible())
	{
	    block_.move(GRID, 0);
	}
}

bool Block::isMoveRightPossible()
{
	if (block_.getPosition().x >= GRID * NUMBER_OF_COLUMNS)
	{
		return false;
	}
	return true;
}

void Block::moveLeft()
{
	if (isMoveLeftPossible())
	{
	    block_.move(-GRID, 0);
	}
}

bool Block::isMoveLeftPossible()
{
	if (block_.getPosition().x <= GRID)
	{
		return false;
	}
	return true;
}

void Block::draw(RenderTarget& target, RenderStates states) const noexcept
{
	target.draw(block_, states);
}

void Block::updatePosition()
{
}