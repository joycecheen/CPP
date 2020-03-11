#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

/* Binary Search Tree: Create a program that creates a binary search tree. The program should 
 *                     read in a series of numbers (either from the console or from a file) 
 *                     between 1 and 1000, separated by a single space, and it should correctly
 *         :p          place them in the tree. You should also be able to remove particular 
 *                     numbers from the tree and update it correctly. You should be able to 
 *                     enter a number and ask if it is in the tree (search). Finally, you 
 *                     should create a visual way of representing the tree.
 * Name: Joyce Chen
 * Date: 3/11/2020
 */

struct node{
  node * left;
  node * right;
  node * parent;
  int value;
};

void insert();
void remove();
void search();
void remove();

int main() {
  bool run = true;
  char userinput[10];
  
  cout << "- Welcome to Binary Search Tree -" << endl;
  cout << "type INSERT to insert" << endl;
  cout << "type REMOVE to remove" << endl;
  cout << "type SEARCH to search" << endl;
  cout << "type PRINT to print" << endl;
  cout << "type QUIT to quit" << endl << endl;

  while (run == true) {					 
    cin >> userinput;
    cin.ignore();
    if (strcmp(userinput, "INSERT") == 0) {
      
    }
    else if (strcmp(userinput, "REMOVE") == 0) {

    }
    else if (strcmp(userinput, "SEARCH") == 0) {

    }
    else if (strcmp(userinput, "PRINT") == 0) {

    }
    else if (strcmp(userinput, "QUIT") == 0) {
      run = false;
    }
    else {
      cout << "not a valid command ^^" << endl;
    }
  }
  return 0;
}

void insert() {
  char inputT[10];
  
  cout << "type CONSOLE to input from console" << endl;
  cout << "type FILE to input from file" << endl;
  cin >> inputT;

  if (strcmp(inputT, "CONSOLE") == 0) {
    
  }
  else if (strcmp(inputT, "FILE") == 0) {
    char filename[20];
    string line;
    char filedata[100] = {};

    cout << "enter file name: ";
    cin >> filename;
    cin.get();

    ifstream file(filename);
    if (file.is_open()) {
      while (getline (file, line)) {
	int a = 0;
	while (line[a] != 0) {
	  filedata[a] = line[a];
	  a++;
	}
      }
      file.close();
    }
    else {
      cout << "cannot open file" << endl;
    }
  }
  else {
    cout << "not a valid command ^^" << endl;
  }
  
}
