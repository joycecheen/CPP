#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <time.h>

/* Hash Table: Create a hash table and a random student generator.
 * Author: Joyce Chen
 * Date: 6/4/20
 */

using namespace std;

struct student { // student data
  char fname[99];
  char lname[99];
  int ID;
  float GPA;
};

struct node { // nodes for linked list struct
  student * student;
  node * next;
};

// declare methods
int getHash(int number, int size);

int main() {
  srand(time(NULL));
  
  //vector<student*> list;
  char fnameinput[99];
  char lnameinput[99];
  int idinput;
  float gpainput;
  int size = 100;
  int count = 1;

  char response[10];
  bool run = true;

  node** list = new node*[size];

  for (int i = 0; i < size; i++) {
    list[i] = new node();
    list[i] -> student = NULL;
    list[i] -> next = NULL;
  }

  vector<char*> fnames;
  vector<char*> lnames;
  
  // prompt user with commands
  cout << "To create a new entry for student(s), type ADD" << endl;
  cout << "To see all students currently stored, type PRINT" << endl;
  cout << "To delete a student entry, type DELETE" << endl;
  cout << "To quit, type QUIT\n" << endl;

  while (run == true) { // while user has not quit yet
    cin >> response;
    if (strcmp(response, "ADD") == 0) { // if add a student, run add function
      cout << "add by random student generator? (y/n): ";
      char yn;
      cin >> yn;
      if (yn == 'y') {
	int n;
	cout << "input number of students to generate: ";
	cin >> n;

	student* t = new student();
	int fnameindex = rand() % fnames.size(); // random first name
	int lnameindex = rand() % lnames.size(); // random last name
	strcpy(t -> fname, fnames[fnameindex]);
	strcpy(t -> lname, lnames[lnameindex]);

	t -> GPA = 4 * ((double)rand() / (double)RAND_MAX);
	t -> ID = count;
	count++;
	int hash = getHash(t -> ID, size);
	bool leave = false;
	node* current = list[hash];
	while (current!= NULL && current->student != NULL) {
	  if (current -> student -> ID == t -> ID) {
	    cout << "ID already used" << endl;
	    leave = true;
	    break;
	  }
	  current = current->next;
	}
	if (leave) {
	  continue;
	}
	while (getSize(list[getHash(t -> ID, size)]) == 3) {
	  node** newStudents = new node*[size * 2];
	  //initializing newStudents, with size = size*2
	  for (int a = 0; a < size * 2; a++) {
	    newStudents[a] = new node();
	    newStudents[a]->student = NULL;
	    newStudents[a]->next = NULL;

	  }
	  //goes through all of the old hash table and rehashes into new table
	  for (int a = 0; a < size; a++) {
	    node* current = list[a];
	    while (current -> student != NULL) {
	      node* tempNew = new node();
	      tempNew -> student = current -> student;
	      tempNew -> next = NULL;
	      if (newStudents[getHash(current -> student->ID, size * 2)] -> student == NULL) {
		newStudents[getHash(current -> student->ID, size * 2)] = tempNew;
	      }
	      else {
		node* tempCurrent = newStudents[getHash(current -> student -> ID, size * 2)];
		while (tempCurrent -> next != NULL) {
		  tempCurrent = tempCurrent->next;
		}
		tempCurrent->next = tempNew;
	      }
	      node* tempNode = current;
	      current = current -> next;
	      delete tempNode;
	    }
	  }
	  size *= 2;

	  node** tempArray = list;
	  list = newStudents;
	  delete tempArray;

	}
	//when adding student and it is the first in the linked list
	if (list[getHash(t -> ID, size)] -> student == NULL) {

	  node* add = new node();
	  add -> student = t;
	  add -> next = new node();
	  add -> next -> student = NULL;

	  list[getHash(t -> ID, size)] = add;
	}
	else { //if it is not the first in linked list

	  node* current = list[getHash(t -> ID, size)];
	  while (current->next != NULL && current->next->student != NULL) {
	    current = current->next;
	  }
	  node* add = new node();
	  add -> student = t;
	  add -> next = new node();

	  add -> next -> student = NULL;

	  current -> next = add;
	}
	n--;
      }
      else if (yn == 'n') {
	// ask and get student info
	cout << "Enter First Name: ";
	cin >> fnameinput;
	cout << "Enter Last Name: ";
	cin >> lnameinput;
	cout << "Enter ID: ";
	cin >> idinput;
	cout << "Enter gpa: ";
	cin >> gpainput;
	cout << "ADDED" << endl << endl;

	// add student to vector list
	student *s = new student();
	strcpy(s -> fname, fnameinput);
	strcpy(s -> lname, lnameinput);
	s -> ID = idinput;
	s -> GPA = gpainput;
	list.push_back(s);
      }
    }
    else if (strcmp(response, "PRINT") == 0) { // if print students, run print function
      print(list);
    }
    else if (strcmp(response, "DELETE") == 0) { // if delete student, run delete function
      deletestudent(list);
    }
    else if (strcmp(response, "QUIT") == 0) { // if quit, set run to false
      run = false;
    }
    else { // if not a valid command, tell user
      cout << "Please enter a valid command (look above ^^)" << endl << endl;
    }
  }

  return 0;
}

// to print student list
void print (vector<student*>& list) {
  // run through vector list and print out student data
  for (vector<student*>::iterator p = list.begin(); p != list.end(); ++p) {
    cout << (*p)->fname << " " << (*p)->lname << ", ";
    cout << (*p)->ID << ", ";

    // show gpa to only two decimal places
    cout.precision (2);
    cout.setf(ios::showpoint);
    cout << fixed << (*p) -> GPA << endl;
  }
    cout << "PRINTED" << endl << endl;

  return;
}

// to delete a student
void deletestudent (vector<student*>& list) {
  int input;

  cout << "Please enter ID of student to delete: ";
  cin >> input;

    // run through vector and look for student with given id
  for (vector<student*>::iterator p = list.begin(); p != list.end(); ++p) {
    if ((*p)-> ID == input) { // if found, delete student data
      delete *p;
      list.erase(p);
      cout << "DELETED" << endl << endl;

      break;
    }
  }

  return;
}

// hash function
int getHash(int number, int size) {
  
}
