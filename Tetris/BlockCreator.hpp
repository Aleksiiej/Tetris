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
	BlockCreator(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept;
	BlockCreator(const BlockCreator& other) = delete;
	BlockCreator(const BlockCreator&& other) = delete;
	~BlockCreator() = default;

	unique_ptr<IBlock> createRandomBlock() noexcept;
private:
	const shared_ptr<BlockBoard> ptrToBlockBoard_{};
	random_device rd;
};

