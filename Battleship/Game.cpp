#include<iostream>
#include <ctime>
#include <cstdlib>
#include "Game.h"


using std::cin;
using std::cout;
using std::endl;


void Game::initGame(int grid[][10],vector<Ship> shipList,char play)
{
    _play:if (play == 'p')
    {
        b.initGrid(grid);
        //b.printBoard(grid);  //uncomment to see initialised grid

        //set the ships onto the grid
        setShip(grid, Carrier, 1, shipList);
        setShip(grid, Battleship, 2, shipList);
        setShip(grid, Battleship, 3, shipList);
        setShip(grid, Destroyer, 4, shipList);
        setShip(grid, Destroyer, 5, shipList);
        setShip(grid, Destroyer, 6, shipList);
        setShip(grid, Submarine, 7, shipList);
        setShip(grid, Submarine, 8, shipList);
        setShip(grid, Submarine, 9, shipList);
        setShip(grid, Submarine, 10, shipList);
        playGame(grid, shipList);
    }

    else
    {
        cout << "Invalid Input...\nPlease try again" << endl;
        cin >> play;
        goto _play;
    }


}

int Game::returnRandColAndRow(int col, int& row, int shipSize, char d)
{
    switch (shipSize) //Generate random column and row based on ship size so we don't go over the edge of the grid
    {
    case Submarine:
        if (d == 'h')
        {
            col = rand() % 8;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 8;
        }
        break;
    case Destroyer:
        if (d == 'h')
        {
            col = rand() % 7;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 7;
        }
        break;
    case Battleship:
        if (d == 'h')
        {
            col = rand() % 6;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 6;
        }
        break;
    case Carrier:
        if (d == 'h')
        {
            col = rand() % 5;
            row = rand() % 10;
        }
        else
        {
            col = rand() % 10;
            row = rand() % 5;
        }
    }
    return col;

}

char Game::getDirection(int d)
{
    if (d > 4)
    {
        return 'h';  //randomly pick which direction to place ship
    }
    else
    {
        return 'v';
    }
}

//check the grid to make sure that none of the ships will overlap
int Game::checkSpaces(int grid[][10], int c, int r, int s, char d)
{
    int check = 0;
    if (d == 'h')
    {
        for (int i = c; i < c + s; i++)
        {
            check = grid[r][i];
            if (check != 0)
            {
                return 1;
            }
        }

        return 0;
    }
    else
    {
        for (int i = r; i < r + s; i++)
        {
            check = grid[i][c];
            if (check != 0)
            {
                return 1;

            }
        }

        return 0;
    }
}

//This function puts the numbers that correspond to the ship type on the grid
void Game::editGrid(int grid[][10], int col, int row, int shipSize, char dir)
{
    if (dir == 'h')
    {
        for (int i = 0; i < shipSize; i++)
        {
            grid[row][col] = shipSize;
            col++;
            cout << endl;
        }
    }
    else if (dir == 'v')
    {
        for (int i = 0; i < shipSize; i++)
        {
            grid[row][col] = shipSize;
            row++;
            cout << endl;
        }
    }
    else
    {
        cout << "Error...!!!\n  No direction passed" << endl;
    }
    //printBoard(grid);  //uncomment to see finished grid
}

