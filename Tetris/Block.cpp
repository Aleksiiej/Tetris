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

const bool Block::isFallingPossible() noexcept
{
	if (block_.getPosition().y >= GRID * NUMBER_OF_ROWS)
	{
		ptrToBlockBoard_->getBoardArrayRef().at(gridToX()).at(gridToY()).block_.setFillColor(Color::Red); //TODO: Owner of this line should be class BlockBoard
		block_.setPosition(5 * GRID, GRID);
		return false;
	}
	else if (ptrToBlockBoard_->blockBoard_.at(gridToX()).at(gridToY() + 1).block_.getFillColor() != Color::White)
	{
		ptrToBlockBoard_->getBoardArrayRef().at(gridToX()).at(gridToY()).block_.setFillColor(Color::Red); //TODO: Owner of this line should be class BlockBoard
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

const bool Block::isMoveRightPossible() const noexcept
{
	if (block_.getPosition().x >= GRID * NUMBER_OF_COLUMNS
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX() + 1).at(gridToY()).block_.getFillColor() != Color::White)
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

const bool Block::isMoveLeftPossible() const noexcept
{
	if (block_.getPosition().x <= GRID
		or ptrToBlockBoard_->getBoardArrayRef().at(gridToX() - 1).at(gridToY()).block_.getFillColor() != Color::White)
	{
		return false;
	}
	return true;
}

const RectangleShape& Block::getBlockRef() const noexcept
{
	return block_;
}

void Block::draw(RenderTarget& target, RenderStates states) const noexcept
{
	target.draw(block_, states);
}

const uint8_t Block::gridToX() const noexcept
{
	return static_cast<uint8_t>((block_.getPosition().x - GRID) / GRID);
}

const uint8_t Block::gridToY() const noexcept
{
	return static_cast<uint8_t>((block_.getPosition().y - GRID) / GRID);
}
