#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

int main() {
  Node* head = NULL;

  char* firstName = new char(99);
  firstName = (char*)"Joyce";
  char* lastName = new char(99);
  lastName = (char*)"Chen";
  int ID = 385533;
  float GPA = 1.00;

  Student *s = new Student(firstName, lastName, ID, GPA);
  Node* t = new Node(Student);

  


  return 0;
}
