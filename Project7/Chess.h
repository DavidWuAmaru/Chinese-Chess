#ifndef Chess_H
#define Chess_H

#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<cmath>
using namespace std;
class Board;
class Chess
{
private:
	int Id;
public:
	Chess(int x);
	int Get();
	virtual bool Judgement(Board& ch, int startx, int starty, int endx, int endy) = 0;//�P�_���B�X�z��
	virtual ~Chess() {}
};

# endif