#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

struct stackNode {
  char op;
  stackNode * next;
};

struct treeNode {
  char op;
  int num;
  bool isOp;
  treeNode * left;
  treeNode * right;
};

int main() {

  cout << "- Welcome to Shunting Yard Algorithm -" << endl << endl;
  cout << "Use '+' for addition" << endl;
  cout << "Use '-' for subtraction" << endl;
  cout << "Use '*' for multiplication" << endl;
  cout << "Use '/' for division" << endl;
  cout << "Use '^' for power" << endl;

  stackNode * head = new stackNode();
  head -> next = NULL;
  head -> op = ' ';

  stack<treeNode*> binaryTree;

  char * infix = new char(100);
  int c = 0;
  cout << "Infix: ";
  cin.getline(infix, 100);

  cout << "Postfix: ";
  for (int i = 0; i < strlen(infix); i++) {
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
