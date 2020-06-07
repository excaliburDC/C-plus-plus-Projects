#include<iostream>
#include<vector>
#include <ctime>
#include "Game.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;



int main()
{
    char play;
    int grid[10][10];
    vector<Ship> boatList;
    Game g;

    cout << "Welcome to Battleships.  Press p to play the game" << endl << endl;
    cout << "The board will show H for a hit and M for a miss" << endl << endl;
    cin >> play;

    //printBoard(grid);  //uncomment to see initialised grid
    g.initGame(grid,boatList,play);

  
    
    

   
    

   

	return 0;
}