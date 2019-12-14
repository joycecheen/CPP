#include "student.h"

/*
 * Node header file
 */

class node {
 public:
  node(student newstudent);
  node *getNext();
  student* getStudent();
  void setNext(node*);
  node(student*);
  ~node();

 private:
  student* student;
  node* next;
  
};
