// TicTacToeCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "TicTacToe.h"
#include "Human.h"
#include "CompAI.h"

using std::cin;
using std::cout;
using std::endl;


void gameManager(TicTacToe game, Player* playerX, Player* playerO)
{
	char letter = 'X';
	int index;
	game.resetGame();
	while (game.isMovePossible())
	{
		if (letter == 'O')
			index = playerO->getMove(game);
		else
			index = playerX->getMove(game);

		
		game.addMove(letter, index);
		system("cls");
		cout << endl;
		cout << "Player " << letter << " makes move to " << index + 1 << endl << endl;
		game.displayBoard();
		cout << endl;
		

		if (game.checkWinner(letter))
		{
			cout << endl;
			cout <<"Player "<< letter << " wins !";
			return;
		}

		letter = (letter == 'X') ? 'O' : 'X';
		
	}
	cout << endl << "Match Tied";
}

//main function

int main() 
{
	TicTacToe game;

	char ch;
	int choice;

	Human x_human('X');
	Human o_human('O');
	CompAI x_AI('X');
	CompAI o_AI('O');

	Player* X = nullptr, * O = nullptr;

	do
	{
		system("cls");
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

		gameManager(game, X, O);

		cout << endl << "Do you want to play again (y/n) : ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');



	return 0;

}
