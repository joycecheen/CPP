#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>

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
void print(node * root, int spaces);
int convert(char * chardata, int * intdata);

int main() {
  bool run = true;
  char userinput[10];
  int intdata[100] = {};
  char chardata[100] = {};
  int n = 0;
  
  cout << "- Welcome to Binary Search Tree -" << endl;
  cout << "type INSERT to insert" << endl;
  cout << "type REMOVE to remove" << endl;
  cout << "type SEARCH to search" << endl;
  cout << "type PRINT to print" << endl;
  cout << "type QUIT to quit" << endl << endl;

  node * root = new node();
  //node * current = new node();
  
  while (run == true) {
    cin >> userinput;
    cin.ignore();
    
    if (strcmp(userinput, "INSERT") == 0) {
      char inputT[10];
      cout << "Type TYPE to input by terminal line" << endl;
      cout << "Type FILE to input by file" << endl;
      cin >> inputT;
      cin.ignore();

      if (strcmp(inputT, "TYPE") == 0) { // input through terminal
	intdata[100] = {}; // clear array

	cout << "Input: "; 
	cin.get(chardata, 100);

	n = convert(chardata, intdata);

	for (int i = 0; i < n; i++) {
	  insert(root, intdata[i]);
	}

	//insert(root, value)
      }

      else if (strcmp(inputT, "FILE") == 0) { // input through file
	char filename[20] = {};
	string line;
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

	for (int i = 0; i < n; i++) {
	  insert(root, intdata[i]);
	}
	//insert(root, value);
      }
    }
	
    else if (strcmp(userinput, "REMOVE") == 0) {

    }
	
    else if (strcmp(userinput, "SEARCH") == 0) {

    }
	
    else if (strcmp(userinput, "PRINT") == 0) {
      print(root, 0);
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
  if (root -> value == 0) {
    root -> value = value;
    return;
  }
  if (root -> value < value) {
    if (root -> right == NULL) {
      node * right = new node();
      right -> value = value;
      right -> left = NULL;
      right -> right = NULL;
      right -> parent = root;

      root -> right = right;
      return;
    }
    insert(root -> right, value);
  }
  else { // if no left node, input node at left
    if (root -> left == NULL) {
      node * left = new node();
      left -> value = value;
      left -> left = NULL;
      left -> right = NULL;
      left -> parent = root;
      root -> left = left;
      return;
    }
    insert(root -> left, value);
  }
}

void remove(node * & deleted) {

}

void search(node * root, int value) {

}

void print(node * root, int spaces) {
  if (root != NULL && root -> value == 0) {
    cout << "tree has no nodes" << endl;
  }
  if (root == NULL || root -> value == 0) {
    return;
  }
  print(root -> right, spaces + 1);
  for (int t = 0; t < spaces; t++) {
    cout << "\t";
  }
  cout << root -> value << endl;
  print(root -> left, spaces + 1);
}

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

      intdata[n] = num; // add
      n++;
    }
    
    /*
    if (current == NULL) { // if tree is empty
      node * temp = new node();
      temp -> value = num;
      //temp -> right = NULL;
      //remp -> left = NULL;
      root = temp;
      current = temp;
      }*/

    
    
  }
  
  return n;
}
