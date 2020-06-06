#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <time.h>
#include <fstream>

/* Hash Table: Create a hash table and a random student generator.
 * Author: Joyce Chen
 * Date: 6/5/20
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
void add(node** list, int size, student* t);

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

  node** list = new node*[size]; // list containing all students

  for (int i = 0; i < size; i++) { // set and clear student list
    list[i] = new node();
    list[i] -> student = NULL;
    list[i] -> next = NULL;
  }

  // get list of first names for rsg
  cout << "Input list of first name file: "; 
  cin.getline(fnamefile, 20);
  ifstream ffile(fnamefile);
  if (ffile.is_open()) {
  } else {
    cout << "Cannot open file" << endl;
    return 0;
  }
  while (!ffile.eof()) {
    char* tempname = new char(30);
    ffile >> tempname;
    fnames.push_back(tempname);
  }

  // get list of last names for rsg
  cout << "Input list of last name file: ";
  cin.getline(lnamefile, 20);
  ifstream lfile(lnamefile);
  if (lfile.is_open()) {
  } else {
    cout << "Cannot open file" << endl;
    return 0;
  }
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
    
    if (strcmp(response, "ADD") == 0) { // if add student(s)
      cout << "Add by random student generator? yes or no: ";
      char yn[5] = {};
      cin >> yn;

      if (strcmp(yn, "yes") == 0) { // add randomly generated students
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
	  t -> GPA = 4 * ((double)rand() / (double)RAND_MAX); // random GPA
	  t -> ID = count; // increment ID
	  count++;

	  add(list, size, t);
	}
      }
      else if (strcmp(yn, "no") == 0) { // manually add student
	// ask and get student info
	cout << "Enter First Name: ";
	cin >> fnameinput;
	cout << "Enter Last Name: ";
	cin >> lnameinput;
	cout << "Enter ID: ";
	cin >> idinput;
	cout << "Enter gpa: ";
	cin >> gpainput;

	// add student info
	student *s = new student();
	strcpy(s -> fname, fnameinput);
	strcpy(s -> lname, lnameinput);
	s -> ID = idinput;
	s -> GPA = gpainput;

	add(list, size, s);
      }
      cout << "ADDED" << endl << endl;
    }
    else if (strcmp(response, "PRINT") == 0) { // print students
      for (int a = 0; a < size; a++) {
	node* t = list[a];
	// run through student list and print out student data
	while (t != NULL && t -> student != NULL) {
	  cout << t -> student -> fname << " " << t -> student -> lname << endl;
	  cout << "ID: " << t -> student -> ID << endl;

	  // show gpa to only two decimal places
	  cout.precision (2);
	  cout.setf(ios::showpoint);
	  cout << "GPA: " << fixed << t -> student -> GPA << endl;
	  
	  t = t -> next;
	  cout << endl;
	}
      }
      cout << "PRINTED\n\n";
    }
    else if (strcmp(response, "DELETE") == 0) { // delete a student 
      int input;

      cout << "Please enter ID of student to delete: ";
      cin >> input;

      // run through student list and look for student with given id
      if (list[getHash(input, size)] -> student -> ID == input) {
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
    else if (strcmp(response, "QUIT") == 0) { // quit
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

void add(node** list, int size, student* t) {
  int hash = getHash(t -> ID, size);
  
  // rehash till less than 3 links to hash address  
  while (getSize(list[getHash(t -> ID, size)]) == 3) {
    node** doubleList = new node*[size * 2]; // initialize student list with double size
    for (int a = 0; a < size * 2; a++) {
      doubleList[a] = new node();
      doubleList[a]->student = NULL;
      doubleList[a]->next = NULL;

    }
    // rehash students into new table
    for (int a = 0; a < size; a++) {
      node* current = list[a];
      while (current -> student != NULL) {
	node* tempNew = new node();
	tempNew -> student = current -> student;
	tempNew -> next = NULL;
	if (doubleList[getHash(current -> student->ID, size * 2)] -> student == NULL) {
	  doubleList[getHash(current -> student->ID, size * 2)] = tempNew;
	}
	else {
	  node* tempCurrent = doubleList[getHash(current -> student -> ID, size * 2)];
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
    list = doubleList;
    delete tempArray;

  }
  // if student is first in the list
  if (list[getHash(t -> ID, size)] -> student == NULL) {
    node* add = new node();
    add -> student = t;
    add -> next = new node();
    add -> next -> student = NULL;

    list[getHash(t -> ID, size)] = add;
  }
  else { // not first in list
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
