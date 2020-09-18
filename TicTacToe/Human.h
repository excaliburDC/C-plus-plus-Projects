#pragma once
#include "Player.h"
class Human : public Player
{
public :

	Human(char s) : Player(s)
	{}
	
	int getMove(TicTacToe game);
};

