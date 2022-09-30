#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "GlobalValues.hpp"

using namespace sf;
using namespace std;

class BlockBoard;

class Block : public Drawable
{
public:
	Block(const float& blockX, const float& blockY, const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept;
	Block() = default;
	Block(const Block& other) = delete;
	Block(const Block&& other) = delete;
	~Block() = default;

	bool checkIfLost() const noexcept;
	void fall() noexcept;
	const bool isFallingPossible() noexcept;
	void moveRight() noexcept;
	const bool isMoveRightPossible() const noexcept;
	void moveLeft() noexcept;
	const bool isMoveLeftPossible() const noexcept;
	void moveDown() noexcept;

	RectangleShape& getBlockRef() noexcept;

private:
	RectangleShape block_{};
	shared_ptr<BlockBoard> ptrToBlockBoard_{};
 
	void draw(RenderTarget& target, RenderStates states) const noexcept override;
	const uint8_t gridToX() const noexcept;
	const uint8_t gridToY() const noexcept;
};

