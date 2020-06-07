#include<vector>
#include "Ship.h"
#include "Board.h"


using std::vector;

#pragma once
class Game
{
private:
   
    Board b;


public:


    enum ShipHealth
    {
        Submarine = 2,
        Destroyer = 3,
        Battleship = 4,
        Carrier = 5
    };

    
    void initGame(int grid[][10], vector<Ship> shipList,char play);
    int returnRandColAndRow(int col, int& row, int shipSize, char d);
    char getDirection(int d);
    int checkSpaces(int grid[][10], int c, int r, int s, char d);
    void editGrid(int grid[][10], int col, int row, int shipSize, char dir); 
    bool setShip(int grid[][10], int shipSize, int name, vector<Ship>& boatList); 
    void editShipInfo(int grid[][10], int c, int r, int shipSize, char d, vector<Ship>& shipList, int name);
    void playGame(int grid[][10], vector<Ship>& shipList);
    int getSpace(int grid[][10], int row, int col);


};