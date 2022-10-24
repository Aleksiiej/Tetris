#pragma once

#include "BaseBlock.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class BlockBoard;

enum class Block5Position
{
	FlatOnTop, FlatOnRigth, FlatOnBottom, FlatOnLeft
};

class Block5 : public BaseBlock
{
public:
	Block5() = delete;
	Block5(BlockBoard& blockBoardRef) noexcept;
	Block5(const Block5& other) = delete;
	Block5(const Block5&& other) = delete;
	~Block5() = default;

	const bool checkIfLost() const noexcept;
	const bool isFallingPossible() noexcept;
	const bool isMoveRightPossible() const noexcept;
	const bool isMoveLeftPossible() const noexcept;
	const bool isRotationPossible() const noexcept;
	void rotate() noexcept;

private:
	Block5Position currentPosition_{};
};

// *---* *--* *---* *--*
// |012| | 0| |3  | |23|
// |  3| | 1| |210| |1 |
// *---* |32| *---* |0 |
//       *--*       *--*     