//This function places the individual ship onto the initialised grid
bool Game::setShip(int grid[][10], int shipSize, int name, vector<Ship>& boatList)
{
    srand(time(0));
    int col = 0;
    int row = 0;
    char d = 'v';
    bool placementFailure = true;
    char check = 'v';
    int cS = 0;

    d = getDirection(rand() % 10);  //randomly pick which direction to place ship

    //This function returns a random column and row (by reference) of where to place the ship
    col = returnRandColAndRow(col, row, shipSize, d);  

    while (placementFailure)
    {
        if (d == 'h')
        {
            cS = checkSpaces(grid, col, row, shipSize, d);//check to make sure the ship can be placed without overlapping another ship
            if (cS == 1)//if the ship overlaps, generate another random column, row and direction and start the loop again
            {
                d = getDirection(rand() % 10);
                col = returnRandColAndRow(col, row, shipSize, d);
                cS == 0;
                continue;
            }
            editGrid(grid, col, row, shipSize, d);//place the ship on the grid
            editShipInfo(grid, col, row, shipSize, d, boatList, name);//create the ship object
            return 0;
        }//end of 'if horizontal'
        else if (d == 'v')
        {
            cS = checkSpaces(grid, col, row, shipSize, d);
            if (cS == 1)
            {
                d = getDirection(rand() % 10);
                col = returnRandColAndRow(col, row, shipSize, d);
                cS == 0;
                continue;
            }
            editGrid(grid, col, row, shipSize, d);
            editShipInfo(grid, col, row, shipSize, d, boatList, name);
            return 0;
        }
    }//end of while loop
}

//This function creates the ship objects
void Game::editShipInfo(int grid[][10], int c, int r, int shipSize, char d, vector<Ship>& shipList, int name)
{
    switch (name)
    {
    case 1:
        if (d == 'h')
        {
            vector<int> r1(5);
            //  put coordinate data into the vectors using at()
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(5);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Aircraft Carrier
            Ship carrierShip('h', 5, r1, c1, 0, "Aircraft Carrier");
            shipList.push_back(carrierShip);
        }
        else if (d == 'v')
        {
            vector<int> r1(5);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(5);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Aircraft Carrier
            Ship carrierShip('v', 5, r1, c1, 0, "Aircraft Carrier");
            shipList.push_back(carrierShip);
        }
        break;
    case 2:
        if (d == 'h')
        {
            vector<int> r1(4);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(4);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Battleship 1
            Ship battleship1Ship('h', 4, r1, c1, 0, "Battleship 1");
            shipList.push_back(battleship1Ship);
        }
        else if (d == 'v')
        {
            vector<int> r1(4);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(4);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Battleship 1
            Ship battleship1Ship('v', 4, r1, c1, 0, "Battleship 1");
            shipList.push_back(battleship1Ship);
        }
        break;
    case 3:
        if (d == 'h')
        {
            vector<int> r1(4);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(4);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Battleship 2
            Ship battleship2Ship('h', 4, r1, c1, 0, "Battleship 2");
            shipList.push_back(battleship2Ship);
        }
        else if (d == 'v')
        {
            vector<int> r1(4);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(4);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Battleship 2
            Ship battleship2Ship('v', 4, r1, c1, 0, "Battleship 2");
            shipList.push_back(battleship2Ship);
        }
        break;
    case 4:
        if (d == 'h')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Destroyer 1
            Ship destroyer1Ship('h', 3, r1, c1, 0, "Destroyer 1");
            shipList.push_back(destroyer1Ship);
        }
        else if (d == 'v')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Destroyer 1
            Ship destroyer1Ship('v', 3, r1, c1, 0, "Destroyer 1");
            shipList.push_back(destroyer1Ship);
        }
        break;
    case 5:
        if (d == 'h')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Destroyer 2
            Ship destroyer2Ship('h', 3, r1, c1, 0, "Destroyer 2");
            shipList.push_back(destroyer2Ship);
        }
        else if (d == 'v')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Destroyer 2
            Ship destroyer2Ship('v', 3, r1, c1, 0, "Destroyer 2");
            shipList.push_back(destroyer2Ship);
        }
        break;
    case 6:
        if (d == 'h')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Destroyer 3
            Ship destroyer3Ship('h', 3, r1, c1, 0, "Destroyer 3");
            shipList.push_back(destroyer3Ship);
        }
        else if (d == 'v')
        {
            vector<int> r1(3);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(3);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Destroyer 3
            Ship destroyer3Ship('v', 3, r1, c1, 0, "Destroyer 3");
            shipList.push_back(destroyer3Ship);
        }
        break;
    case 7:
        if (d == 'h')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Submarine1
            Ship submarine1Ship('h', 2, r1, c1, 0, "Submarine 1");
            shipList.push_back(submarine1Ship);
        }
        else if (d == 'v')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Submarine 1
            Ship submarine1Ship('v', 2, r1, c1, 0, "Submarine 1");
            shipList.push_back(submarine1Ship);
        }
        break;
    case 8:
        if (d == 'h')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Submarine 2
            Ship submarine2Ship('h', 2, r1, c1, 0, "Submarine 2");
            shipList.push_back(submarine2Ship);
        }
        else if (d == 'v')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Submarine 2
            Ship submarine2Ship('v', 2, r1, c1, 0, "Submarine 2");
            shipList.push_back(submarine2Ship);
        }
        break;
    case 9:
        if (d == 'h')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Submarine 3
            Ship submarine3Ship('h', 2, r1, c1, 0, "Submarine 3");
            shipList.push_back(submarine3Ship);
        }
        else if (d == 'v')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Submarine 3
            Ship submarine3Ship('v', 2, r1, c1, 0, "Submarine 3");
            shipList.push_back(submarine3Ship);
        }
        break;
    case 10:
        if (d == 'h')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
                c++;
            }
            //Submarine 4
            Ship submarine4Ship('h', 2, r1, c1, 0, "Submarine 4");
            shipList.push_back(submarine4Ship);
        }
        else if (d == 'v')
        {
            vector<int> r1(2);
            for (int i = 0; i < (int)r1.size(); ++i)
            {
                r1.at(i) = r;
                r++;
            }
            vector<int> c1(2);
            for (int i = 0; i < (int)c1.size(); ++i)
            {
                c1.at(i) = c;
            }
            //Submarine 4
            Ship submarine4Ship('v', 2, r1, c1, 0, "Submarine 4");
            shipList.push_back(submarine4Ship);
        }
        break;
    }
}

