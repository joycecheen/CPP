#include "tree.h"
#include <iostream>

using namespace std;

tree::tree() {
  head = new node(0, 0, NULL, NULL, NULL);
}

node* tree::getHead() {
  return head;
}

void tree::insert(int value, node * root) {
  if (root->getValue() == 0) {
    root->setValue(value);
  }
  else if (value <= root->getValue()) {
    if (root->getLeft() == NULL) {
      node* temp = new node(value, 1, root, NULL, NULL);
      root->setLeft(temp);
      //fix(root->getLeft());
    }
    else {
      insert(value, root->getLeft());
    }
  }
  else {
    if (root->getRight() == NULL) {
      node* temp = new node(value, 1, root, NULL, NULL);
      root->setRight(temp);
      //fix(root->getRight());
    }
    else {
      insert(value, root->getRight());
    }
  }
}

void tree::print(int spaces, node * root) {
  if (root == NULL || root->getValue() == 0) {
    return;
  }
  print(spaces + 1, root->getRight());
  for (int a = 0; a < spaces; a++) {
    cout << "\t";
  }
  if (root->getColor() == 0) {
    cout << root->getValue() << " B" << endl;
  }
  else {
    cout << root->getValue() << " R" << endl;
  }
  print(spaces + 1, root->getLeft());
}

void tree::repair(node * root) {

}
