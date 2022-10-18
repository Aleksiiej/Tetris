#include "BlockCreator.hpp"
#include "IBlock.hpp"
#include "Block1.hpp"
#include "Block2.hpp"
#include "blockBoard.hpp"

BlockCreator::BlockCreator(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept
	: ptrToBlockBoard_(ptrToBlockBoard)
{}

unique_ptr<IBlock> BlockCreator::createRandomBlock() noexcept
{
	unique_ptr<IBlock> createdBlock;
	uint8_t randomNumber;

	mt19937 rng(rd());
	uniform_int_distribution<> distrib1(0, 1);
	randomNumber = distrib1(rng);
	switch (randomNumber)
	{
	case 0:
		createdBlock = make_unique<Block1>(ptrToBlockBoard_);
		break;
	case 1:
		createdBlock = make_unique<Block2>(ptrToBlockBoard_);
		break;
	}

	uniform_int_distribution<> distrib2(0, 5);
	randomNumber = distrib2(rng);
	switch (randomNumber)
	{
	case 0:
		createdBlock->setColor(Color::Red);
		break;
	case 1:
		createdBlock->setColor(Color::Green);
		break;
	case 2:
		createdBlock->setColor(Color::Blue);
		break;
	case 3:
		createdBlock->setColor(Color::Yellow);
		break;
	case 4:
		createdBlock->setColor(Color::Magenta);
		break;
	case 5:
		createdBlock->setColor(Color::Cyan);
		break;
	}

	return move(createdBlock);
}