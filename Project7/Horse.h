#include "Chess.h"
#include "Board.h"

class Horse :public Chess//���B�����AID��-4�M4
{
public:
	Horse(int i) :Chess((i == 0 ? -4 : 4)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};