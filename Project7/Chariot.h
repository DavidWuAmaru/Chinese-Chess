#include "Chess.h"
#include "Board.h"

class Chariot :public Chess//���B�����AID��-5�M5
{
public:
	Chariot(int i) :Chess((i == 0 ? -5 : 5)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};