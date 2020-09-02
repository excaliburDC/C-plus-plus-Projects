#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "TicTacToe.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;

//default constructor

TicTacToe::TicTacToe() 
{

	//initializing the board with all elements as ' '

	for (int row = 0; row < 3; row++)

		for (int col = 0; col < 3; col++)

			board[row][col] = ' ';

}

void TicTacToe::gameMenu()
{
	int choice;

	cout << "\n\n\t\t\t\t\tWelcome to TIC TAC TOE\n" << endl;
	cout << "\t\t\t\t     - - - - - - - - - - - - - - "<<endl;
	cout << "\n\n\t\t\tChoose Game Mode " << endl;
	cout << "\n\n 1.  Player VS Player" << endl;
	cout << "\n 2. Player VS Computer" << endl;
	cout << "\t\t\t\t\t   - - - - - - - - \n\n" << endl;
	cout << "\t\t\t\tPress 1 or 2 to select...  " << endl;
	cin >> choice;
	if (choice == 1)
	{
		system("cls");
		cout << "\n\n\t\t Starting Game...\n\n" << endl;
		cout << "\t\t Initializing game board....\n\n" << endl;
		displayBoard(); //display the initial board


	}
}

//function to display the current game board

void TicTacToe::displayBoard() 
{

	cout <<" 1 "<<setw(3)<<" 2 "<<setw(3)<<" 3 " << endl;

	for (int row = 0; row < 3; row++) //Loop through each row
	{ 

		cout << row + 1;

		for (int col = 0; col < 3; col++)  //loop through each column
		{ 

			cout << setw(3) << board[row][col]; //displaying the game board content

			if (col != 2)

				cout << " |";

		}

		cout << endl;

		if (row != 2)

			cout << " ____|____|____" << endl << " | | " << endl; //displaying the separator

	}

	cout << endl;

}

//function to check whether valid row and column number is entered or not

bool TicTacToe::isValidMove(int row, int col) 
{

	//checking if valid row and column number is entered and already filled cell number is not entered

	if (board[row][col] == ' ' && (row >= 0 && row <= 2) && (col >= 0 && col <= 2))

		return true; //return true if a valid cell number is entered

	else

		return false; //return false if not a valid cell number is entered

}

//function to check the current game status

status TicTacToe::gameStatus(int noOfMoves) 
{

	//Check rows for a win

	for (int row = 0; row < 3; row++)

	{

		if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ')

		{

			return WIN;

		}

	}

	//check for columns

	for (int col = 0; col < 3; col++)

	{

		if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ')

		{

			return WIN;

		}

	}

	//check downward diagonal

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')

	{

		return WIN;

	}

	//check upward diagonal

	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')

	{

		return WIN;

	}

	//Check if any empty cell exists, If yes, return CONTINUE

	for (int i = 0; i < 3; i++)

	{

		for (int j = 0; j < 3; j++)

		{

			if (board[i][j] == ' ')

				return CONTINUE;

		}

	}

	return DRAW; //return DRAW

}


//Function to read the players move

void TicTacToe::getXOMove(char playerSymbol, int& row, int& col) 
{
	int player = 1;

	do 
	{
		////determines player turns
		//player = (player % 2) ? 1 : 2;
		//cout << "\nPlayer" << player << " 's turn: " << endl;
		//cout<<"\nEnter the row and col to make your move : "<<endl;
		//cin >> row >> col;
		////decides the symbol for player 1 & 2
		//playerSymbol = (player == 1) ? 'X' : 'O';

		cout << "Player " << playerSymbol << " Enter move: ";

		cin >> row >> col; //Reading the row number and column number

		cout << endl;

	} 
	while (!isValidMove(row - 1, col - 1)); //ask to re-enter if not a valid move is entered

	row--; //Decrement row by 1 to start from 0

	col--; //Decrement column by 1 to start from 0

}

//Function to add the players move

bool TicTacToe::addMove(int noOfMoves, char playerSymbol, int row, int col) {

	board[row][col] = playerSymbol; //add the player symbol to the cell

	noOfMoves++; //Increment noOfMoves by 1

	system("cls");

	displayBoard(); //Display the current board after adding the players move

	status gStatus = gameStatus(noOfMoves); //check for winner

	if (gStatus == WIN)  //If gameStatus() returns WIN, display the player details and return true
	{ 

		cout << "Player " << playerSymbol << " wins!" << endl;

		return true;

	}
	else if (gStatus == DRAW)   //If gameStatus() returns DRAW, display game draw and return true
	{

		cout << "This game is a draw!" << endl;

		return true;

	}
	else if (noOfMoves >= 9)  //if noOfMoves > 9, match tied, return true
	{ 

		return true;

	}

	else

		return false; //else return false

}
