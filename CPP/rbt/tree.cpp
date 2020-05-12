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
  if (root -> getParent() == NULL) { // if root is black
    root -> setColor(0);
  }
  if (root -> getParent() == NULL || root -> getGrandparent() == NULL) { // if NULL
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

node* findSuccessor(node* root) {
  if (root -> getRight() == NULL) {
    return root;
  }
  return findSuccessor(root -> getRight());
}

// source: https://www.codesdope.com/course/data-structures-red-black-trees-deletion/
void tree::remove(node* root) {
  if (root -> getColor() >= 2) { // node is double black
    if (root -> getParent() == NULL) { // not root
      if (root -> getColor() == 2) {
	head -> setValue(0);
	head -> setParent(NULL);
      
	head -> setLeft(NULL);
	head -> setColor(0);
	head -> setRight(NULL);
	return;
      }
      else { // root
	root -> setColor(0);
	return;
      }
    }
    else if (root -> getSibling() != NULL && root -> getSibling() -> getColor() == 0 && root -> getSibling() -> getRSon() != NULL){ // if sibling is black and has red child
      if (isLeft(root -> getSibling()) && isLeft(root -> getSibling() -> getRSon())) { // left left
	if (root -> getGrandparent() == NULL) { // parent is top node
	  root -> getSibling() -> setColor(head -> getColor());
	  root -> getParent() -> setColor(0);
	  head = root -> getSibling();
	  head -> setParent(NULL);
	  node* right = head -> getRight();
	  head -> setRight(root -> getParent());
	  root -> getParent() -> setParent(head);
	  head -> getLeft() -> setColor(0);
	  if (right != NULL) {
	    right -> setParent(root -> getParent());
	  }
	  root -> getParent() -> setLeft(right);
	  root -> getParent() -> setRight(NULL);
	  if (root -> getColor() == 2) {
	    delete root;
	  }
	  else {
	    root -> setColor(root -> getColor() - 10);
	  }
	}
	else { 
	  root -> getSibling() -> setColor(root -> getParent() -> getColor());
	  root -> getParent() -> setColor(0);
	  if (isLeft(root -> getParent())) {
	    root -> getGrandparent() -> setLeft(root -> getSibling());
	  }
	  else {
	    root -> getGrandparent() -> setRight(root -> getSibling());
	  }
	  root->getSibling() -> setParent(root -> getGrandparent());
	  node* right= root -> getSibling() -> getRight();
	  root -> getParent() -> setParent(root -> getSibling());
	  root -> getParent() -> setLeft(NULL);
	  root -> getGrandparent()->setRight(root -> getParent());
	  root -> getGrandparent() -> getLeft() -> setColor(0);
	  if (right != NULL) {
	    right -> setParent(root -> getParent());
	  }
	  root -> getParent() -> setLeft(right);
	  root -> getParent() -> setRight(NULL);
	  if (root -> getColor() == 2) {
	    delete root;
	  }
	  else {
	    root -> setColor(root -> getColor() - 10);
	  }
	}
      }
      else if (isLeft(root -> getSibling()) && !isLeft(root -> getSibling() -> getRSon())) { // sibling and sibling's child is left right
	node* sibling = root -> getSibling();
	root -> getParent() -> setLeft(sibling -> getRSon());
	sibling -> getRSon() -> setLeft(sibling);
	sibling -> setParent(sibling -> getRSon());
	sibling -> getParent() -> setParent(root -> getParent());
	sibling -> setLeft(NULL);
	sibling -> setRight(NULL);
	
	root -> getSibling() -> setColor(0);
	root -> getSibling() -> getLeft() -> setColor(1);
	remove(root);
      }
      // sibling and sibling's child is right right
      else if (!isLeft(root -> getSibling()) && !isLeft(root -> getSibling() -> getRSon())) {
	if (root -> getGrandparent() == NULL) { // parent is head
	  root -> getSibling() -> setColor(head -> getColor());
	  root -> getParent() -> setColor(0);
	 
	  head = root -> getSibling();
	  head -> setParent(NULL);
	  node* left = head -> getLeft();
	  head -> setLeft(root -> getParent());
	  root -> getParent() -> setParent(head);
	  head -> getRight() -> setColor(0);
	  if (left != NULL) {
	    left -> setParent(root -> getParent());
	  }
	  root -> getParent() -> setRight(left);
	  root -> getParent() -> setLeft(NULL);
	  if (root -> getColor() == 2) {
	    delete root;
	  }
	  else {
	    root -> setColor(root -> getColor() - 10);
	  }
	}
	else {
	  root -> getSibling() -> setColor(root -> getParent() -> getColor());
	  root -> getParent() -> setColor(0);
	  if (isLeft(root -> getParent())) {
	    root -> getGrandparent() -> setLeft(root -> getSibling());
	  }
	  else {
	    root -> getGrandparent() -> setRight(root -> getSibling());
	  }
	  root -> getSibling() -> setParent(root -> getGrandparent());
	  node* left = root -> getSibling() -> getLeft();
	  root -> getParent() -> setParent(root -> getSibling());
	  root -> getParent() -> setRight(NULL);
	  root -> getGrandparent() -> setLeft(root -> getParent());
	  root -> getGrandparent() -> getRight() -> setColor(0);
	  if (left != NULL) {
	    left -> setParent(root -> getParent());
	  }
	  root -> getParent() -> setRight(left);
	  root -> getParent() -> setLeft(NULL);
	  if (root -> getColor() == 2) {
	    delete root;
	  }
	  else {
	    root -> setColor(root -> getColor() - 10);
	  }
	}
      }
      else if (!isLeft(root -> getSibling()) && isLeft(root -> getSibling() -> getRSon())) { // sibling and sibling's child is right left
	node* sibling = root -> getSibling();
	root -> getParent() -> setRight(sibling -> getRSon());
	sibling -> getRSon() -> setRight(sibling);
	sibling -> setParent(sibling -> getRSon());
	sibling -> getParent() -> setParent(root -> getParent());
	sibling -> setRight(NULL);
	sibling -> setLeft(NULL);
	root -> getSibling() -> setColor(0);
	root -> getSibling() -> getRight() -> setColor(1);
	remove(root);
      }
    }
    else if (root -> getSibling() != NULL && root -> getSibling() -> getColor() == 0) { // root sibling is black
      root -> getSibling() -> setColor(1);
      if (root -> getColor() == 2) {
	if (isLeft(root)) {
	  root -> getParent() -> setLeft(NULL);
	}
	else {
	  root -> getParent() -> setRight(NULL);
	}
      }
      if (root -> getParent() -> getColor() == 1) {
	root -> getParent() -> setColor(0);
	if (root -> getColor() == 2) {
	  delete root;
	}
	else {
	  root -> setColor(root -> getColor() - 10);
	}
      }
      else {
	node* parent = root -> getParent();
	if (root -> getColor() == 2) {
	  delete root;
	}
	else {
	  root -> setColor(root -> getColor() - 10);
	}
	parent -> setColor(parent -> getColor() + 10);
	remove(parent);
      }
    }
    else if (root -> getSibling() != NULL && root -> getSibling() -> getColor() == 1) { // root sibling is red
      if (isLeft(root)) { // left root
	if (root -> getGrandparent() == NULL) { // head root
	  head = root -> getSibling();
	  head -> setParent(NULL);
	  node* left = head -> getLeft();
	  head -> setLeft(root -> getParent());
	  root -> getParent() -> setParent(head);
	  head -> setColor(0);
	  root -> getParent() -> setRight(left);
	  left -> setParent(root -> getParent());
	  root -> getParent() -> setLeft(NULL);
	  root -> getParent() -> setColor(1);
	  remove(root);
	}
	else {
	  node* sibling = root -> getSibling();
	  sibling -> setParent(root -> getGrandparent());
	  if (isLeft(root -> getParent())) {
	    root -> getGrandparent() -> setLeft(sibling);
	  }
	  else {
	    root -> getGrandparent() -> setRight(sibling);
	  }
	  root -> getParent() -> setParent(sibling);
	  sibling -> setColor(0);
	  node* left = sibling -> getLeft();
	  sibling -> setLeft(root -> getParent());
	  root -> getParent() -> setRight(left);
	  left -> setParent(root -> getParent());
	  root -> getParent() -> setLeft(NULL);
	  root -> getParent() -> setColor(1);
	  remove(root); 
	}
      }
      else { // right root
	if (root -> getGrandparent() == NULL) { // head root
	  head = root -> getSibling();
	  head -> setParent(NULL);
	  node* right = head -> getRight();
	  head -> setRight(root -> getParent());
	  root -> getParent() -> setParent(head);
	  head -> setColor(0);
	  root -> getParent() -> setLeft(right);
	  right -> setParent(root -> getParent());
	  root -> getParent() -> setRight(NULL);
	  root -> getParent() -> setColor(1);
	  remove(root);
	}
	else {
	  node* sibling = root -> getSibling();
	  sibling -> setParent(root -> getGrandparent());
	  if (isLeft(root -> getParent())) {
	    root -> getGrandparent() -> setLeft(sibling);
	  }
	  else {
	    root -> getGrandparent() -> setRight(sibling);
     	  }
	  root->getParent() -> setParent(sibling);
	  sibling -> setColor(0);
	  node* right = sibling -> getLeft();
	  sibling -> setRight(root -> getParent());
	  root -> getParent() -> setLeft(right);
	  right -> setParent(root -> getParent());
	  root -> getParent() -> setRight(NULL);
	  root -> getParent() -> setColor(1);
	  remove(root);
	}
      }
    }
  }
  else if (root -> getLeft() != NULL && root -> getRight() != NULL) { // if there are both children, replace node with successor and delete successor
    node* successor = findSuccessor(root -> getLeft());
    int value = successor -> getValue();
    remove(successor);
    root -> setValue(value);
  }
  else if (root -> getColor() == 1 && root -> getLeft() == NULL && root -> getRight() == NULL) { // if root is red and there are no children
    if (isLeft(root)) {
      root -> getParent() -> setLeft(NULL);
    }
    else {
      root -> getParent() -> setRight(NULL);
    }
    delete root;
  }
  // if there is left child and node is right or is red
  else if (root -> getLeft() != NULL && (root -> getColor() == 1 || root->getLeft() -> getColor() == 1)) {
    if (root -> getParent() == NULL) {
      root -> getLeft() -> setColor(0);
      head = root -> getLeft();
      head -> setParent(NULL);
      delete root;
    }
    else {
      if (isLeft(root)) {
	root -> getParent() -> setLeft(root -> getLeft());
      }
      else {
	root -> getParent() -> setRight(root -> getLeft());
      }
      root -> getLeft() -> setParent(root -> getParent());
      root -> getLeft() -> setColor(0);
      delete root;
    }
  }
  // if there is right child and node is right or red 
  else if (root -> getRight() != NULL && (root -> getColor() == 1 || root -> getRight() -> getColor() == 1)) {
    if (root -> getParent() == NULL) {
      root -> getRight() -> setColor(0);
      head = root -> getRight();
      head -> setParent(NULL);
      delete root;
    }
    else {
      if (isLeft(root)) {
	root -> getParent() -> setLeft(root -> getRight());
      }
      else {
	root -> getParent() -> setRight(root -> getRight());
      }
      root -> getRight() -> setParent(root -> getParent());
      root -> getRight() -> setColor(0);
      delete root;
    }
  }
  // else double black case
  else {
    root -> setColor(2);
    remove(root);
  }
}

node* tree::search(int value, node* root) {
  if (root == NULL) {
    return NULL;
  }
  if (root -> getValue() == value) {
    return root;
  }
  if (value <= root -> getValue()) {
    return search(value, root -> getLeft());
  }
  return search(value, root -> getRight());
}
