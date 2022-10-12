#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "GlobalValues.hpp"
#include "IBlock.hpp"

using namespace sf;
using namespace std;

class BlockBoard;

class Block2 : public IBlock
{
public:
	Block2() = delete;
	Block2(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept;
	Block2(const Block2& other) = delete;
	Block2(const Block2&& other) = delete;
	~Block2() = default;

	const bool checkIfLost() const noexcept override;
	void fall() noexcept override;
	const bool isFallingPossible() noexcept override;
	void moveRight() noexcept override;
	const bool isMoveRightPossible() const noexcept override;
	void moveLeft() noexcept override;
	const bool isMoveLeftPossible() const noexcept override;
	void moveDown() noexcept override;

	const array<RectangleShape, 4>& getBlock1ArrayRef() const noexcept override;

private:
	array<RectangleShape, 4> block2Array_;
	shared_ptr<BlockBoard> ptrToBlockBoard_{};

	const uint8_t gridToX(const uint8_t& blockNumber) const noexcept;
	const uint8_t gridToY(const uint8_t& blockNumber) const noexcept;
};

// *--*
// |01|
// |23|
// *--*