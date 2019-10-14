#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

void printBoard(int grid[3][3]);
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

  bool game = true;
  bool win = false;
  char response = ' ';

  while (game == true) {
    while (win == false) {
      cout << endl;
      printBoard(grid);
      cout << "Enter a letter for the row, and number for the column: ";
      cin >> move;
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
      else {
	cout << "ILLEGAL  MOVE" << endl;
      }

      if (checkWin(grid, X_MOVE) == true || checkWin(grid, O_MOVE) == true
	  || checkTie(grid) == true) {
	win = true;
      }
    }
    if (checkWin(grid, X_MOVE) == true) {
      cout << "X wins!";
    }
    else if (checkWin(grid, O_MOVE) == true) {
      cout << "O wins!";
    }
    else if (checkTie(grid) == true) {
      cout << "Tie!";
    }
  }
  bool q = true;
  while (q = true) {
    cout << "Would you like to play again? (y or n)" << endl;
    cin >> response;
    if (response == 'n') {
      q = false;
      game = false;
      exit(0);
    }
    else if (response == 'y') {
      q = false;
      int grid [3][3] = { 0 };
    }
    else {
      cout << "Please enter y or n!" << endl;
    }
  }
    
  return 0;
}

bool checkWin(int grid[3][3], int player) {
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

bool checkTie(int grid[3][3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (grid[row][column] == BLANK) {
	return false;
      }
    }
  }
  return true;
}

void printBoard(int grid[3][3]) {
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

