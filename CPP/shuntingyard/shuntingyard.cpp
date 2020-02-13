#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

/* Joyce Chen
 * 2/11/2020
 * Shunting-Yard Algorithm: binary expression tree and stack 
 */

// function prototypes
void removeHead(stackNode * head);
void addHead(stackNode * & head, char newOperand);
void printPrefix(treeNode * parent);
void printInfix(treeNode * parent);
void printPostfix(treeNode * parent);

struct stackNode {
  char operand;
  stackNode * next;
};

struct treeNode {
  char operand;
  int num;
  bool isOperand;
  treeNode * left;
  treeNode * right;
};

int main() {
  // give user instructions 
  cout << "- Welcome to Shunting Yard Algorithm -" << endl << endl;
  cout << "Use '+' for addition" << endl;
  cout << "Use '-' for subtraction" << endl;
  cout << "Use '*' for multiplication" << endl;
  cout << "Use '/' for division" << endl;
  cout << "Use '^' for power" << endl;

  // create stack head
  stackNode * head = new stackNode();
  head -> next = NULL;
  head -> operand = ' ';

  stack<treeNode*> binaryTree; // binary tree

  char * infix = new char(100);
  int value = 0;
  cout << "Infix: ";
  cin.getline(infix, 100); // read in inifx notation

  cout << "Postfix: "; // print inifx
  for (int i = 0; i < strlen(infix); i++)  { // run through
    if (infix[i] >= '1' && infix[i] <= '9') { 
      value = value * 10 + (infix[i] - '0');
    }
    else {
      if (infix[i] == ' ') { // empty space
	if (value > 0) {
	  cout << value << " ";
	  treeNode * number = new treeNode();
	  number -> left = NULL;
	  number -> right = NULL;
	  number -> isOperand = false;
	  number -> num = value;

	  binaryTree.push(num);
	}
	value = 0;
      }
      else if (infix[i] == '(') { // left parantehsis
	addHead(infix[a], head);
      }
      else if (infix[i] == ')') { // right paranthesis
	
      }
      else {

      }
    }
  }
  
  
    
  return 0;
}

void removeHead(stackNode * & head) {
  stackNode * temp = head -> next;
  delete head;
  head = temp;
}

void addHead(stackNode * & head, char newOperand) {
  stackNode * temp = new stackNode();
  temp -> operand = newOperand;
  temp -> next = head;
  head = temp;
}

void printPrefix(treeNode * parent) {
  if (parent != NULL) {
    if (parent -> isOperand == true) {
      cout << parent -> operand << " ";
    }
    else {
      cout << parent -> num << " ";
    }
    prefix(parent -> left);
    prefix(parent -> right);
  }
}

void printInfix(treeNode * parent) {
  if (parent != NULL) {
    if (parent -> isOperand == true) {
      cout << "( ";
    }
    infix(parent -> left);
    if (parent -> is Operand == true) {
      cout << parent -> operand << " ";
    }
    else {
      cout << parent -> number << " ";
    }
    infix(parent -> right);
    if (parent -> isOperand == true) {
      cout << ") ";
    }
  }
}

void printPostfix(treeNode * parent) {
  if (parent != NULL) {
    postfix(parent -> left);
    postfix(parent -> right);
    if (parent -> isOperand == true) {
      cout << parent -> operand << " ";
    }
    else {
      cout << parent -> number << " ";
    }
  }
}
