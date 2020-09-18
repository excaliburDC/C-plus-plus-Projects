#include <iostream>
#include "Human.h"


using std::cin;
using std::cout;

int Human::getMove(TicTacToe game)
{
	int index;
	while (1)
	{
		cout << "\nEnter index: ";
		cin >> index;

		if (game.getPlayerSymbol(index - 1) == ' ')
			return index - 1;

		cout << "Wrong Move";
	}
}
