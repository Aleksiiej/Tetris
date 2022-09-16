#include "Block.hpp"

Block::Block(const int& blockX, const int& blockY)
{
	block_.setPosition(blockX, blockY);
	block_.setSize(size_);
	block_.setFillColor(Color::Red);
}

void Block::fall()
{
	block_.move(0, GRID);
}

void Block::draw(RenderTarget& target, RenderStates states) const noexcept
{
	target.draw(block_, states);
}