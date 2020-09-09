// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include < iostream >
#include < conio.h >

using std::cout;
using std::endl;

bool isGameover;

const int width = 20;

const int height = 17;

int x, y, foodX, foodY, score;

int tailX[100], tailY[100]; //snake coordinates

int nTail;

// Controls
enum eDirecton 
{ 
	STOP = 0, 
	LEFT, 
	RIGHT, 
	UP, 
	DOWN 
}; 

eDirecton dir;



void Setup() 
{
	isGameover = false;

	dir = STOP;

	x = width / 2;

	y = height / 2;

	//display food in a random place
	foodX = rand() % width; 
	foodY = rand() % height; 
	
	score = 0;

}

void DrawWalls() 
{
	system("cls");

	for (int i = 0; i < width + 2; i++)
		cout << "#";

	cout << endl;

	for (int i = 0; i < height; i++) 
	{

		for (int j = 0; j < width; j++) 
		{

			if (j == 0)
				cout << "#"; //walls

			if (i == y && j == x)
				cout << "0"; // snake's tail

			else if (i == foodY && j == foodX)

				cout << "*"; // snake's food

			else {

				bool print = false;

				for (int k = 0; k < nTail; k++) 
				{

					if (tailX[k] == j && tailY[k] == i) 
					{

						cout << "0"; 
						print = true;

					}

				}

				if (!print) 
					cout << " ";

			}

			if (j == width - 1)

				cout << "#";

		}

		cout << endl;

	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";

	cout << endl;

	cout << "Score:" << score << endl;

}

void SnakeMovement()
{
	//checks if a key is hit on the keyboard
	if (_kbhit()) 
	{
		//checks the pressed key with the input keys
		switch (_getch()) 
		{

		case 'a':

			dir = LEFT;
			break;

		case 'd':

			dir = RIGHT;
			break;

		case 'w':

			dir = UP;
			break;

		case 's':

			dir = DOWN;
			break;

		case 'x':

			isGameover = true;
			break;

		}

	}

}

void GameLoop()
{

	int prevX = tailX[0];

	int prevY = tailY[0];

	int prev2X, prev2Y;

	tailX[0] = x;

	tailY[0] = y;

	for (int i = 1; i < nTail; i++) 
	{

		prev2X = tailX[i];

		prev2Y = tailY[i];

		tailX[i] = prevX;

		tailY[i] = prevY;

		prevX = prev2X;

		prevY = prev2Y;

	}

	switch (dir) 
	{

	case LEFT:

		x--;
		break;

	case RIGHT:

		x++;
		break;

	case UP:

		y--;
		break;

	case DOWN:

		y++;
		break;

	default:

		break;

	}

	//if snake hits the wall reset the snake's position
	if (x >= width) 
		x = 0;

	else if (x < 0) 
		x = width - 1;

	if (y >= height) 
		y = 0; 
	else if (y < 0) 
		y = height - 1;


	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
		{
			isGameover = true;
			cout<<"\nGame Over....!!!!"<<endl;
		}
			
	}

		

	if (x == foodX && y == foodY) 
	{

		score += 10;

		foodX = rand() % width;

		foodY = rand() % height;

		nTail++;

	}

}

int main()
{

	Setup();

	while (!isGameover) 
	{

		DrawWalls();

		SnakeMovement();

		GameLoop();

	}

	return 0;

}