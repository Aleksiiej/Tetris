#include "BlockBoard.hpp"
#include "Block2.hpp"

#define SET_BLOCK2_STARTING_POSITION {\
block2Array_.at(0).setPosition((NUMBER_OF_COLUMNS / 2) * GRID - GRID, GRID); \
block2Array_.at(1).setPosition((NUMBER_OF_COLUMNS / 2) * GRID, GRID); \
block2Array_.at(2).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + GRID, GRID); \
block2Array_.at(3).setPosition((NUMBER_OF_COLUMNS / 2) * GRID + 2 * GRID, GRID); \
}

Block2::Block2(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept
	: block2Array_{ {RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }},
					 RectangleShape{Vector2f{ GRID, GRID }}} },
	currentPosition_(Block2Position::Horizontal),
	ptrToBlockBoard_(ptrToBlockBoard)
{
	SET_BLOCK2_STARTING_POSITION;
	for_each(begin(block2Array_), end(block2Array_), [](auto& block) { block.setFillColor(Color::Red); });
}

const bool Block2::checkIfLost() const noexcept
{
	if (block2Array_.at(0).getPosition().y == GRID
		and ptrToBlockBoard_->getBoardArrayRef().at(gridToX(0)).at(gridToY(0)).getFillColor() == Color::Red
		or block2Array_.at(1).getPosition().y == GRID
		and ptrToBlockBoard_->getBoardArrayRef().at(gridToX(1)).at(gridToY(1)).getFillColor() == Color::Red
		or block2Array_.at(2).getPosition().y == GRID
		and ptrToBlockBoard_->getBoardArrayRef().at(gridToX(2)).at(gridToY(3)).getFillColor() == Color::Red
	    or block2Array_.at(3).getPosition().y == GRID
	    and ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3)).at(gridToY(3)).getFillColor() == Color::Red)	
	{
		return false;
	}
	return true;
}

void Block2::fall() noexcept
{
	if (isFallingPossible())
	{
		for_each(begin(block2Array_), end(block2Array_), [](auto& block) { block.move(0, GRID); });
	}
}

const bool Block2::isFallingPossible() noexcept
{
	if (currentPosition_ == Block2Position::Horizontal)
	{

		if (block2Array_.at(0).getPosition().y >= GRID * NUMBER_OF_ROWS or block2Array_.at(3).getPosition().y >= GRID * NUMBER_OF_ROWS)
		{
			for (uint8_t i = 0; i < 4; i++)
			{
				ptrToBlockBoard_->setFillColor(gridToX(i), gridToY(i), Color::Red);
			}
			SET_BLOCK2_STARTING_POSITION;
			return false;
		}
		else if (ptrToBlockBoard_->getBoardArrayRef().at(gridToX(0)).at(gridToY(0) + 1).getFillColor() != Color::White
			or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(1)).at(gridToY(1) + 1).getFillColor() != Color::White
			or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(2)).at(gridToY(2) + 1).getFillColor() != Color::White
			or ptrToBlockBoard_->getBoardArrayRef().at(gridToX(3)).at(gridToY(3) + 1).getFillColor() != Color::White)
		{
			for (uint8_t i = 0; i < 4; i++)
			{
				ptrToBlockBoard_->setFillColor(gridToX(i), gridToY(i), Color::Red);
			}
			SET_BLOCK2_STARTING_POSITION;
			return false;
		}
		return true;
	}
}

const bool Block2::isMoveLeftPossible() const noexcept
{
	return true;
}

void Block2::moveRight() noexcept
{

}

const bool Block2::isMoveRightPossible() const noexcept
{
	return true;
}

void Block2::moveLeft() noexcept
{

}

void Block2::moveDown() noexcept
{
	while (isFallingPossible())
	{
		for_each(begin(block2Array_), end(block2Array_), [](auto& block) { block.move(0, GRID); });
	}
}

const bool Block2::isRotationPossible() const noexcept
{
	return false;
}

void Block2::rotate() noexcept
{
	
}

const array<RectangleShape, 4>& Block2::getBlock1ArrayRef() const noexcept
{
	return block2Array_;
}

const uint8_t Block2::gridToX(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block2Array_.at(0).getPosition().x - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block2Array_.at(1).getPosition().x - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block2Array_.at(2).getPosition().x - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block2Array_.at(3).getPosition().x - GRID) / GRID);
	default:
		return 255;
	}
}

const uint8_t Block2::gridToY(const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((block2Array_.at(0).getPosition().y - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((block2Array_.at(1).getPosition().y - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((block2Array_.at(2).getPosition().y - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((block2Array_.at(3).getPosition().y - GRID) / GRID);
	default:
		return 255;
	}
}

