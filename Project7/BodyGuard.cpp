#include "BodyGuard.h"

bool BodyGuard::Judgement(Board& ch, int startx, int starty, int endx, int endy)
{
    int TempX = startx - endx;
    int TempY = starty - endy;
    int S_Id = ch.Getid(startx, starty);
    int E_Id = ch.Getid(endx, endy);
    if ((S_Id * E_Id <= 0) && (TempX * TempX + TempY * TempY == 2) && (endx >= 4 && endx <= 6) && (endy >= 1 && endy <= 3 || endy >= 8 && endy <= 10))
    {
        return true;
    }
    return false;
}