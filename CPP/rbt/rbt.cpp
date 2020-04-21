#include "node.h"
#include "tree.h"

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int convert(char * chardata, int * intdata);

int main() {
  bool run = true;
  char userinput[10];
  int intdata[100] = {};
  char chardata[100] = {};
  int n = 0;
  
  tree * list = new tree();
  
  cout << "- Welcome to Red Black Tree (Insertion) -" << endl;
  cout << "type 'ADD' to enter a single number" << endl;
  cout << "type 'READ' to read in a file" << endl;
  cout << "type 'PRINT' to print the tree" << endl;
  cout << "type 'QUIT' to quit" << endl << endl;

  while (run == true) {
    cin >> userinput;
    cin.ignore();

    if (strcmp(userinput, "ADD") == 0) {
      int num = 0;
      cout << "single number to insert into the tree: ";
      cin >> num;
      list -> insert(num, list -> getHead());
    }
    else if (strcmp(userinput, "READ") == 0) {
      char filename[20] = {};
      //string line;
      cout << "enter file name: "; // get file name
      cin >> filename;

      /*ifstream file (filename);
        if (file.is_open()) {
          while (getline (file, line)) {
            int a = 0;
            while (line[a] != 0) {
              chardata[a] = line[a];
              a++;
            }
          }
          file.close();
        }
        else {
          cout << "cannot open file" << endl;
        }

        n = convert(chardata, intdata);

	/*
	cout << "N: " << n << endl;
	for (int i = 0; i < n; i++) {
	  cout << intdata[i] << " ";
	  }*/
	
      /*  for (int i = 0; i < n; i++) { // insert
          list -> insert(intdata[i], list -> getHead());
	}*/
      
      // open file
      ifstream fin(filename);
      int c = 0;
      while (!fin.eof()) {
	char digit;
	fin >> digit;
	if (digit == ',') {
	  list -> insert(c, list->getHead());
	  cout << "tree (sideways)" << endl;
          list -> print(list->getHead(), 0);
          c = 0;
        }
        else {
	  c *= 10;
          c += (digit - '0');
        }	
      }
      c /= 10;
      cout << "tree (sideways)" << endl;
      list->insert(c, list->getHead());
      list->print(list->getHead(), 0);
      
      cout << "INSERTED" << endl;
    }
    else if (strcmp(userinput, "PRINT") == 0) {
      list -> print(list -> getHead(), 0);
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
