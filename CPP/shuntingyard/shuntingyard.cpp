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
  
  
  return 0;
}
