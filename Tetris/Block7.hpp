#pragma once

#include "BaseBlock.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class BlockBoard;

enum class Block7Position
{
	Horizontal, Vertical
};

class Block7 : public BaseBlock
{
public:
	Block7() = delete;
	Block7(BlockBoard& blockBoardRef) noexcept;
	Block7(const Block7& other) = delete;
	Block7(const Block7&& other) = delete;
	~Block7() = default;

	const bool checkIfLost() const noexcept;
	const bool isFallingPossible() noexcept;
	const bool isMoveRightPossible() const noexcept;
	const bool isMoveLeftPossible() const noexcept;
	const bool isRotationPossible() const noexcept;
	void rotate() noexcept;

private:
	Block7Position currentPosition_{};
};

// *---* *---*
// |   | | 0 |
// |01 | |21 |
// | 23| |3  |
// *---* *---*
