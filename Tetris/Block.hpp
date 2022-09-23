#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "GlobalValues.hpp"

using namespace sf;
using namespace std;

class BlockBoard;

class Block : public Drawable
{
	friend class BlockBoard;
public:
	Block(const float& blockX, const float& blockY, const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept;
	Block() = default;
	~Block() = default;

	void fall() noexcept;
	const bool isFallingPossible() noexcept;
	void moveRight() noexcept;
	const bool isMoveRightPossible() const noexcept;
	void moveLeft() noexcept;
	const bool isMoveLeftPossible() const noexcept;

	const RectangleShape& getBlockRef() const noexcept;

	const RectangleShape& getBlockRef() const noexcept;

private:
	RectangleShape block_{};
	shared_ptr<BlockBoard> ptrToBlockBoard_{};
 
	void draw(RenderTarget& target, RenderStates states) const noexcept override;
	const uint8_t gridToX() const noexcept;
	const uint8_t gridToY() const noexcept;
};

