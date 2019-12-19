#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

/* Name: Joyce Chen
 * Date: 12/19/19
 * Linked Lists Part 1: First part of student list using linked lists
 */

using namespace std;

int main() {

  // node to keep track of next node in list
  Node* nextN = NULL;

  // manually create and set values for students and nodes
  Student *joyce = new Student((char*)"Joyce", (char*)"Chen", 385533, 1.00);
  Node* joyceN = new Node(joyce);

  Student *emma = new Student((char*)"Emma", (char*)"Shu", 385534, 1.00);
  Node* emmaN = new Node(emma);

  Student *maggie = new Student((char*)"Maggie", (char*)"Bao", 385535, 1.00);
  Node* maggieN = new Node(maggie);


  // set next pointer to corresponding node pointer
  joyceN -> setNext(emmaN);
  emmaN -> setNext(maggieN);

  // print out students by getting next node and student
  joyceN -> getStudent() -> printStudent();
  cout << endl;
  nextN = joyceN -> getNext();
  nextN -> getStudent() -> printStudent();
  cout << endl;
  nextN = nextN -> getNext();
  nextN -> getStudent() -> printStudent();
  cout << endl;

  return 0;
}
