#pragma once

class IChunk
{
public:
	IChunk() = default;
	~IChunk() = default;
	virtual bool checkIfLost() const noexcept;
	virtual void fall() noexcept;
	virtual bool isFallingPossible() const noexcept;
	virtual void moveRight() noexcept;
	virtual bool isMoveRightPossible() const noexcept;
	virtual void moveLeft() noexcept;
	virtual bool isMoveLeftPossible() const noexcept;
};

