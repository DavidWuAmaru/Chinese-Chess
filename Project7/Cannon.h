#include "Chess.h"
#include "Board.h"

class Cannon :public Chess//¯¥¡B¬¶Ãþ¡AID¬°-6©M6
{
public:
	Cannon(int i) :Chess((i == 0 ? -6 : 6)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};