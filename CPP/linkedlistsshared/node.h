#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

//Variables and methods for the node class
class Node {
 public:
  Node(Student* newStudent);
  ~Node();
  void setNext(Node* newnext);
  Node* getNext();
  void setStudent(Student* newStudent);
  Student* getStudent();
 private:
  Student* student;
  Node* next;
};



#endif 