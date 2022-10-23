#pragma once

#include "IBlock.hpp"

#include <array>
#include <memory>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class BlockBoard;

enum class Block5Position
{
	FlatOnTop, FlatOnRigth, FlatOnBottom, FlatOnLeft
};

class Block5 : public IBlock
{
public:
	Block5() = delete;
	Block5(BlockBoard& blockBoardRef) noexcept;
	Block5(const Block5& other) = delete;
	Block5(const Block5&& other) = delete;
	~Block5() = default;

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
	array<RectangleShape, 4> block5Array_;
	Block5Position currentPosition_{};
	BlockBoard& blockBoardRef_;

	const uint8_t gridToX(const uint8_t& blockNumber) const noexcept;
	const uint8_t gridToY(const uint8_t& blockNumber) const noexcept;
};

// *---* *--* *---* *--*
// |012| | 0| |3  | |23|
// |  3| | 1| |210| |1 |
// *---* |32| *---* |0 |
//       *--*       *--*     
