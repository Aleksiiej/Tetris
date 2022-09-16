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

private:
	RectangleShape block_{};
	Vector2f size_{GRID, GRID};
	Vector2f currentPosition;

	void draw(RenderTarget& target, RenderStates states) const noexcept override;
};

