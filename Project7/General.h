#include "Chess.h"
#include "Board.h"

class General :public Chess//�N�B�����AID��-1�M1
{
public:
	General(int i) :Chess((i == 0 ? -1 : 1)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
	~General();
};