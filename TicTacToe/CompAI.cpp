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
	AIMove bestMove, currentMove;

	// base condition for win - lose
	if (state.whoWon == other_player)
	{
		bestMove.score = state.allPossibleMoves().size() + 1;
		if (other_player != max_player)
			bestMove.score = -bestMove.score;
		return bestMove;
	}
	// base condtion for draw
	if (!state.isMovePossible())
	{
		bestMove.score = 0;
		return bestMove;
	}

	if (curr_player == max_player)
		bestMove.score = -1000000;
	else
		bestMove.score = 1000000;

	std::vector<int> move_set = state.allPossibleMoves();

	for (int i = 0; i < move_set.size(); i++)
	{
		state.addMove(curr_player, move_set[i]);
		currentMove = minimax(state, other_player);
		state.setChar(' ', move_set[i]);
		state.resetWinner();
		currentMove.index = move_set[i];

		if (curr_player == max_player)
		{
			if (currentMove.score > bestMove.score)
				bestMove = currentMove;
		}
		else
		{
			if (currentMove.score < bestMove.score)
				bestMove = currentMove;
		}
	}
	return bestMove;
}
