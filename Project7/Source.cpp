#include "Chancellor.h"

bool Chancellor::Judgement(Board& ch, int startx, int starty, int endx, int endy)
{
    int TempX = startx - endx;
    int TempY = starty - endy;
    int S_Id = ch.Getid(startx, starty);
    int E_Id = ch.Getid(endx, endy);
    if ((S_Id * E_Id <= 0) && (TempX * TempX + TempY * TempY == 8) && (endx % 2 != 0 && endx >= 1 && endy <= 9) && ((starty - 1) / 5 == (endy - 1) / 5) && !ch.Get(startx + (TempX / 2), starty + (TempY / 2)))
    {
        return true;
    }
    return false;
}