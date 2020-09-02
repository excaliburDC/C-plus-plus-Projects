

#pragma once


enum status 
{

	WIN,

	DRAW,

	CONTINUE

};

struct BoardCoordinate 
{
	int x;
	int y;
};

//class definition
class TicTacToe 
{

private:

	char board[3][3]; //declaring a 2d character array to tract the game board

public:

	TicTacToe(); //default constructor

	void gameMenu();

	void displayBoard(); //function to display the current game board

	bool isValidMove(int row, int col); //function to check whether valid row and column number is entered or not

	status gameStatus(int noOfMoves); //function to check the current game status

	void getXOMove(char playerSymbol, int& row, int& col); //Function to read the players move

	bool addMove(int noOfMoves, char playerSymbol, int row, int col); //Function to add the players move

};
