#pragma once

#include "IBlock.hpp"

#include <array>
#include <memory>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class BlockBoard;

enum class Block4Position
{
	FlatOnTop, FlatOnRigth, FlatOnBottom, FlatOnLeft
};

class Block4 : public IBlock
{
public:
	Block4() = delete;
	Block4(BlockBoard& blockBoardRef) noexcept;
	Block4(const Block4& other) = delete;
	Block4(const Block4&& other) = delete;
	~Block4() = default;

	const bool checkIfLost() const noexcept override;
	void fall() noexcept override;
	const bool isFallingPossible() noexcept override;
	void setColorsInBlockBoard() const noexcept override;
	void moveRight() noexcept override;
	const bool isMoveRightPossible() const noexcept override;
	void moveLeft() noexcept override;
	const bool isMoveLeftPossible() const noexcept override;
	void moveDown() noexcept override;
	const bool isRotationPossible() const noexcept override;
	void rotate() noexcept override;

	const array<RectangleShape, 4>& getBlockArrayRef() const noexcept override;
	void setColor(const Color& color) noexcept;

private:
	array<RectangleShape, 4> block4Array_;
	Block4Position currentPosition_{};
	BlockBoard& blockBoardRef_;

	const uint8_t gridToX(const uint8_t& blockNumber) const noexcept;
	const uint8_t gridToY(const uint8_t& blockNumber) const noexcept;
};

// *---* *--* *---* *--*
// |012| |30| |  3| |2 |
// |3  | | 1| |210| |1 |
// *---* | 2| *---* |03|
//       *--*       *--*     