#include "StateBoard.hpp"

StateBoard::StateBoard()
{
	for_each(begin(stateBoard_), end(stateBoard_), [](auto& el) { el.fill(FieldState::WHITE); });
}
