#pragma once

class IBlock
{
public:
	IBlock() = default;
	~IBlock() = default;
	virtual const bool checkIfLost() const noexcept = 0;
	virtual void fall() noexcept = 0;
	virtual const bool isFallingPossible() noexcept = 0;
	virtual void moveRight() noexcept = 0;
	virtual const bool isMoveRightPossible() const noexcept = 0;
	virtual void moveLeft() noexcept = 0;
	virtual const bool isMoveLeftPossible() const noexcept = 0;
	virtual void moveDown() noexcept = 0;
	virtual const bool isRotationPossible() const noexcept = 0;
	virtual void rotate() noexcept = 0;
	virtual const array<RectangleShape, 4>& getBlock1ArrayRef() const noexcept = 0;
	virtual void setColor(const Color& color) noexcept = 0;

private:
	virtual const uint8_t gridToX(const uint8_t& blockNumber) const noexcept = 0;
	virtual const uint8_t gridToY(const uint8_t& blockNumber) const noexcept = 0;
};

