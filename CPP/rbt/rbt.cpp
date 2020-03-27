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
      // add function
    }
    else if (strcmp(userinput, "READ") == 0) {
      char filename[20] = {};
      cout << "enter file name: "; // get file name
      cin >> filename;

      // open file
      ifstream file (filename);
      if (file.is_open()) {
	
        // add file data to tree

	file.close();
      }
      else {
	cout << "cannot open file" << endl;
      }

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
