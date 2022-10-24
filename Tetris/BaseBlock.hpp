#pragma once

#include <SFML/Graphics.hpp>

#include <array>

using namespace sf;
using namespace std;

class BlockBoard;

class BaseBlock
{
public:
	BaseBlock() = delete;
	BaseBlock(BlockBoard& blockBoardRef) noexcept;
	BaseBlock(const BaseBlock& other) = delete;
	BaseBlock(const BaseBlock&& other) = delete;
	~BaseBlock() = default;

	void fall() noexcept;
	void moveRight() noexcept;
	void moveLeft() noexcept;
	void moveDown() noexcept;

	void setColor(const Color& color) noexcept;
	void setColorsInBlockBoard() const noexcept;
	void setPossibilityToChangePosition(const bool& possibility) noexcept;
	const array<RectangleShape, 4>& getBlockArrayRef() const noexcept;
	const bool& getPossibilityToChangePosition() const noexcept;

protected:
	array<RectangleShape, 4> blockArray_;
	BlockBoard& blockBoardRef_;
	bool possibilityToChangePosition_{ true };

	const uint8_t gridToX(const uint8_t& blockNumber) const noexcept;
	const uint8_t gridToY(const uint8_t& blockNumber) const noexcept;
};

