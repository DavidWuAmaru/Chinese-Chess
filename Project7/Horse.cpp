#include "Horse.h"

bool Horse::Judgement(Board& ch, int startx, int starty, int endx, int endy)
{
    int TempX = startx - endx;
    int TempY = starty - endy;
    int S_Id = ch.Getid(startx, starty);
    int E_Id = ch.Getid(endx, endy);
    cout << ch.Get(startx + (TempX / 2), starty + (TempY / 2)) << startx + (TempX / 2) << starty + (TempY / 2);
    if ((S_Id * E_Id <= 0) && (TempX * TempX + TempY * TempY == 5) && !ch.Get(startx + (TempX / 2), starty + (TempY / 2)))
    {
        
        return true;
    }
    return false;
}