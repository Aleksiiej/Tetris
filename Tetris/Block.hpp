#pragma once

#include <SFML/Graphics.hpp>
#include "GlobalValues.hpp"

using namespace sf;
class BlockBoard;

class Block : public Drawable
{
	friend class BlockBoard;
public:
	Block(const int& blockX, const int& blockY, BlockBoard* ptrToBlockBoard);
	Block();
	~Block() = default;

	void fall();
	bool isFallingPossible();
	void moveRight();
	bool isMoveRightPossible();
	void moveLeft();
	bool isMoveLeftPossible();

	void updatePosition();

	BlockBoard* ptrToBlockBoard_{};

private:
	RectangleShape block_{};
	Vector2f size_{GRID, GRID};
 
	void draw(RenderTarget& target, RenderStates states) const noexcept override;
};

