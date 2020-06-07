#include<iostream>
#include"Board.h"

using std::cout;
using std::cin;
using std::endl;


void Board::initGrid(int grid[][10])
{
    for (int col = 0; col < 10; col++) //Outer column loop
    {
        for (int row = 0; row < 10; row++) //Inner row loop
        {
            grid[col][row] = 0;
        }
    }
}


void Board::printBoard(int grid[][10])
{
    cout << "   0|1|2|3|4|5|6|7|8|9" << endl << endl;
    for (int i = 0; i < 10; i++)  //column loop
    {
        for (int j = 0; j < 10; j++)  //row loop
        {
            if (j == 0)
            {
                cout << i << "  "; //print row number and spaces before new row
            }
            cout << grid[i][j];
            if (j != 9)
            {
                cout << "|";
            }
        }
        cout << endl; //new line at end of column
    }
    cout << endl;
}

void Board::printGameBoard(int grid[][10])
{
    cout << "   0|1|2|3|4|5|6|7|8|9" << endl << endl;
    for (int i = 0; i < 10; i++)  //column loop
    {
        for (int j = 0; j < 10; j++)  //row loop
        {
            if (j == 0)
            {
                cout << i << "  "; //print row number and spaces before new row
            }
            if (grid[i][j] == 1)  //if the space is a hit, print it
            {
                cout << "H";
            }
            else if (grid[i][j] == 9)  //if the space is a miss, print it
            {
                cout << "M";
            }
            else
            {
                cout << "~";  //otherwise, just print a 0
            }

            if (j != 9)
            {
                cout << "|";
            }
        }
        cout << endl; //new line at end of column
    }
    cout << endl;
}

void Board::printHitsAndMiss(int nHits, int nMiss,int nChances)
{
    cout << endl;
    cout << "Hits: " << nHits << endl;
    cout << "Misses: " << nMiss << endl;
    cout << "Guesses Left: " << nChances << endl;
}
