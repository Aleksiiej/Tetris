#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "GlobalValues.hpp"
#include "IChunk.hpp"

using namespace sf;
using namespace std;

class BlockBoard;

class Chunk1 : public IChunk
{
public:
	Chunk1() = delete;
	Chunk1(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept;
	Chunk1(const Chunk1& other) = delete;
	Chunk1(const Chunk1&& other) = delete;
	~Chunk1() = default;

	const bool checkIfLost() const noexcept override;
	void fall() noexcept override;
	const bool isFallingPossible() noexcept override;
	void moveRight() noexcept override;
	const bool isMoveRightPossible() const noexcept override;
	void moveLeft() noexcept override;
	const bool isMoveLeftPossible() const noexcept override;
	void moveDown() noexcept override;

	RectangleShape& getBlock1Ref() noexcept;
	RectangleShape& getBlock2Ref() noexcept;
	RectangleShape& getBlock3Ref() noexcept;
	RectangleShape& getBlock4Ref() noexcept;
private:
	RectangleShape block1_{}; // *--*
	RectangleShape block2_{}; // |12|
	RectangleShape block3_{}; // |34|
	RectangleShape block4_{}; // *--*
	shared_ptr<BlockBoard> ptrToBlockBoard_{};

	const uint8_t gridToX(uint8_t blockNumber) const noexcept;
	const uint8_t gridToY(uint8_t blockNumber) const noexcept;
};

