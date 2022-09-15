#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalValues.hpp"

using namespace sf;

class Band : public sf::Drawable
{
public:
	Band(Vector2f vec);
	Band() = delete;
	~Band() = default;

private:
	RectangleShape band_;
	Vector2f size_;

	void draw(RenderTarget& target, RenderStates states) const noexcept override;
};

