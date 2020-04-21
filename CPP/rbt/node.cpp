#include "node.h"
#include <iostream>

/*
 * node functions
 */

node::node(int valueN, int colorN, node* parentN, node* leftN, node* rightN) { // node constructor
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

void node::setLeft(node* leftN) {
  left = leftN;
}

void node::setRight(node* rightN) {
  right = rightN;
}

void node::setParent(node* parentN) {
  parent = parentN;
}

int node::getValue() {
  return value;
}

int node::getColor() {
  return color;
}

node* node::getParent() {
  return parent;
}

node* node::getLeft() {
  return left;
}

node* node::getRight() {
  return right;
}

node* node::getGrandparent() {
  return parent -> getParent();
}

node* node::getUncle() {
  if (parent->getValue() > getGrandparent()->getValue()) {
    return getGrandparent()->getLeft();
  }
  return getGrandparent()->getRight();
}
