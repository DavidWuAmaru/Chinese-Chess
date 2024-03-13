#include "Chess.h"
#include "Board.h"

class General :public Chess//將、帥類，ID為-1和1
{
public:
	General(int i) :Chess((i == 0 ? -1 : 1)) {}
	bool Judgement(Board& ch, int startx, int starty, int endx, int endy);
	~General();
};