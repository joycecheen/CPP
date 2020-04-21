#include "tree.h"
#include <iostream>

/*
 * tree functions
 * source : https://www.geeksforgeeks.org/red-black-tree-set-2-insert/
 */

using namespace std;

tree::tree() { // constructor
  head = new node(0, 0, NULL, NULL, NULL);
}

node* tree::getHead() { // get head
  return head;
}

//checks if node is a left child or right child
bool isLeft(node* root) {  
  if (root -> getParent() -> getValue() >= root -> getValue()) {
    return true;
  }
  else {
    return false;
  }
}

void tree::insert(int value, node * root) { // insert node then fix to red black tree
  if (root -> getValue() == 0) {
    root -> setValue(value);
  }
  else if (value <= root -> getValue()) {
    if (root -> getLeft() == NULL) {
      node* temp = new node(value, 1, root, NULL, NULL);
      root -> setLeft(temp);
      repair(root -> getLeft());
    }
    else {
      insert(value, root -> getLeft());
    }
  }
  else {
    if (root->getRight() == NULL) {
      node* temp = new node(value, 1, root, NULL, NULL);
      root -> setRight(temp);
      repair(root -> getRight());
    }
    else {
      insert(value, root -> getRight());
    }
  }
}

void tree::print(node *root, int spaces) { // print out visual representation of tree
  if (root == NULL || root -> getValue() == 0) {
    return;
  }
  print(root -> getRight(), spaces + 1);
  for (int a = 0; a < spaces; a++) {
    cout << "\t";
  }
  if (root -> getColor() == 0) {
    cout << root->getValue() << " B" << endl;
  }
  else {
    cout << root -> getValue() << " R" << endl;
  }
  print(root -> getLeft(), spaces + 1);
}

void tree::repair(node * root) { // update tree so it is a red black tree
  if (root -> getParent() == NULL) { // root is black
    root -> setColor(0);
  }
  if (root -> getParent() == NULL || root -> getGrandparent() == NULL) { 
    return;
  }
  if (root -> getUncle() != NULL && root -> getUncle() -> getColor() == 1 && root -> getParent() -> getColor() == 1) { // if uncle & parent are red, update
    root -> getParent() -> setColor(0);
    root -> getUncle() -> setColor(0);
    root -> getGrandparent() -> setColor(1);
    repair(root -> getGrandparent()); // recursively fix tree with grandparent
  }
  else if (root->getParent() -> getColor() == 1) { // if parent is red and uncle is NULL or black
    node* gG = root -> getGrandparent() -> getParent(); // gG = great-grandparent
    node* grandparent = root -> getGrandparent();
    
    if (isLeft(root) && isLeft(root->getParent())) { // if left left case, update
      node* temp = new node(grandparent->getValue(), 1, root -> getParent(), root -> getParent() -> getRight(), root -> getUncle());
      if (gG == NULL) {
	delete head;
	head = root -> getParent();
	head -> setParent(NULL);
	head -> setRight(temp);
	head -> setColor(0);
      }
      else {
	root -> getParent() -> setParent(gG);
	if (isLeft(root -> getParent())) {
	  gG -> setLeft(root -> getParent());
	}
	else {
	  gG -> setRight(root -> getParent());
	}
	delete grandparent;
	root -> getParent() -> setRight(temp);
	root -> getParent() -> setColor(0);
      }
    }
    else if (!isLeft(root) && isLeft(root -> getParent())) { // if left right case, update 
      node* temp = new node(grandparent -> getValue(), 1, root, root -> getRight(), root -> getUncle());
      node* left = root -> getLeft();
      root -> setLeft(root -> getParent());
      root -> getLeft() -> setRight(left);
      root -> getLeft() -> setParent(root);
      root -> setParent(grandparent);
      if (left != NULL) {
	left -> setParent(root -> getLeft());
      }
      grandparent -> setLeft(root);

      root = root -> getLeft();
      if (gG == NULL) { 
	delete head;
	head = root -> getParent();
	head -> setParent(NULL);
	head -> setRight(temp);
	head -> setColor(0);
      }
      else {
	root -> getParent() -> setParent(gG);
	if (isLeft(root -> getParent())) {
	  gG -> setLeft(root -> getParent());
	}
	else {
	  gG -> setRight(root -> getParent());
	}
	delete grandparent;
	root->getParent() -> setRight(temp);
	root->getParent() -> setColor(0);
      }
    } 
    else if (!isLeft(root) && !isLeft(root -> getParent())) { // if right right case, update
      node *temp = new node(grandparent -> getValue(), 1, root -> getParent(), root -> getUncle(), root -> getParent() -> getLeft());
      if (gG == NULL) {
	delete head;
	head = root -> getParent();
	head -> setParent(NULL);
	head -> setLeft(temp);
	head -> setColor(0);
      }
      else {
	root -> getParent() -> setParent(gG);
	if (isLeft(root -> getParent())) {
	  gG -> setLeft(root -> getParent());
	}
	else {
	  gG -> setRight(root -> getParent());
	}
	delete grandparent;
	root -> getParent() -> setLeft(temp);
	root -> getParent() -> setColor(0);
      }
    }
    else if (isLeft(root) && !isLeft(root -> getParent())) { // if right left case, update
      node* temp = new node(grandparent -> getValue(), 1, root, root -> getUncle(), root -> getLeft());
      node* right = root -> getRight();
      root -> setRight(root -> getParent());
      root -> getRight() -> setLeft(right);
      if (right != NULL) {
	right -> setParent(root -> getRight());
      }
      root -> getRight() -> setParent(root);
      root -> setParent(grandparent);
      grandparent -> setRight(root);

      root = root -> getRight();
      if (gG == NULL) {
	delete head;
	head = root -> getParent();
	head -> setParent(NULL);
	head -> setLeft(temp);
	head -> setColor(0);
      }
      else {
	root -> getParent() -> setParent(gG);
	if (isLeft(root -> getParent())) {
	  gG -> setLeft(root -> getParent());
	}
	else {
	  gG -> setRight(root -> getParent());
	}
	delete grandparent;
	root -> getParent() -> setLeft(temp);
	root -> getParent() -> setColor(0);
      }
    }
  }
}
