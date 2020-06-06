#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <time.h>
#include <fstream>

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
int getSize(node* start);

int main() {
  srand(time(NULL));
  
  char fnameinput[99];
  char lnameinput[99];
  int idinput;
  float gpainput;
  int size = 100;
  int count = 1;
  char response[10];
  bool run = true;

  vector<char*> fnames;
  vector<char*> lnames;
  char* fnamefile = new char(20);
  char* lnamefile = new char(20);

  node** list = new node*[size];

  for (int i = 0; i < size; i++) {
    list[i] = new node();
    list[i] -> student = NULL;
    list[i] -> next = NULL;
  }

  cout << "Input list of first name file: ";
  cin.getline(fnamefile, 20);
  ifstream ffile(fnamefile);
  if (ffile.is_open()) {
  } else {
    cout << "Cannot open file" << endl;
    return 0;
  }
  cout << "Input list of last name file: ";
  cin.getline(lnamefile, 20);
  ifstream lfile(lnamefile);
  if (lfile.is_open()) {
  } else {
    cout << "Cannot open file" << endl;
    return 0;
  }
  
  // gets all the first names from first name file
  while (!ffile.eof()) {
    char* tempname = new char(30);
    ffile >> tempname;
    fnames.push_back(tempname);
  }
  // gets all the last names from last name file
  while (!lfile.eof()) {
    char* tempname = new char(30);
    lfile >> tempname;
    lnames.push_back(tempname);
    }
  
  // prompt user with commands
  cout << endl << "To create a new entry for student(s), type ADD" << endl;
  cout << "To see all students currently stored, type PRINT" << endl;
  cout << "To delete a student entry, type DELETE" << endl;
  cout << "To quit, type QUIT\n" << endl;

  while (run == true) { // while user has not quit yet
    cin >> response;
    if (strcmp(response, "ADD") == 0) { // if add a student, run add function
      cout << "Add by random student generator? yes or no: ";
      char yn[5] = {};
      cin >> yn;
      if (strcmp(yn, "yes") == 0) {
	int n;
	cout << "Input number of students to generate: ";
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
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
	    // initializing newStudents, with size = size*2
	    for (int a = 0; a < size * 2; a++) {
	      newStudents[a] = new node();
	      newStudents[a]->student = NULL;
	      newStudents[a]->next = NULL;

	    }
	    // goes through all of the old hash table and rehashes into new table
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
	  // when adding student and it is the first in the linked list
	  if (list[getHash(t -> ID, size)] -> student == NULL) {

	    node* add = new node();
	    add -> student = t;
	    add -> next = new node();
	    add -> next -> student = NULL;

	    list[getHash(t -> ID, size)] = add;
	  }
	  else { // if it is not the first in linked list

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
	}
      }
      else if (strcmp(yn, "no") == 0) {
	// ask and get student info
	cout << "Enter First Name: ";
	cin >> fnameinput;
	cout << "Enter Last Name: ";
	cin >> lnameinput;
	cout << "Enter ID: ";
	cin >> idinput;
	cout << "Enter gpa: ";
	cin >> gpainput;

	// add student to vector list
	student *s = new student();
	strcpy(s -> fname, fnameinput);
	strcpy(s -> lname, lnameinput);
	s -> ID = idinput;
	s -> GPA = gpainput;

	int hash = getHash(s -> ID, size);

	bool leave = false;
	node* current = list[hash];
	while (current -> student != NULL) {
	  if (current -> student -> ID == s -> ID) {
	    cout << "ID already exists" << endl;
	    leave = true;
	    break;
	  }
	  current = current -> next;
	}
	if (leave) {
	  continue;
	}
	
	while (getSize(list[getHash(s -> ID, size)]) == 3) {
	  node** newStudents = new node*[size * 2];
	  // initializing newStudents, with size = size*2
	  for (int a = 0; a < size * 2; a++) {
	    newStudents[a] = new node();
	    newStudents[a] -> student = NULL;
	    newStudents[a] -> next = NULL;

	  }
	  // goes through all of the old hash table and rehashes into new table
	  for (int a = 0; a < size; a++) {
	    node* current = list[a];
	    while (current != NULL && current -> student != NULL) {
	      node* tempNew = new node();
	      tempNew -> student = current -> student;
	      tempNew -> next = NULL;
	      if (newStudents[getHash(current -> student -> ID, size * 2)] -> student == NULL) {
		newStudents[getHash(current -> student -> ID, size * 2)] = tempNew;
	      }
	      else {
		node* tempCurrent = newStudents[getHash(current -> student->ID, size * 2)];
		while (tempCurrent -> next != NULL) {
		  tempCurrent = tempCurrent -> next;
		}
		tempCurrent -> next = tempNew;
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
	// when adding student and it is the first in the linked list
	if (list[getHash(s -> ID, size)] -> student == NULL) {

	  node* add = new node();
	  add -> student = s;
	  add -> next = new node();
	  add -> next -> student = NULL;

	  list[getHash(s -> ID, size)] = add;
	}
	else { // if it is not the first in linked list
	  node* current = list[getHash(s->ID, size)];
	  while (current -> next != NULL && current -> next -> student != NULL) {
	    current = current -> next;
	  }
	  node* add = new node();
	  add -> student = s;
	  add -> next = new node();

	  add -> next -> student = NULL;

	  current -> next = add;
	}

      }
      cout << "ADDED" << endl << endl;
    }
    else if (strcmp(response, "PRINT") == 0) { // if print students, run print function
      for (int a = 0; a < size; a++) {
	node* t = list[a];
	while (t != NULL && t -> student != NULL) {
	  cout << t -> student -> fname << " " << t -> student -> lname << endl;
	  cout << "ID: " << t -> student -> ID << endl;

	  cout.precision (2);
	  cout.setf(ios::showpoint);
	  cout << "GPA: " << fixed << t -> student -> GPA << endl;
	  
	  t = t -> next;
	  cout << endl;
	}
      }
      cout << "PRINTED\n\n";
    }
    else if (strcmp(response, "DELETE") == 0) { // if delete student, run delete function
      int input;

      cout << "Please enter ID of student to delete: ";
      cin >> input;

      if (list[getHash(input, size)] -> student ->ID == input) {
	node* t = list[getHash(input, size)];
	list[getHash(input, size)] = list[getHash(input, size)] -> next;
	delete t;
      }
      else {
	node* current = list[getHash(input, size)];
	while (current -> next -> student -> ID != input) {
	  current = current -> next;
	}
	node* t = current -> next;
	current -> next = t -> next;
	delete t;
      }
      cout << "DELETED \n\n";
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

// hash function
int getHash(int number, int size) {
  int address = 0;
  while (number != 0) {
    address *= 13;
    address += (number % 10);
    address %= size;
    number /= 10;
  }
  address *= 13;
  return address % size;
}

// returns size of linked list
int getSize(node* start) {
  int n = 0;
  while (start != NULL && start->student != NULL) {
    n++;
    start = start->next;
  }
  return n;
}
