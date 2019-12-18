#include "Student.h"

class Node {
 public:
  Node(Student newStudent);
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);
  Node(student*);
  ~Node();

 private:
  Student* Student;
  Node* nextNode;

};
