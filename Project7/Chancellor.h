#include "Chess.h"
#include "Board.h"

class Chancellor :public Chess//象、相類，ID為-3和3
{
public:
	Chancellor(int i) :Chess((i == 0 ? -3 : 3)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};