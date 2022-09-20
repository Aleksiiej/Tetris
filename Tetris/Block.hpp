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
	bool isFallingPossible() noexcept;
	void moveRight() noexcept;
	bool isMoveRightPossible() const noexcept;
	void moveLeft() noexcept;
	bool isMoveLeftPossible() const noexcept;

private:
	RectangleShape block_{};
	shared_ptr<BlockBoard> ptrToBlockBoard_{};
 
	void draw(RenderTarget& target, RenderStates states) const noexcept override;
};

