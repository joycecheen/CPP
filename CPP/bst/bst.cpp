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
      }
    }
	
    else if (strcmp(userinput, "REMOVE") == 0) {
      int value = 0;

      cout << "Value to delete: ";
      cin >> value;

      node * d = find(root, value);
      remove(d);
    }
	
    else if (strcmp(userinput, "SEARCH") == 0) {
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

void remove(node * & d) {
  if (d == NULL) { // return if not in tree
    return;
  }
  // case 1: node has no children
  if (d -> left == NULL && d -> right == NULL) { 
    if (d -> parent == NULL) {
      d -> value = 0;
      return;
    }
    if (d -> value <= d -> parent -> value) {
      d -> parent -> left = NULL;
    }
    else {
      d -> parent -> right = NULL;
    }
    delete d;
    d = NULL;
  }
  // case 2: node has one child
  else if (d -> left == NULL || d -> right == NULL) {
    if (d -> left == NULL) {
      node * temp = d -> right;
      if (d -> parent == NULL) {
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
      else {
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
    else {
      node * temp = d -> left;
      if (d -> parent == NULL) {
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
      else {
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
    if (d -> right != NULL) {    
      s = findSR(d -> right);
    }
    else {
      s = findSL(d -> left);
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
    
  }
  
  return n;
}

node* find(node * root, int value) {
  if (root == NULL || root -> value == value) {
    return root;
  }
  if (root -> value > value) {
    return find(root -> left, value);
  }
  return find(root -> right, value);
}

//used to find the smallest node on the right side of tree
node* findSR(node * root) {
  if (root -> left == NULL) {
    return root;
  }
  
  return findSR(root->left);
}

//used to find the largest node on the left side of tree
node* findSL(node * root) {
  if (root -> right == NULL) {
    return root;
  }
  
  return findSL(root->right);
}
