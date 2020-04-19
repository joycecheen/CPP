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
      string line;
      cout << "enter file name: "; // get file name
      cin >> filename;

      ifstream file (filename);
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

        for (int i = 0; i < n; i++) { // insert
          list -> insert(intdata[i], list -> getHead());
        }
      
      /*
      // open file
      ifstream file(filename);
      int c = 0;
      while (!file.eof()) {
	char digit;
	file >> digit;

	if (digit == ' ') {
	  list->insert(c, list->getHead());
          cout << "tree (sideways)" << endl;
          list->print(list->getHead(), 0);
          c = 0;
        }
        else {
	  c *= 10;
          c += (digit - '0');
        }	
      }
      c /= 10;
      list->insert(c, list->getHead());
      list->print(list->getHead(), 0);
      */
    }
    else if (strcmp(userinput, "PRINT") == 0) {
      list -> print(0, list -> getHead());
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

// turn read in char arr into int arr, also return number of values
int convert(char * chardata, int * intdata) {
  int n = 0;
  for (int i = 0; i < strlen(chardata); i++) {
    if (chardata[i] >= 48 && chardata[i] <= 57) { // add to int array if char is a num
      int num = chardata[i] - '0';

      while(chardata[i+1] >= 48 && chardata[i+1] <= 57) { // multi digit num
        int tempI = chardata[i+1] - '0';
        num = (num * 10) + tempI;
        i++;
      }
      if ((num < 1000) && (num > 0)) {
        intdata[n] = num; // add to int arr
        n++;
      }
    }

  }

  return n;
}
