#include "Band.hpp"

Band::Band(const int& bandX, const int& bandY)
{
	band_.setPosition(bandX, bandY);
	band_.setSize(size_);
	band_.setFillColor(Color::White);
	band_.setOutlineColor(Color::Black);
	band_.setOutlineThickness(5);
}

void Band::draw(RenderTarget& target, RenderStates states) const noexcept
{
	target.draw(band_, states);
}
