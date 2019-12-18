#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(Student *newStudent) {
  nextNode = NULL;
  Student = newStudent;
}
Node* Node::getNext() {
  return nextNode;
}
student* Node::getStudent() {
  return Student;
}
void Node::setNext(Node *setNode) {
  nextNode = setNode;
}
Node::~Node() {
  delete student;
}
