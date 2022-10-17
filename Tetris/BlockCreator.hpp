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
	shared_ptr<IBlock> createRandomBlock();
private:
	const shared_ptr<BlockBoard> ptrToBlockBoard_{};
	random_device rd;
};

