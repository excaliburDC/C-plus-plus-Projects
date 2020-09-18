#include "TicTacToe.h"

#pragma once

//abstract class
class Player
{
	char symbol;

public:
	
	Player(char s) : symbol(s) 
	{ }
	
	// getter
	char getSymbol()
	{ 
		return symbol; 
	}

	// virtual function
	virtual int getMove(TicTacToe game) = 0;
};
