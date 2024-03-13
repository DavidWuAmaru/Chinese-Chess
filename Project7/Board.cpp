#include "Board.h"
#include "Chess.h"
#include "General.h"
#include "BodyGuard.h"
#include "Chancellor.h"
#include "Horse.h"
#include "Chariot.h"
#include "Cannon.h"
#include "Soldier.h"

int Board::Player = -1;
bool Board::End = true;
Board::Board()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			c[i][j] = NULL;
		}
	}
	//memset(c, NULL, sizeof(c));
}
Chess* Board::Get(int x, int y)
{
	return c[x][y];
}
int Board::Getid(int x, int y)
{
	if (c[x][y] != NULL)
	{
		return c[x][y]->Get();
	}
	return NULL;
}
bool Board::Move(int startx, int starty, int endx, int endy)
{
	if (startx >= 1 && startx <= 9 && starty >= 1 && starty <= 10 && endx >= 1 && endx <= 9 && endy >= 1 && endy <= 10 && Getid(startx, starty) && Getid(startx, starty) * Player > 0 && c[startx][starty]->Judgement(*this, startx, starty, endx, endy))
	{
		if (c[endx][endy] != NULL)
		{
			delete c[endx][endy];           //吃子
		}
		c[endx][endy] = c[startx][starty];
		c[startx][starty] = NULL;
		Player *= -1;                       //更換玩家操作
		return true;
	}
	else
	{
		cout << "走法錯誤，請重新輸入：" << endl;
		return false;
	}
}
void Board::Init()
{
	c[1][1] = new Chariot(1);
	c[9][1] = new Chariot(1);
	c[2][1] = new Horse(1);
	c[8][1] = new Horse(1);
	c[3][1] = new Chancellor(1);
	c[7][1] = new Chancellor(1);
	c[4][1] = new BodyGuard(1);
	c[6][1] = new BodyGuard(1);
	c[5][1] = new General(1);
	c[2][3] = new Cannon(1);
	c[8][3] = new Cannon(1);
	c[1][4] = new Soldier(1);
	c[3][4] = new Soldier(1);
	c[5][4] = new Soldier(1);
	c[7][4] = new Soldier(1);
	c[9][4] = new Soldier(1);
	c[1][10] = new Chariot(0);
	c[9][10] = new Chariot(0);
	c[2][10] = new Horse(0);
	c[8][10] = new Horse(0);
	c[3][10] = new Chancellor(0);
	c[7][10] = new Chancellor(0);
	c[4][10] = new BodyGuard(0);
	c[6][10] = new BodyGuard(0);
	c[5][10] = new General(0);
	c[2][8] = new Cannon(0);
	c[8][8] = new Cannon(0);
	c[1][7] = new Soldier(0);
	c[3][7] = new Soldier(0);
	c[5][7] = new Soldier(0);
	c[7][7] = new Soldier(0);
	c[9][7] = new Soldier(0);
}
void Board::Show()
{
	cout << endl;
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 0xF0);
	cout << "     P2  一 二 三 四 五 六 七 八 九" << endl << endl;
	char num[11][4] = { "零","一","二","三","四","五","六","七","八","九" ,"十" };
	for (int i = 1; i < 11; i++)
	{
		if (i == 6)
		{
			SetConsoleTextAttribute(handle, 0xF0);
			cout << "          ————楚河 漢界————" << endl << endl;
		}
		SetConsoleTextAttribute(handle, 0xF0);
		cout << "     " << num[i] << "  ";
		for (int j = 1; j < 10; j++)
		{
			if (c[j][i] != NULL)
			{
				if (c[j][i]->Get() > 0)
				{
					SetConsoleTextAttribute(handle, 0xF2);
					cout << Chessword[c[j][i]->Get() + 7] << " ";
				}
				else
				{
					SetConsoleTextAttribute(handle, 0xFC);
					cout << Chessword[c[j][i]->Get() + 7] << " ";
				}
			}
			else if ((i == 2 && j == 5) || (i == 9 && j == 5))
			{
				SetConsoleTextAttribute(handle, 0xF0);
				cout << "米" << " ";
			}
			else
			{
				SetConsoleTextAttribute(handle, 0xF0);
				cout << "十" << " ";
			}
		}
		cout << endl << endl;
	}
	SetConsoleTextAttribute(handle, 0xF0);
	cout << "     P1  一 二 三 四 五 六 七 八 九" << endl << endl;
}
void Board::Play()
{
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 0xFC);
	system("cls");
	this->Init();
	this->Show();
	do
	{
		int startx, starty, aimx, aimy, iflag;
		int sid, aid;
		iflag = 0;
		do
		{
			sid = aid = 0;
			if ((Board::Player == 1 ? 2 : 1) == 1)
			{
				SetConsoleTextAttribute(handle, 0xFC);
			}
			else
			{
				SetConsoleTextAttribute(handle, 0xF2);
			}
			cout << "請P" << (Board::Player == 1 ? 2 : 1) << "輸入起始棋子位置與目標位置的坐標：" << endl;
			cin >> startx >> starty >> aimx >> aimy;
		} while (!this->Move(startx, starty, aimx, aimy));
		//system("cls");
		this->Show();
		for (int i = 4; i < 7; i++)
		{
			for (int j = 1; j < 11; j++)
			{
				if (c[i][j] != NULL)
				{
					if ((int)fabs(c[i][j]->Get()) == 1)
					{
						iflag++;
					}
					else if (iflag != 0 && iflag != 2)
					{
						if ((int)fabs(c[i][j]->Get()) != 1)
						{
							iflag--;
						}
					}
				}
			}
		}
		if (iflag == 2)
		{
			Player *= -1;
			Board::End = false;
		}
	} while (Board::End);
	if ((Board::Player == 1 ? 1 : 2) == 1)
	{
		SetConsoleTextAttribute(handle, 0xFC);
	}
	else
	{
		SetConsoleTextAttribute(handle, 0xF2);
	}
	cout << "結束，贏家是Player" << (Board::Player == 1 ? 1 : 2) << endl;
}
//Board::~Board()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 11; j++)
//		{
//			if (c[i][j] != NULL)
//			{
//				delete c[i][j];
//				c[i][j] = NULL;
//			}
//		}
//	}
//}