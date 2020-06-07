#include <vector>

using std::vector;
using std::string;

#pragma once

class Ship
{
private:

    char dir;
    int length;
    vector<int> boatrow;
    vector<int> boatcol;
    int hits;
    string name;



public:

    //Default constructor
    Ship(char d, int length, vector<int> r, vector<int> c, int hit, string name);
    void setHit();
    char checkIfSunk(int boatSize);

    void shipCoordinates();   //get ship grid coordinates
    string getShip(int row, int col);   //check coordinate bombed to find particular ship
};



