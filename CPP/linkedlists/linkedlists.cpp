#include <iostream>
#include <string.h>
#include "node.h"
#include "student.h"

using namespace std;

void add(node* &head, node* node, student* student);
void print(node* node);
void deletestudent(node* &head, node* node, int id);

int main() {
  node* head = NULL;
  bool run = true;
  char response[10];

  // prompt user with commands
  cout << "To create a new entry for a student, type ADD" << endl;
  cout << "To see all students currently stored, type PRINT" << endl;
  cout << "To delete a student entry, type DELETE" << endl;
  cout << "To quit, type QUIT\n" << endl;

  while (run == true) { // while user has not quit yet
    cin >> response;
    if (strcmp(response, "ADD") == 0) { // if add a student, run add function
      char* fname = new char(99);
      char* lname = new char(99);
      int id;
      float gpa;
      
      cout << "Enter First Name: ";
      cin >> fname;
      cout << "Enter Last Name: ";
      cin >> lname;
      cout << "Enter ID: ";
      cin >> id;
      cout << "Enter gpa: ";
      cin >> gpa;
      cout << "ADDED" << endl << endl;

      student *t = new student(fname, lname, id, gpa);
      add(head, head, t);
    }
    else if (strcmp(response, "PRINT") == 0) { // if print students, run print function
      print(head);
    }
    else if (strcmp(response, "DELETE") == 0) { // if delete student, run delete function
      int id;
      cout << "Please enter ID of student to delete: ";
      cin >> id;
      
      deletestudent(head, head, id);
    }
    else if (strcmp(response, "QUIT") == 0) { // if quit, set run to false
      run = false;
      return 0;
    }
    else { // if not a valid command, tell user
      cout << "Please enter a valid command (look above ^^)" << endl << endl;
    }
  }

  return 0;
}

void add (node* &head, node* node, student* student) {
  //node* t = new node(student);
  if (node == NULL) {
    node* t = new node(student);
    head = t;
    return;
  }
  if (node -> getNext() == NULL) {
    node* t = new node(student);
    node -> setNext(t);
    return;
  }
  add(head, node -> getNext(), student);
}

void print (node* node) {
  if (node == NULL) {
    return;
  }
  node -> getStudent() -> printstudent();
  cout << endl;
  print(node -> getNext());
  
  return;
}

void deletestudent (node* &head, node* node, int id) {
  if ((node -> getStudent() -> getid() == id) && (node == head)) {
    node* t = head;
    head = head -> getNext();
    delete t;
    return;
  }
  if (node -> getNext() -> getStudent() -> getid() == id) {
    node -> setNext(node -> getNext() -> getNext());
    delete node -> getNext();
    return;
  }
  deletestudent(head, node -> getNext(), id);
  
  return;
}
