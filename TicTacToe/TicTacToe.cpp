#include <iostream>
#include <iomanip>
#include "TicTacToe.h"
#include "Human.h"
#include "CompAI.h"


using std::cout;
using std::cin;
using std::endl;
using std::setw;

//default constructor

TicTacToe::TicTacToe() 
{
	resetGame();
}

void TicTacToe::resetGame()
{
	//initializing the board with all elements as ' '

	for (int row = 0; row < 3; row++)

		for (int col = 0; col < 3; col++)

			board[row][col] = ' ';
}

void TicTacToe::setPlayerSymbol(char symbol, int i)
{
	board[i / 3][i % 3] = symbol;
}

char TicTacToe::getPlayerSymbol(int i)
{
	return board[i / 3][i % 3];
}

void TicTacToe::gameMenu()
{
	char ch;
	int choice;

	Human x_human('X');
	Human o_human('O');
	CompAI x_AI('X');
	CompAI o_AI('O');

	Player* X, * O;

	do 
	{
		cout << "\n\n\t\t\t\t\tWelcome to TIC TAC TOE\n" << endl;
		cout << "\t\t\t\t     - - - - - - - - - - - - - - " << endl;
		cout << "\n\n\t\t\tChoose Game Mode " << endl;
		cout << "\n\n 1.  Player VS Player" << endl;
		cout << "\n 2. Player VS Computer" << endl;
		cout << "\n 3. Computer VS Player" << endl;
		cout << "\t\t\t\t\t   - - - - - - - - \n\n" << endl;
		cout << "\t\t\t\tPress 1,2 or 3 to select...  " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			X = &x_human;
			O = &o_human;
			break;

		case 2:
			system("cls");
			X = &x_human;
			O = &o_AI;
			break;

		case 3:
			system("cls");
			X = &x_AI;
			O = &o_human;
			break;

		default:
			cout << "Wrong choice... Please enter a valid choice" << endl;;
		}

		gameManager(X, O);

		cout << endl << "Do you want to play again (y/n) : ";
		cin >> ch;
	} 
	while (ch == 'y' || ch == 'Y');

	
	
}

void TicTacToe::gameManager(Player *playerX ,Player* playerO)
{
	char letter = 'X';
	int index;
	resetGame();

	
	status gStatus = gameStatus(); //check for winner

	while (gStatus == status::CONTINUE)
	{
		if (letter == 'O')
			index = playerO->getMove(*this);
		else
			index = playerX->getMove(*this);

		addMove(letter, index);

		if (gStatus == status::WIN)  //If gameStatus() returns WIN, display the player details and return true
		{

			cout << "Player " << letter << " wins!" << endl;
			break;
		}

		else if (gStatus == status::DRAW)   //If gameStatus() returns DRAW, display game draw and return true
		{

			cout << "This game is a draw!" << endl;
			break;

		}
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

bool TicTacToe::isValidMove() 
{

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (board[row][col] == ' ')
				return true;
		}
	}
	return false;

}

std::vector<int> TicTacToe::allPossibleMoves()
{
	std::vector<int> move_set;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (board[row][col] == ' ')
				move_set.push_back(3 * row + col);
		}
	}
	return move_set;
}

//function to check the current game status

status TicTacToe::gameStatus() 
{

	//Check rows for a win

	for (int row = 0; row < 3; row++)

	{

		if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ')

		{

			return status::WIN;

		}

	}

	//check for columns

	for (int col = 0; col < 3; col++)

	{

		if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ')

		{

			return status::WIN;

		}

	}

	//check downward diagonal

	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')

	{

		return status::WIN;

	}

	//check upward diagonal

	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ')

	{

		return status::WIN;

	}

	//Check if any empty cell exists, If yes, return CONTINUE

	for (int i = 0; i < 3; i++)

	{

		for (int j = 0; j < 3; j++)

		{

			if (board[i][j] == ' ')

				return status::CONTINUE;

		}

	}

	return status::DRAW; //return DRAW

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

bool TicTacToe::addMove(char playerSymbol, int index) 
{

	setPlayerSymbol(playerSymbol, index);

	system("cls");

	cout << endl;
	cout << playerSymbol << "'s move : " << index + 1 << endl;

	displayBoard(); //Display the current board after adding the players move



}
