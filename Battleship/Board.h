#pragma once
class Board
{
public:
    void initGrid(int grid[][10]);
    void printBoard(int grid[][10]); //Print the board with the ships placed on it
    void printGameBoard(int grid[][10]); //This is the board that is printed for playing the game.  You cannot see the ships
    void printHitsAndMiss(int nHits, int nMiss,int nChances);
};

