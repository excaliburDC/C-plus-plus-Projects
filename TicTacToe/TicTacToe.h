#pragma once

#include <vector>

class TicTacToe
{
	char board[3][3];
	char winner;

public:
	// constructor
	TicTacToe();
	
	// reset
	void resetBoard();
	void resetWinner();
	void resetGame();
	

	// setters and getters
	void setPlayerSymbol(char symbol, int i);
	
	char getPlayerSymbol(int i);

	char winnerSymbol();

	// possible moves
	bool isMovePossible();

	
	std::vector<int> allPossibleMoves();
	
	// check winner
	bool checkWinner(char symbol);
	
	// do move
	void addMove(char symbol, int index);
	
	void displayBoard();
	
};