#pragma once

class IChunk
{
public:
	IChunk() = default;
	~IChunk() = default;
	virtual const bool checkIfLost() const noexcept = 0;
	virtual void fall() noexcept = 0;
	virtual const bool isFallingPossible() const noexcept = 0;
	virtual void moveRight() noexcept = 0;
	virtual const bool isMoveRightPossible() const noexcept = 0;
	virtual void moveLeft() noexcept = 0;
	virtual const bool isMoveLeftPossible() const noexcept = 0;
private:
	virtual const uint8_t gridToX(uint8_t blockNumber) const noexcept = 0;
	virtual const uint8_t gridToY(uint8_t blockNumber) const noexcept = 0;
};

