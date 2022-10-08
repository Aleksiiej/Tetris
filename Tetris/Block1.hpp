#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "GlobalValues.hpp"
#include "IBlock.hpp"

using namespace sf;
using namespace std;

class BlockBoard;

class Block1 : public IBlock
{
public:
	Block1() = delete;
	Block1(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept;
	Block1(const Block1& other) = delete;
	Block1(const Block1&& other) = delete;
	~Block1() = default;

	const bool checkIfLost() const noexcept override;
	void fall() noexcept override;
	const bool isFallingPossible() noexcept override;
	void moveRight() noexcept override;
	const bool isMoveRightPossible() const noexcept override;
	void moveLeft() noexcept override;
	const bool isMoveLeftPossible() const noexcept override;
	void moveDown() noexcept override;

	const array<RectangleShape, 4>& getBlock1ArrayRef() const noexcept;

private:
	array<RectangleShape, 4> block1Array_;
	shared_ptr<BlockBoard> ptrToBlockBoard_{};

	const uint8_t gridToX(uint8_t blockNumber) const noexcept;
	const uint8_t gridToY(uint8_t blockNumber) const noexcept;
};

// *--*
// |01|
// |23|
// *--*

