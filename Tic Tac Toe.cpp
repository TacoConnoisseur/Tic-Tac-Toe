#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//Declare an array that has 3 rows and
//three columns using 9 asterisks to represent
//9 spaces on the tic tac toe board
char game[3][3] = { '*', '*', '*', '*', '*', '*', '*', '*', '*' };

//Declare a variable representing both players
char player = 'X';

//Declare variable to represent number of tiles in use
int n = 0;

//Declare function that will display the game board
//after both players choose a space on the board
void board()
{

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			cout << game[r][c] << " ";
		}
		cout << endl;
	}
}

//Declare a function that gets input from the players
void Input()
{
	int a;
	cout << "Choose a space on the board: " << player << " ";
	cin >> a;

	a--;
	game[a / 3][a % 3] = player;
}

//Declare a function that will allow 2 people to play
void switchPlayers()
{
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}
//Set the win conditions for player 1
char winCondition()
{
	//player 1's win conditions must be checked for all spaces
	if (game[0][0] == 'X' && game[0][1] == 'X' && game[0][2] == 'X')
		return 'X';
	if (game[1][0] == 'X' && game[1][1] == 'X' && game[1][2] == 'X')
		return 'X';
	if (game[2][0] == 'X' && game[2][1] == 'X' && game[2][2] == 'X')
		return 'X';

	if (game[0][0] == 'X' && game[1][0] == 'X' && game[2][0] == 'X')
		return 'X';
	if (game[0][1] == 'X' && game[1][1] == 'X' && game[2][1] == 'X')
		return 'X';
	if (game[0][2] == 'X' && game[1][2] == 'X' && game[2][2] == 'X')
		return 'X';

	if (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X')
		return 'X';
	if (game[2][0] == 'X' && game[1][1] == 'X' && game[0][2] == 'X')
		return 'X';

	//Set win conditions for player 2
	//player 2's win conditions must be checked for all spaces
	if (game[0][0] == 'O' && game[0][1] == 'O' && game[0][2] == 'O')
		return 'O';
	if (game[1][0] == 'O' && game[1][1] == 'O' && game[1][2] == 'O')
		return 'O';
	if (game[2][0] == 'O' && game[2][1] == 'O' && game[2][2] == 'O')
		return 'O';

	if (game[0][0] == 'O' && game[1][0] == 'O' && game[2][0] == 'O')
		return 'O';
	if (game[0][1] == 'O' && game[1][1] == 'O' && game[2][1] == 'O')
		return 'O';
	if (game[0][2] == 'O' && game[1][2] == 'O' && game[2][2] == 'O')
		return 'O';

	if (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O')
		return 'O';
	if (game[2][0] == 'O' && game[1][1] == 'O' && game[0][2] == 'O')
		return 'O';

	return '/';
}

//The main function
int main()
{
	n = 0;
	//welcome message
	cout << "Welcome to Tic Tac Toe!" << endl;
	//calls tic tac toe board
	board();
	//repeats forever until someone wins
	while (1)
	{
		//Increment the value of n to display 'tie' message
		n++;
		//calls function to get input from user for each turn
		Input();
		//updates game board after each turn
		board();

		//check win condition after each turn to determine if the game continues
		if (winCondition() == 'X')
		{
			cout << "Player 1 wins!" << endl;
			//end while(1) after player 1 achieves victory
			break;
		}
		else if (winCondition() == 'O')
		{
			cout << "Player 2 wins!" << endl;
			//ends while(1) after player 2 achieves victory
			break;
		}
		else if (winCondition() == '/' && n == 9)
		{
			cout << "You tied the match!" << endl;
			break;
		}
		switchPlayers();
	}
	system("pause");
	return 0;
};