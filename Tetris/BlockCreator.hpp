#pragma once
#include <memory>
#include <random>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class IBlock;
class Block1;
class Block2;
class BlockBoard;

class BlockCreator
{
public:
	BlockCreator() = delete;
	BlockCreator(BlockBoard& blockBoardRef) noexcept;
	BlockCreator(const BlockCreator& other) = delete;
	BlockCreator(const BlockCreator&& other) = delete;
	~BlockCreator() = default;

	unique_ptr<IBlock> createRandomBlock() noexcept;
private:
	BlockBoard& blockBoardRef_;
	random_device rd;
};

