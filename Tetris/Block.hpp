#pragma once

#include <SFML/Graphics.hpp>
#include "GlobalValues.hpp"

using namespace sf;

class Block : public Drawable
{
public:
	Block(const int& blockX, const int& blockY);
	Block() = delete;
	~Block() = default;

	void fall();
	void moveRight();
	void moveLeft();

private:
	RectangleShape block_{};
	Vector2f size_{GRID, GRID};

	void draw(RenderTarget& target, RenderStates states) const noexcept override;
};

