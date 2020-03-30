#include "node.h"
#include <iostream>

class tree {
 public:
  void insert(int value, node * root);
  void print(int spaces, node * root);
  void repair(node * root);
 private:
  node * head;
};
