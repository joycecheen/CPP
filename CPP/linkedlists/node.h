#include <iostream>

using namespace std;

class node {
 public:
  node *getNext();
  student* getStudent();
  void setNext(node*);
  node(student*);
  ~node();

 private:
  student* student;
  node* nextNode;
  
};
