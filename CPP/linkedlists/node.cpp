#include <iostream>
#include "node.h"

using namespace std;

node::node(student *newStudent) {
  student = newStudent;
}
node* node::getNext() {
  return node;
}
student* node::getStudent() {
  return student;
}
void node::setNext(node *setNode) {
  nextNode = setNode;
}
node::~node() {
  delete student;
}
