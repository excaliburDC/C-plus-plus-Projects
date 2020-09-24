#include <cstdlib> 
#include <ctime> 
#include <vector>
#include "CompAI.h"



int CompAI::getMove(TicTacToe game)
{
	AIMove move;
	//srand(time(0));

	//using srand with time generates different set of numbers every time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	if (game.allPossibleMoves().size() == 9)
		move.index = std::rand() % 9;
	else
		move = minimaxAlgo(game, getSymbol());

	return move.index;
}

AIMove CompAI::minimaxAlgo(TicTacToe state, char curr_player)
{
	char max_player = this->getSymbol();
	char other_player = (curr_player == 'X') ? 'O' : 'X';
	AIMove best, current;

	// base condition for win - lose
	if (state.winnerSymbol() == other_player)
	{
		best.score = state.allPossibleMoves().size() + 1;
		if (other_player != max_player)
			best.score = -best.score;
		return best;
	}
	// base condition for draw
	if (!state.isMovePossible())
	{
		best.score = 0;
		return best;
	}

	if (curr_player == max_player)
		best.score = -1000000;
	else
		best.score = 1000000;

	std::vector<int> move_set = state.allPossibleMoves();

	for (int i = 0; i < move_set.size(); i++)
	{
		state.addMove(curr_player, move_set[i]);
		current = minimaxAlgo(state, other_player);
		state.setPlayerSymbol(' ', move_set[i]);
		state.resetWinner();
		current.index = move_set[i];

		if (curr_player == max_player)
		{
			if (current.score > best.score)
				best = current;
		}
		else
		{
			if (current.score < best.score)
				best = current;
		}
	}
	return best;
}

