#include "Block.hpp"
#include "blockBoard.hpp"

Block::Block(const int& blockX, const int& blockY, shared_ptr<BlockBoard>& ptrToBlockBoard) : ptrToBlockBoard_(ptrToBlockBoard)
{
	block_.setPosition(blockX, blockY);
	block_.setSize(Vector2f{ GRID, GRID });
	block_.setFillColor(Color::Red);
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

bool Block::isMoveRightPossible() const noexcept
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

bool Block::isMoveLeftPossible() const noexcept
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
