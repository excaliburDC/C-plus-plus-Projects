// TicTacToeCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "TicTacToe.h"



using namespace std;





//main function

int main() 
{

	int noOfMoves = 0; //Initialize noOfMoves by 0

	bool done = false; //Initialize done as false

	TicTacToe T; //Instantiate class object

	char player='X'; //let player X starts the game

	T.gameMenu();


	while (!done)   //Loop until done is true
	{

		int row, col;

		T.getXOMove(player, row, col); //Reading the row and col number

		done = T.addMove(noOfMoves, player, row, col); //Add the move to the board

		//Switch the players

		if (player == 'X')

			player = 'O';

		else

			player = 'X';

		

	}

	return 0;

}
