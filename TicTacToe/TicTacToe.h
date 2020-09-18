#pragma once

#include<vector>
#include "Player.h"

enum class status 
{

	WIN,

	DRAW,

	CONTINUE

};

enum class GameMode
{
	PVP,
	PVAI
};



//class definition
class TicTacToe 
{

private:

	char board[3][3]; //declaring a 2d character array to tract the game board
	GameMode gameMode;
	

public:

	TicTacToe(); //default constructor

	void resetGame();

	void setPlayerSymbol(char symbol, int i); 

	char getPlayerSymbol(int i); 

	void gameMenu();

	void gameManager(Player* playerX,Player* playerO);

	void displayBoard(); //function to display the current game board

	bool isValidMove(); //function to check whether valid the entered move is valid or not

	std::vector<int> allPossibleMoves();  //function to check all the possible moves in available

	status gameStatus(); //function to check the current game status

	void getXOMove(char playerSymbol, int& row, int& col); //Function to read the players move

	

	bool addMove(char playerSymbol, int index); //Function to add the players move

};
