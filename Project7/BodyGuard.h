#include "Chess.h"
#include "Board.h"

class BodyGuard :public Chess//�h�B�K���AID��-2�M2
{
public:
	BodyGuard(int i) :Chess((i == 0 ? -2 : 2)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
};