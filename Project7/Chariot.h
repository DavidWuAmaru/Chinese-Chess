#include "Chess.h"
#include "Board.h"

class Chariot :public Chess//車、車類，ID為-5和5
{
public:
	Chariot(int i) :Chess((i == 0 ? -5 : 5)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};