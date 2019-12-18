#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(Student *newStudent) {
  nextNode = NULL;
  student = newStudent;
}
Node* Node::getNext() {
  return nextNode;
}
Student* Node::getStudent() {
  return student;
}
void Node::setNext(Node *setNode) {
  nextNode = setNode;
}
Node::~Node() {
  delete student;
}
