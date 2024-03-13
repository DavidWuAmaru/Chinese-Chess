#include "Cannon.h"

bool Cannon::Judgement(Board& ch, int startx, int starty, int endx, int endy)
{
    int TempX = startx - endx;
    int TempY = starty - endy;
    int S_Id = ch.Getid(startx, starty);
    int E_Id = ch.Getid(endx, endy);

    if ((S_Id * E_Id <= 0) && (!(TempX && TempY)) && (TempX + TempY))
    {
        int Tmp = 0;
        if (TempX)
        {
            int Sign = (TempX > 0 ? -1 : 1);
            for (int i = 1; i < fabs(TempX); i++)
            {
                if (ch.Get(startx + Sign * i, starty))
                {
                    Tmp++;
                }
            }
        }
        else
        {
            int Sign = (TempY > 0 ? -1 : 1);
            for (int i = 1; i < fabs(TempY); i++)
            {
                if (ch.Get(startx, starty + Sign * i))
                {
                    Tmp++;
                }
            }
        }
        if (E_Id)
        {
            if (Tmp == 1)
            {
                return true;
            }
        }
        else
        {
            if (!Tmp)
            {
                return true;
            }
        }
    }
    return false;
}