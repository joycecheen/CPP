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
  
  //vector<student*> list;
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

  node** list = new node*[size];

  for (int i = 0; i < size; i++) {
    list[i] = new node();
    list[i] -> student = NULL;
    list[i] -> next = NULL;
  }

  /*char fnamefile[20] = {};
  char lnamefile[20] = {};
  string line;
  char filecontent[400] = {};

  cout << "enter file name of first name file: ";
  cin >> fnamefile;

  ifstream file (fnamefile);
  if (file.is_open()) {
    while (getline (file, line)) {
      int a = 0;
      while (line[a] != 0) {
	filecontent[a] = line[a];
	a++;
      }
    }
    file.close();
  }
  else {
    cout << "cannot open file" << endl;
  }

  for (int i = 0; i < 400; i++) {
    cout << filecontent[i]; 
  } */

  cout << "input list of first name file" << endl;
  char* fnamefile = new char(30);
  cin.getline(fnamefile, 30);
  ifstream fname(fnamefile);
  
  cout << "input list of last name file" << endl;
  char* lnamefile = new char(30);
  cin.getline(lnamefile, 30);
  ifstream lname(lnamefile);
  
  //gets all the first names from first name file
  while (!fname.eof()) {
    char* tempname = new char(30);
    fname >> tempname;
    fnames.push_back(tempname);
  }
  //gets all the last names from last name file
  while (!lname.eof()) {
    char* tempname = new char(30);
    lname >> tempname;
    lnames.push_back(tempname);
    }
  
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
	}
      }
      else if (yn == 'n') {
	// ask and get student info
	cout << "enter first name: ";
	cin >> fnameinput;
	cout << "enter last name: ";
	cin >> lnameinput;
	cout << "enter ID: ";
	cin >> idinput;
	cout << "enter gpa: ";
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
	    cout << "ID already used" << endl;
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
	  //initializing newStudents, with size = size*2
	  for (int a = 0; a < size * 2; a++) {
	    newStudents[a] = new node();
	    newStudents[a] -> student = NULL;
	    newStudents[a] -> next = NULL;

	  }
	  //goes through all of the old hash table and rehashes into new table
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
	//when adding student and it is the first in the linked list
	if (list[getHash(s -> ID, size)] -> student == NULL) {

	  node* add = new node();
	  add -> student = s;
	  add -> next = new node();
	  add -> next -> student = NULL;

	  list[getHash(s -> ID, size)] = add;
	}
	else { //if it is not the first in linked list
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
	  cout << "GPA: " << t -> student -> GPA << endl;
	  cout << "ID: " << t -> student -> ID << endl;
	  t = t -> next;
	  cout << endl;
	}

      }
    }
    else if (strcmp(response, "DELETE") == 0) { // if delete student, run delete function
      int input;

      cout << "please enter ID of student to delete: ";
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
