#include "Student.h"

class Node {
 public:
  Node(Student newStudent);
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);
  Node(Student*);
  ~Node();

 private:
  Student* student;
  Node* nextNode;

};
