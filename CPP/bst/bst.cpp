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

void insert(node * root, int value);
void remove(node * & deleted);
void search(node * root, int value);
void remove(node * root, int space);
void convert(char * chardata, int * intdata);

int main() {
  bool run = true;
  char userinput[10];
  int intdata[100];
  char chardata[100];
  
  cout << "- Welcome to Binary Search Tree -" << endl;
  cout << "type INSERT to insert" << endl;
  cout << "type REMOVE to remove" << endl;
  cout << "type SEARCH to search" << endl;
  cout << "type PRINT to print" << endl;
  cout << "type QUIT to quit" << endl << endl;

  node * root = new node();
  
  while (run == true) {
    cin >> userinput;
    cin.ignore();
    
    if (strcmp(userinput, "INSERT") == 0) {
      char userT[10];
      cout << "Type TYPE to input by terminal line" << endl;
      cout << "Type FILE to input by file" << endl;
      cin >> inputT;
      cin.ignore();

      if (strcmp(input, "TYPE") == 0) { // input through terminal
	intdata[100] = {}; // clear array

	cout << "Input: "; 
	cin.getline(chardata, 100);

	//finish

	convert(chardata, intdata);
	insert(root, value)
      }

      else if (strcmp(input, "FILE") == 0) { // input through file
	char filename[20] = {};
	string line;
	filedata[100] = {};
	intdata[100] = {};

	cout << "Enter file name: "; // get file name
	cin >> filename;
	cin.get();

	// open file and copy file data into char array
	ifstream file (filename);
	if (file.is_open()) {
	  while (getline (file, line)) {
	    int a = 0;
	    while (line[a] != 0) {
	      intdata[a] = line[a];
	      a++;
	    }
	  }
	  file.close();
	}
	else {
	  cout << "cannot open file" << endl;
	}
	
	convert(chardata, intdata);
	insert(root, value);
      }
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

void insert(node * root, int value) {
  
}

void remove(node * & deleted) {

}

void search(node * root, int value) {

}

void remove(node * root, int space) {

}

void convert(char * chardata, int * intdata) {
  for (int i = 0; i < 400; i++) {
    if (filedata[i] == 0) {
      break;
    }
    if (n < 100) { // up to 100 stored numbers
      if (filedata[i] >= 48 && filedata[i] <= 57) { // add to int array if char is a num
	int num = filedata[i] - '0';

	while(filedata[i+1] >= 48 && filedata[i+1] <= 57) { // multi digit num
	  int temp = filedata[i+1] - '0';
	  num = (num * 10) + temp;
	  i++;
	}

	intdata[n] = num; // add
	n++;
      }
    }
  }
}
