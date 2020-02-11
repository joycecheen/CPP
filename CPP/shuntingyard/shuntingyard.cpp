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
void addHead(stackNode * head, char newOperand);
void prefix(treeNode * parent);
void infix(treeNode * parent);

struct stackNode {
  char operand;
  stackNode * next;
};

struct treeNode {
  char operand;
  int num;
  bool isOp;
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

  stack<treeNode*> binaryTree;

  char * infix = new char(100);
  int c = 0;
  cout << "Infix: ";
  cin.getline(infix, 100); // read in inifx notation

  cout << "Postfix: ";
  for (int i = 0; i < strlen(infix); i++)  { // run through
    if (infix[i] >= '1' && infix[i] <= '9') { 
      c += initial; 
    }
    else {
      if (infix[i] == ' ') { // empty space
	
      }
      else if (infix[i] == '(') { // left parantehsis

      }
      else if (infix[i] == ')') { // righgt paranthesis

      }
    }
  }
  
  
    
  return 0;
}
