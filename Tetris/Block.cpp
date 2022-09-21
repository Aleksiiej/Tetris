#include "Block.hpp"
#include "BlockBoard.hpp"

Block::Block(const float& blockX, const float& blockY, const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept : ptrToBlockBoard_(ptrToBlockBoard)
{
	block_.setPosition(blockX, blockY);
	block_.setSize(Vector2f{ GRID, GRID });
	block_.setFillColor(Color::Red);
}

void Block::fall() noexcept
{
	if (isFallingPossible())
	{
	   block_.move(0, GRID);
	}
}

bool Block::isFallingPossible() noexcept
{
	if (block_.getPosition().y >= GRID * NUMBER_OF_ROWS)
	{
		ptrToBlockBoard_->blockBoard_.at((block_.getPosition().x - GRID) / GRID).at((block_.getPosition().y - GRID) / GRID).block_.setFillColor(Color::Red);
		block_.setPosition(5 * GRID, GRID);
		return false;
	}
	else if (ptrToBlockBoard_->blockBoard_.at((block_.getPosition().x - GRID) / GRID).at((block_.getPosition().y - GRID) / GRID + 1).block_.getFillColor() != Color::White)
	{
		ptrToBlockBoard_->blockBoard_.at((block_.getPosition().x - GRID) / GRID).at((block_.getPosition().y - GRID) / GRID).block_.setFillColor(Color::Red);
		block_.setPosition(5 * GRID, GRID);
		return false;
	}
	else return true;
}

void Block::moveRight() noexcept
{
	if (isMoveRightPossible())
	{
	    block_.move(GRID, 0);
	}
}

bool Block::isMoveRightPossible() const noexcept
{
	if (block_.getPosition().x >= GRID * NUMBER_OF_COLUMNS
		or ptrToBlockBoard_->blockBoard_.at((block_.getPosition().x - GRID) / GRID + 1).at((block_.getPosition().y - GRID) / GRID).block_.getFillColor() != Color::White)
	{
		return false;
	}
	return true;
}

void Block::moveLeft() noexcept
{
	if (isMoveLeftPossible())
	{
	    block_.move(-GRID, 0);
	}
}

bool Block::isMoveLeftPossible() const noexcept
{
	if (block_.getPosition().x <= GRID
		or ptrToBlockBoard_->blockBoard_.at((block_.getPosition().x - GRID) / GRID - 1).at((block_.getPosition().y - GRID) / GRID).block_.getFillColor() != Color::White)
	{
		return false;
	}
	return true;
}

void Block::draw(RenderTarget& target, RenderStates states) const noexcept
{
	target.draw(block_, states);
}
