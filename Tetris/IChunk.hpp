#pragma once

class IChunk
{
public:
	IChunk() = default;
	~IChunk() = default;
	virtual bool checkIfLost() const noexcept = 0;
	virtual void fall() noexcept = 0;
	virtual bool isFallingPossible() const noexcept = 0;
	virtual void moveRight() noexcept = 0;
	virtual bool isMoveRightPossible() const noexcept = 0;
	virtual void moveLeft() noexcept = 0;
	virtual bool isMoveLeftPossible() const noexcept = 0;
};

