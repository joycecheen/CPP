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

// function prototypes
void insert(node * root, int value);
void remove(node * & d);
bool search(node * root, int s);
void print(node * root, int spaces);
int convert(char * chardata, int * intdata);
node* find(node * root, int value);
node* findSL(node * root);
node* findSR(node * root);

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
  
  while (run == true) {
    cin >> userinput;
    cin.ignore();
    
    if (strcmp(userinput, "INSERT") == 0) { // add number to tree
      char inputT[10];
      cout << "Type TYPE to input by terminal line" << endl;
      cout << "Type FILE to input by file" << endl;
      cin >> inputT;
      cin.ignore();

      if (strcmp(inputT, "TYPE") == 0) { // input through terminal
	intdata[100] = {};

	cout << "Input: "; 
	cin.get(chardata, 100);

	n = convert(chardata, intdata);

	for (int i = 0; i < n; i++) { // insert
	  insert(root, intdata[i]);
	}
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

	for (int i = 0; i < n; i++) { // insert
	  insert(root, intdata[i]);
	}	
      }
    }
	
    else if (strcmp(userinput, "REMOVE") == 0) { // remove from tree
      int value = 0;

      cout << "Value to delete: ";
      cin >> value;

      node * d = find(root, value); // find node with value to delete
      remove(d);
    }
	
    else if (strcmp(userinput, "SEARCH") == 0) { // search tree
      int s = 0;
      
      cout << "Value to search for: ";
      cin >> s;

      if (search(root, s) == true) {
	cout << s << " is in the tree" << endl;
      }
      else {
	cout << s << " is not in the tree" << endl;
      }
    }
	
    else if (strcmp(userinput, "PRINT") == 0) { // print tree
      print(root, 0);
    }
	
    else if (strcmp(userinput, "QUIT") == 0) { // quit
      run = false;
    }
	
    else {
      cout << "not a valid command ^^" << endl;
    }
	
  }
      
  return 0;
}

// insert number(s) into tree
void insert(node * root, int value) {
  if (root -> value == 0) { // no nodes in tree
    root -> value = value;
    return;
  }
  if (root -> value < value) { // if value is greater, goes on right
    if (root -> right == NULL) { // no right node
      node * right = new node();
      right -> value = value;
      right -> left = NULL;
      right -> right = NULL;
      right -> parent = root;

      root -> right = right;
      return;
    }
    insert(root -> right, value); // else transverse to right 
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
    insert(root -> left, value); // else transverse to left
  }
}

// logic of remove function (Hibbard delete algorithm) from: http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete.html
void remove(node * & d) {
  if (d == NULL) { // return if not in tree
    return;
  }
  // case 1: node has no children
  if (d -> left == NULL && d -> right == NULL) { 
    if (d -> parent == NULL) { // if parent, set node to null
      d -> value = 0;
      return;
    }
    if (d -> value <= d -> parent -> value) { // if node is on left of tree
      d -> parent -> left = NULL; // set left to null
    }
    else { // if on right of tree
      d -> parent -> right = NULL; // set right to null
    }
    delete d;
    d = NULL;
  }
  // case 2: node has one child
  else if (d -> left == NULL || d -> right == NULL) {
    if (d -> left == NULL) { // if child is on right
      node * temp = d -> right; 
      if (d -> parent == NULL) { // if root node, transfer right child data
	d -> value = temp -> value; 
	d -> right = temp -> right;
	d -> left = temp -> left;
	if (temp -> left != NULL) { 
	  temp -> left -> parent = d;
	}
	if (temp -> right != NULL) {
	  temp -> right -> parent = d;
	}
	delete temp;
      }
      else { // delete d and make right child new parent
	node * temP = d -> parent;
	delete d;
	if (temp -> value <= temP -> value) {
	  temP -> left = temp;
	}
	else {
	  temP -> right = temp;
	}
	temp -> parent = temP;
	}
    }
    else { // if child is on left
      node * temp = d -> left;
      if (d -> parent == NULL) { // if root node, transfer left child data
	d -> value = temp -> value;
	d -> right = temp -> right;
	d -> left = temp -> left;
	if (temp -> left != NULL) {
	  temp -> left -> parent = d;
	}
	if (temp -> right != NULL) {
	  temp -> right -> parent = d;
	}
	delete temp;
      }
      else { // delete d and make left child new parent
	node * temP = d -> parent;
	delete d;
	if (temp -> value <= temP -> value) {
	  temP -> left = temp;
	}
	else {
	  temP -> right = temp;
	}
	temp -> parent = temP;
      }
    } 
  }
  // case 3: node has two children
  else {
    node * s;
    if (d -> right != NULL) { // replace node's value w smallest node    
      s = findSR(d -> right); // found on right of tree
    }
    else { // replace node's value with largest node
      s = findSL(d -> left); // found on left of tree
    }
    int value = s -> value;
    remove(s);
    d -> value = value;
  }
}

// search function from geeksforgeeks:
// https://www.geeksforgeeks.org/iterative-searching-binary-search-tree/
bool search(node * root, int s) { // iterative search
  while (root != NULL) {
    if (root -> value < s) {
      root = root -> right;
    }
    else if (root -> value > s) {
      root = root -> left;
    }
    else {
      return true;
    }
  }
  return false;
}

// print tree showing parent child relationships
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

// find node with given value (used for remove function)
node* find(node * root, int value) {
  if (root == NULL || root -> value == value) {
    return root;
  }
  if (root -> value > value) {
    return find(root -> left, value);
  }
  return find(root -> right, value);
}

// find the smallest node on the right side of tree
node* findSR(node * root) {
  if (root -> left == NULL) {
    return root;
  }
  
  return findSR(root->left);
}

// find the largest node on the left side of tree
node* findSL(node * root) {
  if (root -> right == NULL) {
    return root;
  }
  
  return findSL(root->right);
}
