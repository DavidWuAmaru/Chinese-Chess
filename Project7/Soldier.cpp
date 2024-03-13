#include "Soldier.h"

bool Soldier::Judgement(Board& ch, int startx, int starty, int endx, int endy)
{
    int TempX = startx - endx;
    int TempY = starty - endy;
    int S_Id = ch.Getid(startx, starty);
    int E_Id = ch.Getid(endx, endy);
    if ((S_Id * E_Id <= 0) && (S_Id * TempY <= 0))
    {
        if (fabs(TempY) == 1 && TempX == 0)
        {
            return true;
        }
        if (fabs(TempX) == 1 && TempY == 0)
        {
            if (((starty - 1) / 5 == 0 && S_Id < 0) || ((starty - 1) / 5 == 1 && S_Id > 0))
            {
                return true;
            }
        }
    }
    return false;
}