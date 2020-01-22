`#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

node::node(new student *newStudent) {
  next = NULL;
  student = newStudent;
}
node* node::getNext() {
  return next;
}
student* node::getStudent() {
  return student;
}
void node::setNext(node *setNode) {
  next = setNode;
}
node::~node() {
  delete student;
}
