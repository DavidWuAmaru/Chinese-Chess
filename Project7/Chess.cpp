#include "Chess.h"
#include "Board.h"

Chess::Chess(int x) {
	this->Id = x;
}
int Chess::Get()                //��ID
{
	return Id;
}