#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "Student.h"

/* Name: Joyce Chen
 * Date: 12/19/19
 * Linked Lists Part 2
 */

using namespace std;

void add(Node* prev, Node* &head, Node* node, Student* s);
void print(Node* node);
void remove(Node* &head, Node* node, int ID);
void average(Node* node, float sum, float count);

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

      Node* prev = NULL;

      cout << endl << "Enter Student Entry's First Name: ";
      cin >> firstName;
      cout << "Enter Student Entry's Last Name: ";
      cin >> lastName;
      cout << "Enter Student Entry's ID: ";
      cin >> ID;
      cout << "Enter Student Entry's GPA: ";
      cin >> GPA;

      Student *s = new Student(firstName, lastName, ID, GPA);
      add(prev, head, head, s);

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
      cin.ignore();

      remove(head, head, ID);

      cout << endl << "DELETED" << endl << endl;
    }
    else if (strcmp(response, "AVERAGE") == 0) {
      average(head, 0, 0);
      cout << endl << "AVERAGED" << endl << endl;
    }
    else if (strcmp(response, "QUIT") == 0) {
      run = false;
    }
    else {
      cout << "Please enter a valid command, see above ^^" << endl;
    }

  }
 

  return 0;
}

void add(Node* prev, Node* &head, Node* node, Student* s) {
  
  if (node == NULL) { // create head
    Node* temp = new Node(s);
    temp -> setStudent(s);
    head = temp;
    return;
  }
  
  Node * student = new Node(s);
  student -> setStudent(s);
  
  if (student -> getStudent() -> getID() < head -> getStudent() -> getID()) { // create new head
    Node* temp = head;
    head = new Node(s);
    head -> setStudent(s);
    head -> setNext(temp);
    return;
  }

  if ((node -> getNext() == NULL)) { // add at very end of list
    Node *temp = new Node(s);
    temp -> setStudent(s);
    node -> setNext(temp);
    temp -> setNext(NULL);
    cout << "add at end" << endl;
    return;
  }


  if ((node -> getStudent() -> getID() < student -> getStudent() -> getID()) && (student -> getStudent() -> getID() < node -> getNext() -> getStudent() -> getID())) { // add between two nodes
    cout << node -> getStudent() -> getID() << endl;
    cout << node -> getNext() -> getStudent() -> getID() << endl;
    Node * temp = new Node(s);
    temp -> setStudent(s);
    temp -> setNext(node -> getNext());
    node -> setNext(temp);
    return;

   }

  add(node, head, node -> getNext(), s);
}

void print(Node* node) {
  if (node == NULL) {
    return;
  }
		  
  node -> getStudent() -> printStudent();
  cout << endl;
  
  print(node -> getNext());
}

void remove(Node* &head, Node* node, int ID) {
  if ((node -> getStudent() -> getID() == ID) && (node == head)) {
    Node* temp = head;
    head = head -> getNext();
    cout << "One" << endl;
    if (temp -> getStudent() != NULL) {
      delete temp;
    }
    cout << "Two" << endl;
    return;
  }
  if (node -> getNext() -> getStudent() -> getID() == ID) {
    node -> setNext(node -> getNext() -> getNext());
    delete node -> getNext();
    return;
  }
  
  remove(head, node -> getNext(), ID);
}

void average(Node* node, float sum, float count) {
  if (node == NULL) {
    cout << setprecision(2) << fixed;
    cout << endl << (sum/count) << endl;
    return;
  }
  sum += node -> getStudent() -> getGPA();
  count++;

  average(node->getNext(), sum, count);
}
