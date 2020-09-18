#pragma once

#include "Player.h"


struct AIMove
{
	int index;
	long score;
};

class CompAI : public Player
{
public:
	CompAI(char s) : Player(s) {}

	int getMove(TicTacToe game);

	AIMove minimaxAlgo(TicTacToe state, char curr_player);

};

