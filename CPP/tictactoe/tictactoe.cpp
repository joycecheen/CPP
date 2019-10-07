#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

//void addMove(char grid [4][4], char move[2], int x, int y);
void printBoard(char grid[4][4]);

char move[2] = {};
  char grid[4][4] =
    {
      {' ', '1', '2', '3'},
      {'a', ' ', ' ', ' '},
      {'b', ' ', ' ', ' '},
      {'c', ' ', ' ', ' '}
    };
  int x;
  char y;

int main() {
  
  //boolean game = 0;

  printBoard(grid);
  //addMove(x,y);
  //while (game = 0) {
    cin.get(move,3);
    x = (move[0] - 48); 
    y = (move[1] - 'a' + 1);
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
      if (grid[y][x] == ' ') {
        grid[y][x] = 'X';

      }
      
    printBoard(grid); 
    //}
  
  return 0;
}

/*void addMove(char grid [4][4], char move[2], int x, int y) {
  cin.get(move,3);
  x = (move[0] - 48);
  y = move[1];
  y2 = y - 'a' + 1;
  grid[y2][x] = 'X';
    return;
}*/

void printBoard(char grid[4][4]) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  
  return;
}
