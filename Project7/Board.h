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
	Chess* c[10][11];        //�ѽL�GX����]9�^�AY���a�]10�^�A�q1�}�l�O
	char Chessword[15][4] = { "�L","��","��","��","��","�K","��"," ","�N","�h","�H","��","��","��","��" };
public:
	string a;
	static int Player;       //�W�b�Ϭ�1�A�U�b�Ϭ�-1
	static bool End;         //�P�_�O�_����
	Board();
	Chess* Get(int x, int y);//��^���w�I�����w
	int Getid(int x, int y);//��^���w�I�B�ѤlID�����w
	bool Move(int startx, int starty, int endx, int endy);	//����
	void Init();               //��l�ƴѤl
	void Show();               //���L
	void Play();               //�}�l�C��
	//~Board();
};

# endif