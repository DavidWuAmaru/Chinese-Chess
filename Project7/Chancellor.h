#include "Chess.h"
#include "Board.h"

class Chancellor :public Chess//�H�B�����AID��-3�M3
{
public:
	Chancellor(int i) :Chess((i == 0 ? -3 : 3)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};