#include "Chunk1.hpp"

Chunk1::Chunk1()
{
	block1_.setPosition(NUMBER_OF_COLUMNS, GRID);
	block1_.setSize(Vector2f{ GRID, GRID });
	block1_.setFillColor(Color::Red);

	block2_.setPosition(NUMBER_OF_COLUMNS + 1, GRID);
	block2_.setSize(Vector2f{ GRID, GRID });
	block2_.setFillColor(Color::Red);

	block2_.setPosition(NUMBER_OF_COLUMNS + 1, GRID);
	block2_.setSize(Vector2f{ GRID, GRID });
	block2_.setFillColor(Color::Red);
}

bool Chunk1::checkIfLost() const noexcept
{
	return true;
}

void Chunk1::fall() noexcept
{}

bool Chunk1::isFallingPossible() const noexcept
{
	return true;
}

void Chunk1::moveRight() noexcept
{}

bool Chunk1::isMoveRightPossible() const noexcept
{
	return true;
}

void Chunk1::moveLeft() noexcept
{}

bool Chunk1::isMoveLeftPossible() const noexcept
{
	return true;
}