#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

//void addMove(char grid [4][4], char move[2], int x, int y);
void printBoard(char grid[4][4]);

const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;

int main() {
  
  char move[5];
  char grid[4][4] =
  {
    {' ', '1', '2', '3'},
    {'a', ' ', ' ', ' '},
    {'b', ' ', ' ', ' '},
    {'c', ' ', ' ', ' '}
  };
  int turn = X_TURN;
  int row = 0;
  int column = 0;

  //boolean game = 0;

  printBoard(char grid[4][4]);
  cout << "Enter a letter for the row, and number for the column: ";
  cin >> move;
  column = (int)(move[1] - '1' + 1);
  row = (int)(move[0] - 'a' + 1);
  cout << "row: " << row << endl;
  cout << "column: " << column << endl;
  if (grid[row][column] == ' ') {
     grid[row][column] = 'X';

  }
      
    printBoard(char grid[4][4]); 
  
  return 0;
}

void printBoard(char grid[4][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  
  return;
}
