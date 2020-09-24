#include <iostream>
#include "TicTacToe.h"



using std::cout;
using std::cin;
using std::endl;

//default constructor

TicTacToe::TicTacToe() 
{
	resetGame();
}

void TicTacToe :: resetBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = ' ';
	}
}
void TicTacToe :: resetWinner() 
{ 
	winner = ' '; 
}
void TicTacToe :: resetGame()
{
	resetBoard();
	resetWinner();
}

// setters and getters
void TicTacToe :: setPlayerSymbol(char symbol, int i) 
{ 
	board[i / 3][i % 3] = symbol; 
}

char TicTacToe :: getPlayerSymbol(int i) 
{ 
	return board[i / 3][i % 3]; 
}

char TicTacToe :: winnerSymbol() 
{ 
	return winner; 
}

// possible moves
bool TicTacToe :: isMovePossible()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				return true;
		}
	}
	return false;
}

std::vector<int> TicTacToe :: allPossibleMoves()
{
	std::vector<int> move_set;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				move_set.push_back(3 * i + j);
		}
	}
	return move_set;
}

// check winner
bool TicTacToe :: checkWinner(char symbol)
{
	// horizontal check
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == symbol)
			return true;
	}

	// vertical check
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == symbol)
			return true;
	}

	// diagonal 1 check
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == symbol)
		return true;

	// diagonal 2 check
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == symbol)
		return true;

	return false;
}

// do move
void TicTacToe :: addMove(char symbol, int index)
{
	int i = index / 3, j = index % 3;
	board[i][j] = symbol;

	if (checkWinner(symbol))
		winner = symbol;
}
void TicTacToe :: displayBoard()
{
	for (int i = 0; i <= 6; i += 3)
	{
		/*cout << "________";
		cout << "\n " << getPlayerSymbol(i) << " | " << getPlayerSymbol(i + 1) << " | " << getPlayerSymbol(i + 2)<<endl;*/
		cout << endl;
		cout << "------------------------------";
		cout << endl;
		cout << "|        |         |         |" << endl;
		cout << "|   " << getPlayerSymbol(i) << "    |    " << getPlayerSymbol(i+1) << "    |    " << getPlayerSymbol(i+2) << "    |"<<endl;
		cout << "|        |         |         |";

		if (i == 6)
		{
			cout << endl;
			cout << "------------------------------";
			break;
		}

	}
}
