#include "node.h"
#include "tree.h"
#include <iostream>
#include <cstring>
#include <fstream>

/* Red Black Tree Part 1 - Insertion: Create a Red-Black Tree
 * Name: Joyce Chen
 * Date: 4/20/20
 */

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
  cout << "type 'SEARCH' to check for a number in the tree" << endl;
  cout << "type 'REMOVE' to remove a particular number" << endl;
  cout << "type 'QUIT' to quit" << endl << endl;

  while (run == true) { // while user has not quit
    cin >> userinput;
    cin.ignore();

    if (strcmp(userinput, "ADD") == 0) { // add a single number to tree
      int num = 0;
      cout << "single number to insert into the tree: ";
      cin >> num;
      list -> insert(num, list -> getHead()); // insert
      cout << "ADDED \n\n";
    }
    else if (strcmp(userinput, "READ") == 0) { // read in file and add to tree sequentially
      char filename[20] = {};
      string line;
      cout << "enter file name: "; // get file name
      cin >> filename;

      // open file and copy file data into char array
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

        n = convert(chardata, intdata); // convert char array into int array
	
        for (int i = 0; i < n; i++) { // insert
          list -> insert(intdata[i], list -> getHead());
	}      
      cout << "ADDED \n\n";
    }
    else if (strcmp(userinput, "PRINT") == 0) { // print tree
      list -> print(list -> getHead(), 0);
      cout << "PRINTED \n\n";
    }
    else if (strcmp(userinput, "SEARCH") == 0) {
      int value = 0;
      cout << "please input value to search: ";
      cin >> value;

      if (list -> search(value, list -> getHead()) != NULL) {
        cout << value << "is in tree" << endl;
      }
      else {
	cout << value << "is not in tree" << endl;
      }
      
    }
    else if (strcmp(userinput, "REMOVE") == 0) {
      int value = 0;
      cout << "please input value to delete: ";
      cin >> value;

      // remove function

      cout << "REMOVED \n\n";
    }
    else if (strcmp(userinput, "QUIT") == 0) { // quit
      run = false;
    }
    else {
      cout << "not a valid command ^^ \n\n";
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
      if ((num < 1000) && (num > 0)) { // 1-999
        intdata[n] = num; // add to int arr
        n++;
      }
    }

  }

  return n;
}
