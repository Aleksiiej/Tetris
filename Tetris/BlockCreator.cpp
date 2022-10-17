#include "BlockCreator.hpp"
#include "IBlock.hpp"
#include "Block1.hpp"
#include "Block2.hpp"
#include "blockBoard.hpp"

BlockCreator::BlockCreator(const shared_ptr<BlockBoard>& ptrToBlockBoard) noexcept
	: ptrToBlockBoard_(ptrToBlockBoard)
{}

shared_ptr<IBlock> BlockCreator::createRandomBlock()
{
	mt19937 rng(rd());
	uniform_int_distribution<> distrib(0, 1);
	uint8_t randomNumber = distrib(rng);
	switch (randomNumber)
	{
	case 0:
		return make_shared<Block1>(ptrToBlockBoard_);
		break;
	case 1:
		return make_shared<Block2>(ptrToBlockBoard_);
		break;
	}
}