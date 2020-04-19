#include "node.h"
#include <iostream>

class tree {
 public:
  tree();
  void insert(int value, node * root);
  void print(int spaces, node * root);
  void repair(node * root);
  node * getHead();
 private:
  node * head;
};
