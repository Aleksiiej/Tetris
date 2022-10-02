#pragma once

#include <SFML/Graphics.hpp>

#include "GlobalValues.hpp"
#include "IChunk.hpp"

using namespace sf;

class Chunk1 : public IChunk
{
public:
	Chunk1();
	~Chunk1() = default;

	bool checkIfLost() const noexcept override;
	void fall() noexcept override;
	bool isFallingPossible() const noexcept override;
	void moveRight() noexcept override;
	bool isMoveRightPossible() const noexcept override;
	void moveLeft() noexcept override;
	bool isMoveLeftPossible() const noexcept override;

private:
	RectangleShape block1_{}; // *--*
	RectangleShape block2_{}; // |12|  
	RectangleShape block3_{}; // |34|
	RectangleShape block4_{}; // *--*
};

