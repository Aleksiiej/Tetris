#pragma once

#include "BaseBlock.hpp"

#include <array>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class BlockBoard;

enum class Block2Position
{
	Horizontal, Vertical
};

class Block2: public BaseBlock
{
public:
	Block2() = delete;
	Block2(BlockBoard& blockBoardRef) noexcept;
	Block2(const Block2& other) = delete;
	Block2(const Block2&& other) = delete;
	~Block2() = default;

	const bool checkIfLost() const noexcept;
	const bool isFallingPossible() noexcept;
	const bool isMoveRightPossible() const noexcept;
	const bool isMoveLeftPossible() const noexcept;
	const bool isRotationPossible() const noexcept;
	void rotate() noexcept;

private:
	Block2Position currentPosition_{};
};

// *----*
// |0123|
// *----*
