#pragma once

#include <SFML/Graphics.hpp>


using namespace sf;
using namespace std;

class BlockFunctions
{
private:
	void fall(array<RectangleShape, 4>& blockArray) noexcept;
	void moveRight(array<RectangleShape, 4>& blockArray) noexcept;
	void moveLeft(array<RectangleShape, 4>& blockArray) noexcept;
	void moveDown(array<RectangleShape, 4>& blockArray) noexcept;
	void setColor(array<RectangleShape, 4>& blockArray, const Color& color) noexcept;
	const uint8_t gridToX(array<RectangleShape, 4>& blockArray, const uint8_t& blockNumber) const noexcept;
	const uint8_t gridToY(array<RectangleShape, 4>& blockArray, const uint8_t& blockNumber) const noexcept;
};

