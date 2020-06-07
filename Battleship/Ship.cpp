#include<iostream>
#include "Ship.h"

using std::cout;
using std::endl;


Ship::Ship(char d, int l, vector<int> r, vector<int> c, int h, string n)
{
    dir = d;
    length = l;
    boatrow = r;
    boatcol = c;
    hits = h;
    name = n;
}


void Ship::setHit()
{
    hits++;
}

char Ship::checkIfSunk(int shipHealth)
{
    if (hits >= shipHealth)
    {
        return 'H';
    }
    else
    {
        return 'M';
    }
}

void Ship::shipCoordinates()
{
    cout << "Coordinates for Ship " << name << endl << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Grid [" << boatrow[i] << "][" << boatcol[i] << "]" << endl;
    }
    cout << endl;
}

string Ship::getShip(int row, int col)
{
    for (int i = 0; i < length; i++)
    {
        if ((boatrow[i] == row) && (boatcol[i] == col))
        {
            return name;
        }
    }
    return "";
}
