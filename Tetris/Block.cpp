#include "Block.hpp"

Block::Block(const int& blockX, const int& blockY)
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
	currentPosition_.x = (block_.getPosition().x) / GRID;
	currentPosition_.y = (block_.getPosition().y) / GRID;

}