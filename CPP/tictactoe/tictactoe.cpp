#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

void addMove(char move[2], int x, int y);
void printBoard(char grid[4][4]);

int main() {
  char move[2] = {};
  char grid[4][4] =
    {
      {' ', '1', '2', '3'},
      {'a', ' ', ' ', ' '},
      {'b', ' ', ' ', ' '},
      {'c', ' ', ' ', ' '}
    };
  int x;
  int y;

  printBoard(grid);
  addMove(x,y); 
  /*cin.get(move,3);
  int x = (move[0] - 48); 
  int y = (move[1] - 'a' + 1);
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  grid[y][x] = 'X';
  printBoard(grid); */
  
  return 0;
}

void addMove(char move[2], int x, int y) {
  cin.get(move,3);
  int x = (move[0] - 48);
  int y = (move[1] - 'a' + 1);
  grid[y][x] = 'X';
    return;
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
