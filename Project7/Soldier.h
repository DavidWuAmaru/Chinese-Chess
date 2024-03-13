#include "Chess.h"
#include "Board.h"

class Soldier :public Chess//¨ò¡B§LÃþ¡AID¬°-7©M7
{
public:
	Soldier(int i) :Chess((i == 0 ? -7 : 7)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};