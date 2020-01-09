#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

/* Name: Joyce Chen
 * Date: 12/19/19
 * Linked Lists Part 2
 */

using namespace std;

void add(Node* &head, Node* node, Student* s);
void print(Node* node);
void remove(int ID, Node* &head, Node* node);
float average();

int main() {
  
  /* Linked Lists Part 1: First part of studentlist using linked lists 
   *
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
  */

  Node* head = NULL;
  bool run = true;
  char response[10];

  cout << "To create a new entry for a student, type ADD" << endl;
  cout << "To see all students currently stored, type PRINT" << endl;
  cout << "To delete a student by ID, type DELETE" << endl;
  cout << "To average GPA of all students, type AVERAGE" << endl;
  cout << "To quit, type QUIT" << endl << endl;

  while (run == true) {
    cin >> response;
    if (strcmp(response, "ADD") == 0) {
      char* firstName = new char(99);
      char* lastName = new char(99);
      int ID = 0;
      float GPA = 0;

      cout << endl << "Enter Student Entry's First Name: ";
      cin >> firstName;
      cout << "Enter Student Entry's Last Name: ";
      cin >> lastName;
      cout << "Enter Student Entry's ID: ";
      cin >> ID;
      cout << "Enter Student Entry's GPA: ";
      cin >> GPA;

      Student *s = new Student(firstName, lastName, ID, GPA);
      add(head, head, s);

      cout << endl << "ADDED" << endl << endl;
    }
    else if (strcmp(response, "PRINT") == 0) {
      cout << endl;
      print(head);
      cout << endl << "PRINTED" << endl << endl;
    }
    else if (strcmp(response, "DELETE") == 0) {
      int ID = 0;
      cout << endl << "Please enter ID of student to delete: ";
      cin >> ID;

      remove(ID, head, head);

      cout << endl << "DELETED" << endl << endl;
    }
    else if (strcmp(response, "AVERAGE") == 0) {

    }
    else if (strcmp(response, "QUIT") == 0) {

    }
    else {
      cout << "Please enter a valid command, see above ^^" << endl;
    }

  }
 

  return 0;
}

void add(Node* &head, Node* node, Student* s) {
  if (node == NULL) {
    Node* sN = new Node(s);
    head = sN;
    return;
  }
  if (node -> getNext() == NULL) {
    Node *sN = new Node(s);
    node -> setNext(sN);
    return;
  }

  add(head, node -> getNext(), s);
}

void print(Node* node) {
  if (node == NULL) {
    cout << "List is empty" << endl;
    return;
  }
  node -> getStudent() -> printStudent();
  cout << endl;
  
  print(node -> getNext());
}

void remove(int ID, Node* &head, Node* node) {
  if ((node -> getStudent() -> getID() == ID) && (node == head)) {
    Node* sN = head;
    head = head -> getNext();
    delete sN;
    return;
  }
  if (node -> getNext() -> getStudent() -> getID() == ID) {
    node -> setNext(node -> getNext() -> getNext());
    delete node -> getNext();
    return;
  }
  
  remove(ID, head, node -> getNext());
}

