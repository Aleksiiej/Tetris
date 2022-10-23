#include "BlockFunctions.hpp"
#include "GlobalValues.hpp"

#include <algorithm>
#include <array>

void BlockFunctions::fall(array<RectangleShape, 4>& blockArray) noexcept
{
	for_each(begin(blockArray), end(blockArray), [](auto& block) { block.move(0, GRID); });
}

void BlockFunctions::moveRight(array<RectangleShape, 4>& blockArray) noexcept
{
	for_each(begin(blockArray), end(blockArray), [](auto& block) { block.move(GRID, 0); });
}

void BlockFunctions::moveLeft(array<RectangleShape, 4>& blockArray) noexcept
{
	for_each(begin(blockArray), end(blockArray), [](auto& block) { block.move(-GRID, 0); });
}

void BlockFunctions::moveDown(array<RectangleShape, 4>& blockArray) noexcept
{
	for_each(begin(blockArray), end(blockArray), [](auto& block) { block.move(0, GRID); });
}

void BlockFunctions::setColor(array<RectangleShape, 4>& blockArray, const Color& color) noexcept
{
	for_each(begin(blockArray), end(blockArray), [&](auto& block) { block.setFillColor(color); });
}

const uint8_t BlockFunctions::gridToX(array<RectangleShape, 4>& blockArray, const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((blockArray.at(0).getPosition().x - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((blockArray.at(1).getPosition().x - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((blockArray.at(2).getPosition().x - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((blockArray.at(3).getPosition().x - GRID) / GRID);
	default:
		return 255;
	}
}

const uint8_t BlockFunctions::gridToY(array<RectangleShape, 4>& blockArray, const uint8_t& blockNumber) const noexcept
{
	switch (blockNumber)
	{
	case 0:
		return static_cast<uint8_t>((blockArray.at(0).getPosition().y - GRID) / GRID);
	case 1:
		return static_cast<uint8_t>((blockArray.at(1).getPosition().y - GRID) / GRID);
	case 2:
		return static_cast<uint8_t>((blockArray.at(2).getPosition().y - GRID) / GRID);
	case 3:
		return static_cast<uint8_t>((blockArray.at(3).getPosition().y - GRID) / GRID);
	default:
		return 255;
	}
}