#include "node.h"
#include <iostream>

// node constructor
node::node(int valueN, int colorN, node* leftN, node* rightN, node* parentN) {
  value = valueN;
  color = colorN;
  left = leftN;
  right = rightN;
  parent = parentN;
}

void node::setValue(int valueN) {
  value = valueN;
}

void node::setColor(int colorN) {
  color = colorN;
}

void node::setLeft(node * leftN) {
  left = leftN;
}

void node::setRight(node * rightN) {
  right = rightN;
}

void node::setParent(node * parentN) {
  parent = parentN;
}
