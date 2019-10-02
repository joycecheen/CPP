#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

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

  printBoard(grid);

  cin.get(move,3);
  for (int z = 0; z < 2; ++z) {
    cout << move[z] << endl;
  }
  int y = (move[1] - 'a' + 1);
  cout << (move[0])+1 << endl;
  cout << y + 1 << endl;
  grid[move[0]+1][y] = 'X';
  printBoard(grid);
  
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
