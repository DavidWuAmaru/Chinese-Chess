#ifndef Board_H
#define Board_H

#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<cmath>
using namespace std;

class Chess;
class Board
{
private:
	Chess* c[10][11];        //棋盤：X為橫（9），Y為縱（10），從1開始記
	char Chessword[15][4] = { "兵","炮","車","馬","相","仕","帥"," ","將","士","象","馬","車","砲","卒" };
public:
	string a;
	static int Player;       //上半區為1，下半區為-1
	static bool End;         //判斷是否結束
	Board();
	Chess* Get(int x, int y);//返回指定點的指針
	int Getid(int x, int y);//返回指定點處棋子ID的指針
	bool Move(int startx, int starty, int endx, int endy);	//移動
	void Init();               //初始化棋子
	void Show();               //打印
	void Play();               //開始遊戲
	//~Board();
};

# endif