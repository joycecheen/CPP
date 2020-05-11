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

void tree::remove(node* root) {
  //if node is a double black
  if (root->getColor() >= 2) {
    //when double black is root node
    if (root->getParent() == NULL) {
      
      if (root->getColor() == 2) {
	head->setValue(0);
	head->setParent(NULL);
      
	head->setLeft(NULL);
	head->setColor(0);
	head->setRight(NULL);
	return;
      }
      else {
	root->setColor(0);
	return;
      }
    }
    //if sibling is black and has a red child
    else if (root->getSibling() != NULL && root->getSibling()->getColor() == 0 && root->getSibling()->getRedSon() != NULL){
      //when sibling and sibling's child is left left
      if (isLeft(root->getSibling()) && isLeft(root->getSibling()->getRedSon())) {
	//when root's parent is the top node
	if (root->getGrandparent() == NULL) {
	  root->getSibling()->setColor(head->getColor());
	  root->getParent()->setColor(0);
	  
	  head = root->getSibling();
	  head->setParent(NULL);
	  node* right = head->getRight();
	  head->setRight(root->getParent());
	  root->getParent()->setParent(head);
	  head->getLeft()->setColor(0);
	  if (right != NULL) {
	    right->setParent(root->getParent());
	  }
	  root->getParent()->setLeft(right);
	  root->getParent()->setRight(NULL);
	  if (root->getColor() == 2) {
	    delete root;
	  }
	  else {
	    root->setColor(root->getColor() - 10);
	  }
	}
	else {
	  root->getSibling()->setColor(root->getParent()->getColor());
	  root->getParent()->setColor(0);
	  if (isLeft(root->getParent())) {
	    root->getGrandparent()->setLeft(root->getSibling());
	  }
	  else {
	    root->getGrandparent()->setRight(root->getSibling());
	  }
	  root->getSibling()->setParent(root->getGrandparent());
	  node* right= root->getSibling()->getRight();
	  root->getParent()->setParent(root->getSibling());
	  root->getParent()->setLeft(NULL);
	  root->getGrandparent()->setRight(root->getParent());
	  root->getGrandparent()->getLeft()->setColor(0);
	  if (right != NULL) {
	    right->setParent(root->getParent());
	  }
	  root->getParent()->setLeft(right);
	  root->getParent()->setRight(NULL);
	  if (root->getColor() == 2) {
	    delete root;
	  }
	  else {
	    root->setColor(root->getColor() - 10);
	  }
	}
      }
      //when sibling and sibling's child is left right
      else if (isLeft(root->getSibling()) && !isLeft(root->getSibling()->getRedSon())) {
	//reorder the sibling and it's child, then recall the remove function
	node* sibling = root->getSibling();
	root->getParent()->setLeft(sibling->getRedSon());
	sibling->getRedSon()->setLeft(sibling);
	sibling->setParent(sibling->getRedSon());
	sibling->getParent()->setParent(root->getParent());
	sibling->setLeft(NULL);
	sibling->setRight(NULL);
	
	root->getSibling()->setColor(0);
	root->getSibling()->getLeft()->setColor(1);
	remove(root);
      }
      //when sibling and sibling's child is right right
      else if (!isLeft(root->getSibling()) && !isLeft(root->getSibling()->getRedSon())) {
	//when root's parent is the head node
	if (root->getGrandparent() == NULL) {
	  root->getSibling()->setColor(head->getColor());
	  root->getParent()->setColor(0);
	 
	  head = root->getSibling();
	  head->setParent(NULL);
	  node* left = head->getLeft();
	  head->setLeft(root->getParent());
	  root->getParent()->setParent(head);
	  head->getRight()->setColor(0);
	  if (left != NULL) {
	    left->setParent(root->getParent());
	  }
	  root->getParent()->setRight(left);
	  root->getParent()->setLeft(NULL);
	  if (root->getColor() == 2) {
	    delete root;
	  }
	  else {
	    root->setColor(root->getColor() - 10);
	  }
	}
	else {
	  root->getSibling()->setColor(root->getParent()->getColor());
	  root->getParent()->setColor(0);
	  if (isLeft(root->getParent())) {
	    root->getGrandparent()->setLeft(root->getSibling());
	  }
	  else {
	    root->getGrandparent()->setRight(root->getSibling());
	  }
	  root->getSibling()->setParent(root->getGrandparent());
	  node* left = root->getSibling()->getLeft();
	  root->getParent()->setParent(root->getSibling());
	  root->getParent()->setRight(NULL);
	  root->getGrandparent()->setLeft(root->getParent());
	  root->getGrandparent()->getRight()->setColor(0);
	  if (left != NULL) {
	    left->setParent(root->getParent());
	  }
	  root->getParent()->setRight(left);
	  root->getParent()->setLeft(NULL);
	  if (root->getColor() == 2) {
	    delete root;
	  }
	  else {
	    root->setColor(root->getColor() - 10);
	  }
	}
      }
      //when sibling and sibling's child is right left
      else if (!isLeft(root->getSibling()) && isLeft(root->getSibling()->getRedSon())) {
	//reorder sibling and it's child, then recall remove
	node* sibling = root->getSibling();
	root->getParent()->setRight(sibling->getRedSon());
	sibling->getRedSon()->setRight(sibling);
	sibling->setParent(sibling->getRedSon());
	sibling->getParent()->setParent(root->getParent());
	sibling->setRight(NULL);
	sibling->setLeft(NULL);
	root->getSibling()->setColor(0);
	root->getSibling()->getRight()->setColor(1);
	remove(root);
      }
    }
    //when root's sibling is black, and has no children
    else if (root->getSibling() != NULL && root->getSibling()->getColor() == 0) {
      root->getSibling()->setColor(1);
      if (root->getColor() == 2) {
	if (isLeft(root)) {
	  root->getParent()->setLeft(NULL);
	}
	else {
	  root->getParent()->setRight(NULL);
	}
      }
      if (root->getParent()->getColor() == 1) {
	root->getParent()->setColor(0);
	if (root->getColor() == 2) {
	  delete root;
	}
	else {
	  root->setColor(root->getColor() - 10);
	}
      }
      else {
	node* parent = root->getParent();
	if (root->getColor() == 2) {
	  delete root;
	}
	else {
	  root->setColor(root->getColor() - 10);
	}
	parent->setColor(parent->getColor() + 10);
	remove(parent);
      }
    }
    //when root's sibling is red
    else if (root->getSibling() != NULL && root->getSibling()->getColor() == 1) {
      //if root is on the left
      if (isLeft(root)) {
	//if root's parent is the head node
	if (root->getGrandparent() == NULL) {
	  head = root->getSibling();
	  head->setParent(NULL);
	  node* left = head->getLeft();
	  head->setLeft(root->getParent());
	  root->getParent()->setParent(head);
	  head->setColor(0);
	  root->getParent()->setRight(left);
	  left->setParent(root->getParent());
	  root->getParent()->setLeft(NULL);
	  root->getParent()->setColor(1);
	  remove(root);
	}
	else {
	  node* sibling = root->getSibling();
	  sibling->setParent(root->getGrandparent());
	  if (isLeft(root->getParent())) {
	    root->getGrandparent()->setLeft(sibling);
	  }
	  else {
	    root->getGrandparent()->setRight(sibling);
	  }
	  root->getParent()->setParent(sibling);
	  sibling->setColor(0);
	  node* left = sibling->getLeft();
	  sibling->setLeft(root->getParent());
	  root->getParent()->setRight(left);
	  left->setParent(root->getParent());
	  root->getParent()->setLeft(NULL);
	  root->getParent()->setColor(1);
	  remove(root); 
	}
      }
      //if root is on the right
      else {
	//if root's parent is the head node
	if (root->getGrandparent() == NULL) {
	  head = root->getSibling();
	  head->setParent(NULL);
	  node* right = head->getRight();
	  head->setRight(root->getParent());
	  root->getParent()->setParent(head);
	  head->setColor(0);
	  root->getParent()->setLeft(right);
	  right->setParent(root->getParent());
	  root->getParent()->setRight(NULL);
	  root->getParent()->setColor(1);
	  remove(root);
	}
	else {
	  node* sibling = root->getSibling();
	  sibling->setParent(root->getGrandparent());
	  if (isLeft(root->getParent())) {
	    root->getGrandparent()->setLeft(sibling);
	  }
	  else {
	    root->getGrandparent()->setRight(sibling);
	    OB	  }
	  root->getParent()->setParent(sibling);
	  sibling->setColor(0);
	  node* right = sibling->getLeft();
	  sibling->setRight(root->getParent());
	  root->getParent()->setLeft(right);
	  right->setParent(root->getParent());
	  root->getParent()->setRight(NULL);
	  root->getParent()->setColor(1);
	  remove(root);
	}
      }
    }
  }
  //if root has both children, replace node with successor and delete successor
  else if (root->getLeft() != NULL && root->getRight() != NULL) {
    node* successor = findSuccessor(root->getLeft());
    int value = successor->getValue();

    remove(successor);
    root->setValue(value);
  }
  //if root is red and root and root has no children
  else if (root->getColor() == 1 && root->getLeft() == NULL && root->getRight() == NULL) {
    if (isLeft(root)) {
      root->getParent()->setLeft(NULL);
    }
    else {
      root->getParent()->setRight(NULL);
    }
    delete root;
  }
  //if root has left child, and either it's right child or itself is red
  else if (root->getLeft() != NULL && (root->getColor() == 1 || root->getLeft()->getColor() == 1)) {
    if (root->getParent() == NULL) {
      root->getLeft()->setColor(0);
      head = root->getLeft();
      head->setParent(NULL);
      delete root;
    }
    else {
      if (isLeft(root)) {
	root->getParent()->setLeft(root->getLeft());
      }
      else {
	root->getParent()->setRight(root->getLeft());
      }
      root->getLeft()->setParent(root->getParent());
      root->getLeft()->setColor(0);
      delete root;
    }
  }
  //if root has right child and either its right node or itself is red 
  else if (root->getRight() != NULL && (root->getColor() == 1 || root->getRight()->getColor() == 1)) {
    if (root->getParent() == NULL) {
      root->getRight()->setColor(0);
      head = root->getRight();
      head->setParent(NULL);
      delete root;
    }
    else {
      if (isLeft(root)) {
	root->getParent()->setLeft(root->getRight());
      }
      else {
	root->getParent()->setRight(root->getRight());
      }
      root->getRight()->setParent(root->getParent());
      root->getRight()->setColor(0);
      delete root;
    }
  }
  //else it is a double black case
  //set node's color to be double black, and delete root again
  else {
    root->setColor(2);
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
  if (value <= root->getValue()) {
    return search(value, root->getLeft());
  }
  return search(value, root->getRight());
}
