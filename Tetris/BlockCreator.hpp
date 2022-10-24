#pragma once
#include <memory>
#include <random>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class BaseBlock;
class BlockBoard;

class BlockCreator
{
public:
	BlockCreator() = delete;
	BlockCreator(BlockBoard& blockBoardRef) noexcept;
	BlockCreator(const BlockCreator& other) = delete;
	BlockCreator(const BlockCreator&& other) = delete;
	~BlockCreator() = default;

	unique_ptr<BaseBlock> createRandomBlock() noexcept;
private:
	BlockBoard& blockBoardRef_;
	random_device rd_;
};

