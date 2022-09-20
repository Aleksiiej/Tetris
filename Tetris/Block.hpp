#pragma once

#include <SFML/Graphics.hpp>
#include "GlobalValues.hpp"

using namespace sf;

class Block : public Drawable
{
	friend class BlockBoard;
public:
	Block(const int& blockX, const int& blockY);
	Block();
	~Block() = default;

	void fall();
	bool isFallingPossible();
	void moveRight();
	bool isMoveRightPossible();
	void moveLeft();
	bool isMoveLeftPossible();

	void updatePosition();

private:
	RectangleShape block_{};
	Vector2f size_{GRID, GRID};
	Vector2f currentPosition_{};

	void draw(RenderTarget& target, RenderStates states) const noexcept override;
};

