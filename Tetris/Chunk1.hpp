#pragma once

#include <SFML/Graphics.hpp>
#include "IChunk.hpp"

using namespace sf;
using namespace std;

class Chunk1 : public IChunk
{
public:
	Chunk1() = default;
	~Chunk1() = default;

	bool checkIfLost() const noexcept override;
	void fall() noexcept override;
	bool isFallingPossible() const noexcept override;
	void moveRight() noexcept override;
	bool isMoveRightPossible() const noexcept override;
	void moveLeft() noexcept override;
	bool isMoveLeftPossible() const noexcept override;
};

