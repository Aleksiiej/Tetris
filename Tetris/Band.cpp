#include "Band.hpp"

Band::Band(Vector2f vec) : size_(vec)
{
	band_.setSize(vec);
	band_.setPosition(GRID, GRID);
	band_.setFillColor(Color::White);
	band_.setOutlineColor(Color::Black);
	band_.setOutlineThickness(5);
}

void Band::draw(RenderTarget& target, RenderStates states) const noexcept
{
	target.draw(band_, states);
}
