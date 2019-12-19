#include "Student.h"

// node header file

class Node {
public: // public functions
  Node(Student newStudent); // node new student constructor
  Node* getNext(); // get next node pointer
  Student* getStudent(); // get student pointer
  void setNext(Node*); // set next pointer to corresponding node pointer
  Node(Student*); // constructor
  ~Node(); // destructor

private: // private variables
  Student* student;
  Node* nextNode;

};
