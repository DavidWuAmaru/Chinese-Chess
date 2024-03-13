#include "Chess.h"
#include "Board.h"

class Horse :public Chess//馬、馬類，ID為-4和4
{
public:
	Horse(int i) :Chess((i == 0 ? -4 : 4)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};