void Game::playGame(int grid[][10], vector<Ship>& shipList)
{
    bool gameInProgress = true;
    int row = 0;
    int col = 0;
    int guess = 0;
    int numChances = 50;
    int hit = 0;
    int miss = 0;
    int space = 0;
    char d = 'g';
    string btname = "";
    char sunk = '/0';
    system("cls");
    while (gameInProgress)
    {
        
        b.printGameBoard(grid);
        b.printHitsAndMiss(hit,miss,numChances);
        //b.printBoard(grid);  //uncomment to see the game board with the ships on it
        coord: cout << "Enter a row coordinate: ";
        cin >> row;
        cout << "Enter a column coordinate: ";
        cin >> col;
        cout << endl;

        if (row < 0 || row > 9 || col < 0 || col > 9)
        {
            cout << "Coordinates out of bound...\nPlease enter a valid coordinate" << endl<<endl;
            goto coord;
        }

  




        guess++;
        numChances--;
        space = getSpace(grid, row, col);

        switch (space)
        {
        case 0:
            cout << "You have missed" << endl;
            grid[row][col] = 9;
            miss++;
            break;
        case 1:
            cout << "This space has already been bombed.  You have wasted a guess!" << endl;
            break;
        case 2:
            grid[row][col] = 1;
            hit++;

            btname = shipList[6].getShip(row, col);  //Check to see if ship is Submarine 1
            if (btname == "Submarine 1")
            {
                cout << "You have bombed " << btname << "!" << endl;
                shipList[6].setHit();
                sunk = shipList[6].checkIfSunk(Submarine);
                if (sunk == 'H')
                {
                    cout << "You have sunk Submarine 1." << endl;
                }
            }
            else if (btname.empty())
            {
                btname = shipList[7].getShip(row, col);  //Check to see if ship is Submarine 2
                if (btname == "Submarine 2")
                {
                    cout << "You have bombed " << btname << "!" << endl;
                    shipList[7].setHit();
                    sunk = shipList[7].checkIfSunk(Submarine);
                    if (sunk == 'H')
                    {
                        cout << "You have sunk Submarine 2." << endl;
                    }
                }
                else if (btname.empty())
                {
                    btname = shipList[8].getShip(row, col);  //Check to see if ship is Submarine 3
                    cout << "You have bombed " << btname << "!" << endl;
                    shipList[8].setHit();
                    sunk = shipList[8].checkIfSunk(Submarine);
                    if (sunk == 'H')
                    {
                        cout << "You have sunk Submarine 3." << endl;
                    }
                }
                else if (btname.empty())
                {
                    btname = shipList[9].getShip(row, col);  //Check to see if ship is Submarine 4
                    cout << "You have bombed " << btname << "!" << endl;
                    shipList[9].setHit();
                    sunk = shipList[9].checkIfSunk(Submarine);
                    if (sunk == 'H')
                    {
                        cout << "You have sunk Submarine 4." << endl;
                    }
                }
            }
            btname.clear();
            break;
        case 3:
            grid[row][col] = 1;
            hit++;

            btname = shipList[3].getShip(row, col);  //Check to see if ship is Destroyer 1
            if (btname == "Destroyer 1")
            {
                cout << "You have bombed " << btname << "!" << endl;
                shipList[3].setHit();
                sunk = shipList[3].checkIfSunk(Destroyer);
                if (sunk == 'H')
                {
                    cout << "You have sunk Destroyer 1." << endl;
                }
            }
            else if (btname.empty())
            {
                btname = shipList[4].getShip(row, col);  //Check to see if ship is Destroyer 2
                if (btname == "Destroyer 2")
                {
                    cout << "You have bombed " << btname << "!" << endl;
                    shipList[4].setHit();
                    sunk = shipList[4].checkIfSunk(Destroyer);
                    if (sunk == 'H')
                    {
                        cout << "You have sunk Destroyer 2." << endl;
                    }
                }
                else if (btname.empty())
                {
                    btname = shipList[5].getShip(row, col);  //Check to see if ship is Destroyer 3
                    cout << "You have bombed " << btname << "!" << endl;
                    shipList[5].setHit();
                    sunk = shipList[5].checkIfSunk(Destroyer);
                    
                    if (sunk == 'H')
                    {
                        cout << "You have sunk Destroyer 3." << endl;
                    }
                }
            }
            btname.clear();
            break;
        case 4:
            grid[row][col] = 1;
            hit++;

            btname = shipList[1].getShip(row, col);  //Check to see if ship is Battleship 1
            if (btname == "Battleship 1")
            {
                cout << "You have bombed " << btname << "!" << endl;
                shipList[1].setHit();
                sunk = shipList[1].checkIfSunk(Battleship);
                if (sunk == 'H')
                {
                    cout << "You have sunk Battleship 1." << endl;
                }
            }
            if (btname.empty())
            {
                btname = shipList[2].getShip(row, col);  //Check to see if ship is Battleship 2
                cout << "You have bombed " << btname << "!" << endl;
                shipList[2].setHit();
                sunk = shipList[2].checkIfSunk(Battleship);
                if (sunk == 'H')
                {
                    cout << "You have sunk Battleship 2." << endl;
                }
            }
            btname.clear();
            break;
        case 5:
            cout << "You have bombed the aircraft carrier! " << endl;
            grid[row][col] = 1;
            hit++;
            shipList[0].setHit();
            sunk = shipList[0].checkIfSunk(Carrier);
            if (sunk == 'H')
            {
                cout << "You have sunk the aircraft carrier." << endl;
            }
            break;
        }//end of switch

        cout << "\n\nPress Enter to continue" << endl;
        cin.get();

        if (cin.get())
            system("cls");

        
        
        if (hit == 30)
        {
            cout << "Thank you for playing! \n You have sunk all the battleships in " << guess << " moves!" << endl;
            gameInProgress = false;
        }

        if (numChances <= 0)
        {
            cout << "Game Over...!!! :( \n You have reached the limit of your chances and you couldn't sink all the battleships" << endl;
            cout << "Better Luck Next Time :)" << endl;
            gameInProgress = false;
        }
    }//end of while game is playing loop

    


}

int Game::getSpace(int grid[][10], int row, int col)
{
    int space = 0;
    space = grid[row][col];
    return space;
}

