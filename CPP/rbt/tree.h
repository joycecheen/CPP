#include "node.h"
#include <iostream>

class tree {
 public:
  tree();
  void insert(int value, node* root);
  void print(node* root, int spaces);
  void repair(node* root);
  node* getHead();
 private:
  node* head;
};
