#pragma once

#include "BaseBlock.hpp"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class BlockBoard;

enum class Block4Position
{
	FlatOnTop, FlatOnRigth, FlatOnBottom, FlatOnLeft
};

class Block4 : public BaseBlock
{
public:
	Block4() = delete;
	Block4(BlockBoard& blockBoardRef) noexcept;
	Block4(const Block4& other) = delete;
	Block4(const Block4&& other) = delete;
	~Block4() = default;

	const bool checkIfLost() const noexcept;
	const bool isFallingPossible() noexcept;
	const bool isMoveRightPossible() const noexcept;
	const bool isMoveLeftPossible() const noexcept;
	const bool isRotationPossible() const noexcept;
	void rotate() noexcept;

private:
	Block4Position currentPosition_{};
<<<<<<< HEAD
	BlockBoard& blockBoardRef_;
	int possibility{ 1 };

	const uint8_t gridToX(const uint8_t& blockNumber) const noexcept;
	const uint8_t gridToY(const uint8_t& blockNumber) const noexcept;
=======
>>>>>>> 3e7c217 (Class BaseBlock completed)
};

// *---* *--* *---* *--*
// |012| |30| |  3| |2 |
// |3  | | 1| |210| |1 |
// *---* | 2| *---* |03|
//       *--*       *--*     
