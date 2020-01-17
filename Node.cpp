#include <iostream>
#include "Node.h"

// Node Functions

using namespace std;

Node::Node(Student *newStudent) { // constructor
  nextNode = NULL;
  student = newStudent;
}

// getters
Node* Node::getNext() { 
  return nextNode;
}
Student* Node::getStudent() {
  return student;
}
void Node::setNext(Node *setNode) { // set next node pointer
  nextNode = setNode;
}
Node::~Node() { // destructor
  delete student;
}
