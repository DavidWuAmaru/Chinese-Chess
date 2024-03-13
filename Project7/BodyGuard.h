#include "Chess.h"
#include "Board.h"

class BodyGuard :public Chess//士、仕類，ID為-2和2
{
public:
	BodyGuard(int i) :Chess((i == 0 ? -2 : 2)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};