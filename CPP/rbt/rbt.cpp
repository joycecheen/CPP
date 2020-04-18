#include "node.h"

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  bool run = true;
  char userinput[10];

  cout << "- Welcome to Red Black Tree (Insertion) -" << endl;
  cout << "type ADD to enter a single number" << endl;
  cout << "type READ to read in a file" << endl;
  cout << "type PRINT to print the tree" << endl;
  cout << "type QUIT to quit" << endl << endl;

  while (run == true) {
    cin >> userinput;
    cin.ignore();

    if (strcmp(userinput, "ADD") == 0) {
      int num;
      cout << "single number to insert into the tree: ";
      cin >> num;
      list -> insert(number, list -> getHead());
    }
    else if (strcmp(userinput, "READ") == 0) {
      char filename[20] = {};
      cout << "enter file name: "; // get file name
      cin >> filename;

      // open file
      ifstream file(filename);
      int c = 0;
      while (!file.eof()) {
	char digit;
	file >> digit;

	if (digit == ' ') {
	  list->insert(current, list->getHead());
          cout << "tree (sideways)" << endl;
          list->print(list->getHead(), 0);
          current = 0;
        }
        else {
	  current *= 10;
          current += (digit - '0');
        }	
      }
      current /= 10;
      list->insert(current, list->getHead());
      list->print(list->getHead(), 0);
    }
    else if (strcmp(userinput, "PRINT") == 0) {
      // print out tree
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
