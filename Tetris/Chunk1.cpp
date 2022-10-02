#include "Chunk1.hpp"

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