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

  // give user instructions
  cout << "To create a new entry for a student, type ADD" << endl;
  cout << "To see all students currently stored, type PRINT" << endl;
  cout << "To delete a student by ID, type DELETE" << endl;
  cout << "To average GPA of all students, type AVERAGE" << endl;
  cout << "To quit, type QUIT" << endl << endl;

  while (run == true) { // while user had not quit yet
    cin >> response;
    if (strcmp(response, "ADD") == 0) { // add student
      char* firstName = new char(99);
      char* lastName = new char(99);
      int ID = 0;
      float GPA = 0;

      Node* prev = NULL;

      // read in student info
      cout << endl << "Enter Student Entry's First Name: ";
      cin >> firstName;
      cout << "Enter Student Entry's Last Name: ";
      cin >> lastName;
      cout << "Enter Student Entry's ID: ";
      cin >> ID;
      cout << "Enter Student Entry's GPA: ";
      cin >> GPA;

      Student *s = new Student(firstName, lastName, ID, GPA);
      add(prev, head, head, s); // add

      cout << endl << "ADDED" << endl << endl;
    }
    else if (strcmp(response, "PRINT") == 0) { // print all students stored
      cout << endl;
      if (head != NULL) { // if list is not empty
	print(head); // print
	cout << endl << "PRINTED" << endl << endl;
      }
      else { // otherwise if list is empty
	cout << "List is empty... please add a student" << endl << endl; // tell user
      }
    }
    else if (strcmp(response, "DELETE") == 0) { // delete a student by ID
      int ID = 0;
      if (head == NULL) { // if list is empty 
        cout << endl << "List is empty..." << endl << endl; 
      } else { // otherwise, print
	cout << endl << "Please enter ID of student to delete: ";
	cin >> ID; // read in ID
	cin.ignore();

	remove(head, head, ID); // delete
      }
    }
    else if (strcmp(response, "AVERAGE") == 0) { // print GPA average
      if (head != NULL) { // if list is not empty
	average(head, 0, 0); // average
	cout << endl << "AVERAGED" << endl << endl;
      }
      else { // otherwise if list is empty
	cout << endl << "List is empty... please add a student" << endl << endl;
      }
    }
    else if (strcmp(response, "QUIT") == 0) { // quit the program
      run = false;
    }
    else { // user entered invalid command
      cout << endl << "Please enter a valid command, see above ^^" << endl << endl;
    }

  }
 
  return 0;
}

void add(Node* prev, Node* &head, Node* node, Student* s) { // add student function
  if (node == NULL) { // if no students stored, create head
    Node* temp = new Node(s);
    temp -> setStudent(s);
    head = temp;
    return;
  }
  
  Node * student = new Node(s);
  student -> setStudent(s);
  
  if (student -> getStudent() -> getID() < head -> getStudent() -> getID()) { // if new student ID is smallest, create new head
    Node* temp = head;
    head = new Node(s);
    head -> setStudent(s);
    head -> setNext(temp);
    return;
  }

  if ((node -> getNext() == NULL)) { // if new student ID is largest, add at very end of list
    Node *temp = new Node(s);
    temp -> setStudent(s);
    node -> setNext(temp);
    temp -> setNext(NULL);
    cout << "add at end" << endl;
    return;
  }

  // if new ID is between two student IDs, insert node between
  if ((node -> getStudent() -> getID() < student -> getStudent() -> getID()) && (student -> getStudent() -> getID() < node -> getNext() -> getStudent() -> getID())) {
    Node * temp = new Node(s);
    temp -> setStudent(s);
    temp -> setNext(node -> getNext());
    node -> setNext(temp);
    return;

   }

  add(node, head, node -> getNext(), s); // add function calls itself
}

void print(Node* node) { // print all student function
  if (node == NULL) { // if current node is empty, return
    return;
  }
  node -> getStudent() -> printStudent(); // print
  cout << endl;
  
  print(node -> getNext()); // print function calls itself
}

void remove(Node* &head, Node* node, int ID) { // delete function
  if ((node -> getStudent() -> getID() == ID) && (node == head)) { // if ID matches and is head, set next head and delete
    Node* temp = head;
    head = head -> getNext(); 
    if (temp -> getStudent() != NULL) {
      delete temp;
    }
    cout << endl << "DELETED" << endl << endl;
    return;
  }
  if (node -> getNext() == NULL) { // if at end of list no ID matched
    cout << endl << "NOTHING FOUND" << endl << endl;
    return;
  }
  if (node -> getNext() -> getStudent() -> getID() == ID) { // if ID matches, set next and delete
    Node * temp = node -> getNext();
    node -> setNext(node -> getNext() -> getNext());
    delete temp;
    cout << endl << "DELETED" << endl << endl;
    return;
  }
  
  remove(head, node -> getNext(), ID); // delete function calls itself
}

void average(Node* node, float sum, float count) { // average function
  if (node == NULL) { // once reached end of list, print average
    cout << setprecision(2) << fixed;
    cout << endl << (sum/count) << endl;
    return;
  }
  sum += node -> getStudent() -> getGPA(); // add each gpa
  count++; // count # of students

  average(node->getNext(), sum, count); // average function calls itself
}
