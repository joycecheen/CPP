#include <iostream>
#include <stdlib.h>
#include <cstring>

/*
 * Tic-Tac-Toe: Create a tictactoe game using the command line, it will be a two player game.
 * Author: Joyce Chen
 * Date : 10/01/2019
 */

using namespace std;

// declare methods
void printBoard(int grid[3][3]);
void clearBoard(int grid[3][3]);
bool checkWin(int grid[3][3], int player);
bool checkTie(int grid[3][3]);

const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

int main() {
  
  char move [5];
  int grid [3][3] = { 0 };
  int turn = X_TURN;
  int row = 0;
  int column = 0;

  int xcounter = 0;
  int ocounter = 0;
  int tcounter = 0;
  
  bool game = true;
  bool win = false;
  char response = ' ';

  while (game == true) { // if the player has not quit game
    bool q = true;
    turn = X_TURN;
    
    while (win == false) { // if no one has won/tied yet during this round
      cout << endl;
      printBoard(grid);
      cout << "Enter a letter for the row, and number for the column (eg. b3): "; // get player move 
      cin >> move;
      while (move[0] != 'a' && move[0] != 'b' && move[0] != 'c' ||
	     move[1] != '1' && move[1] != '2' && move[1] != '3') { // check if move is valid
	cout << "Please enter a valid move (eg. b3): ";
	cin >> move;
      } // if valid.. input move into grid
      column = (int)(move[1] - '1');
      row = (int)(move[0] - 'a');
      if (grid[row][column] == BLANK) {
        if (turn == X_TURN) {
	  grid[row][column] = X_MOVE;
          turn = O_TURN;
	}
        else {
	  grid[row][column] = O_MOVE;
          turn = X_TURN;
        }
      }
      else { // tell player if spot already has a move
	cout << "ILLEGAL  MOVE" << endl;
      }

      if (checkWin(grid, X_MOVE) == true || checkWin(grid, O_MOVE) == true
	  || checkTie(grid) == true) { // if there is a win or tie, tell player and add to score
	printBoard(grid);
	win = true;
	if (checkWin(grid, X_MOVE) == true) {
	  cout << "X WON!" << endl;
	  xcounter++;
	}
	else if (checkWin(grid, O_MOVE) == true) {
	  cout << "O WON!" << endl;
	  ocounter++;
	}
	else if (checkTie(grid) == true) {
	  cout << "TIE!" << endl;
	  tcounter++;
	}
      }
    }
    // output scores
    cout << "SCORES:  X - " << xcounter << endl;
    cout << "         O - " << ocounter << endl;
    cout << "         Ties - " << tcounter << endl;
      
    while (q == true) { // ask if player wants to play again
      cout << "Would you like to play again? (y or n)" << endl;
      cin >> response;
      if (response == 'n') { // if no, exit
	q = false;
	game = false;
	cout << "Thank you for playing!";
	exit(0);
      }
      else if (response == 'y') { // if yes, clear grid and moves
	q = false;
	win = false;
	clearBoard(grid);
	move[0] = ' ';
	move[1] = ' ';
      }
      else {
	cout << "Please enter y or n." << endl;
      }
    }
  }
  
  return 0;
}

bool checkWin(int grid[3][3], int player) { // method to check for win
  if (grid[0][0] == player && grid[0][1] == player && grid[0][2] == player) {
    return true;
  }
  if (grid[1][0] == player && grid[1][1] == player && grid[1][2] == player) {
    return true;
  }
  if (grid[2][0] == player && grid[2][1] == player && grid[2][2] == player) {
    return true;
  }
  if (grid[0][0] == player && grid[1][0] == player && grid[2][0] == player) {
    return true;
  }
  if (grid[0][1] == player && grid[1][1] == player && grid[2][1] == player) {
    return true;
  }
  if (grid[0][2] == player && grid[1][2] == player && grid[2][2] == player) {
    return true;
  }
  if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
    return true;
  }
  if (grid[2][0] == player && grid[1][1] == player && grid[0][2] == player) {
    return true;
  }
  return false;
}

bool checkTie(int grid[3][3]) { // method to check for tie
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (grid[row][column] == BLANK) {
	return false;
      }
    }
  }
  return true;
}

void printBoard(int grid[3][3]) { // method to output grid onto command line
  cout << "\t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    cout << (char)('a' + row) << "\t";
    for (int column = 0; column < 3; column++) {
      if (grid[row][column] == BLANK) {
	cout << "\t";
      }
      else if (grid[row][column] == X_MOVE) {
	cout << "X\t";
      }
      else if (grid[row][column] == O_MOVE) {
	cout << "O\t";
      }
    }
    cout << " " << endl; //new row
  }
  
  return;
}

void clearBoard(int grid[3][3]) { // method to clear grid
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      grid[row][column] = BLANK;
    }
  }

  return;
}
