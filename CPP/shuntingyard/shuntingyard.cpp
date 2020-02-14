#include <iostream>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

/* Joyce Chen
 * 2/11/2020
 * Shunting-Yard Algorithm: binary expression tree and stack and queue 
 */

struct stackNode { // node for stack
  char operand;
  stackNode * next;
};

struct treeNode { // node for binary expression tree
  char operand;
  int num;
  bool isOperand;
  treeNode * left;
  treeNode * right;
};

// function prototypes
void removeHead(stackNode * & head); 
void addHead(stackNode * & head, char newOperand);
void printPrefix(treeNode * parent);
void printInfix(treeNode * parent);
void printPostfix(treeNode * parent);

int main() {
  
  // user instructions 
  cout << "- Welcome to Shunting Yard Algorithm -" << endl << endl;
  cout << "Use '+' for addition" << endl;
  cout << "Use '-' for subtraction" << endl;
  cout << "Use '*' for multiplication" << endl;
  cout << "Use '/' for division" << endl;
  cout << "Use '^' for power" << endl << endl;

  // create stack head
  stackNode * head = new stackNode();
  head -> next = NULL;
  head -> operand = ' ';

  stack<treeNode*> expressionTree; // expression tree

  // set order of precedence for operators
  map<char, int> precedence;
  precedence['^'] = 3;
  precedence['*'] = 2;
  precedence['/'] = 2;
  precedence['+'] = 1;
  precedence['-'] = 1;

  // set operator associativity (left or right)
  map<char, char> associativity;
  associativity['^'] = 'r';
  associativity['*'] = 'l';
  associativity['/'] = 'l';
  associativity['+'] = 'l';
  associativity['-'] = 'l';

  // read in mathematical expression in infix notation
  char * infix = new char(100);
  int value = 0; // keep track of multiple digit numbers
  cout << "Input mathematical expression: ";
  cin.getline(infix, 100);

  cout << "Postfix notation: "; // print postfix expression first 
  for (int i = 0; i < strlen(infix); i++)  { // run through expression
    if (infix[i] >= '1' && infix[i] <= '9') { // if number, add to value
      value = value * 10 + (infix[i] - '0');
    }
    else {
      if (infix[i] == ' ') { // if empty space
	if (value > 0) { // print out number and create tree node
	  cout << value << " ";
	  treeNode * number = new treeNode();
	  number -> left = NULL;
	  number -> right = NULL;
	  number -> isOperand = false;
	  number -> num = value;

	  expressionTree.push(number);
	}
	value = 0; // reset value
      }
      else if (infix[i] == '(') { // if left parenthesis
	addHead(head, infix[i]);
      }
      else if (infix[i] == ')') { // if right parenthesis
	stackNode * temp = head; 
	
	while (temp -> operand != '(') { 
	  cout << temp -> operand << " ";

	  // create tree node with top two nodes of expression tree stack
	  treeNode * two = expressionTree.top();
	  expressionTree.pop();
	  treeNode * one = expressionTree.top();
	  expressionTree.pop();

	  treeNode *expression = new treeNode();
	  expression -> left = one;
	  expression -> right = two;
	  expression -> isOperand = true;
	  expression -> operand = temp -> operand;

	  expressionTree.push(expression);
	  removeHead(temp);
	}
	head = temp -> next;
	delete temp;
      }
      else {
	// loop returning operands til stack matches 
	while (head -> operand != ' ' && head -> operand != '(' && ((precedence[infix[i]]
	       < precedence[head -> operand]) || (precedence[infix[i]] == precedence[head
	       -> operand] && associativity[infix[i]] == 'l'))) {
	  cout << head -> operand << " ";
					
	  // combine the top two nodes of stack
	  treeNode *second = expressionTree.top();
	  expressionTree.pop();
	  treeNode *first = expressionTree.top();
	  expressionTree.pop();

	  treeNode *expression = new treeNode();
	  expression -> left = first;
	  expression -> right = second;
	  expression -> isOperand = true;
	  expression -> operand = head->operand;			      					expressionTree.push(expression);

	  removeHead(head);
	}
	addHead(head, infix[i]);
      }
    }
  }

  // if there is remaining value, return it
  if (value != 0) {
    cout << value << " ";

    treeNode *number = new treeNode();
    number->left = NULL;
    number->right = NULL;
    number->isOperand = false;
    number->num = value;

    expressionTree.push(number); 
  }

  // return all the remaining operands
  while (head->next != NULL) {
    cout << head->operand << " ";
		
    treeNode *second = expressionTree.top();
    expressionTree.pop();
    treeNode *first = expressionTree.top();
    expressionTree.pop();

    treeNode *expression = new treeNode();
    expression->left = first;
    expression->right = second;
    expression->isOperand = true;
    expression->operand = head->operand;

    expressionTree.push(expression);
	
    removeHead(head);
  }
	
  // output infix, prefix, and postfix notation from the expression tree
  char response[10];
  bool run = true;
  
  cout << endl << endl << "Type Quit to quit" << endl;

  while (run == true) {
    cout << endl << "Please enter notation type to print (Infix, Prefix, Postfix): ";
    cin >> response;

    if (strcmp(response, "Infix") == 0) { // infix
      cout << "Infix notation: ";
      printInfix(expressionTree.top());
    }
    else if (strcmp(response, "Prefix") == 0) { // prefix
      cout << "Prefix notation: ";
      printPrefix(expressionTree.top());
    }
    else if (strcmp(response, "Postfix") == 0) { // postfix
      cout << "Postfix notation: ";
      printPostfix(expressionTree.top());
    }
    else if (strcmp(response, "Quit") == 0) { // quit
      run = false;
    }
    cout << endl;
  }
    
  return 0;
}

// remove top node in stack
void removeHead(stackNode * & head) {
  stackNode * temp = head -> next;
  delete head;
  head = temp;
}

// add node to top of stack
void addHead(stackNode * & head, char newOperand) {
  stackNode * temp = new stackNode();
  temp -> operand = newOperand;
  temp -> next = head;
  head = temp;
}

// print prefix notation from expression tree
void printPrefix(treeNode * parent) {
  if (parent != NULL) {
    if (parent -> isOperand == true) {
      cout << parent -> operand << " ";
    }
    else {
      cout << parent -> num << " ";
    }
    printPrefix(parent -> left);
    printPrefix(parent -> right);
  }
}

// print infix notation from expression tree
void printInfix(treeNode * parent) {
  if (parent != NULL) {
    if (parent -> isOperand == true) {
      cout << "( ";
    }
    printInfix(parent -> left);
    if (parent -> isOperand == true) {
      cout << parent -> operand << " ";
    }
    else {
      cout << parent -> num << " ";
    }
    printInfix(parent -> right);
    if (parent -> isOperand == true) {
      cout << ") ";
    }
  }
}
 
// print postfix notation from expression tree
void printPostfix(treeNode * parent) {
  if (parent != NULL) {
    printPostfix(parent -> left);
    printPostfix(parent -> right);
    if (parent -> isOperand == true) {
      cout << parent -> operand << " ";
    }
    else {
      cout << parent -> num << " ";
    }
  }
}
