#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

/* Hash Table: Create a hash table and a random student generator.
 * Author: Joyce Chen
 * Date: 6/4/20
 */

struct student { // student data
  char fname[99];
  char lname[99];
  int id;
  float gpa;
};

using namespace std;

// declare methods
void add(vector<student*>& list, char fnameinput[99], char lnameinput[99], int idinput,
         float gpainput);
void print(vector<student*>& list);
void deletestudent(vector<student*>& list);

int main() {
  vector<student*> list;
  char fnameinput[99];
  char lnameinput[99];
  int idinput;
  float gpainput;

  char response[10];
  bool run = true;

  // prompt user with commands
  cout << "To create a new entry for a student, type ADD" << endl;
  cout << "To see all students currently stored, type PRINT" << endl;
  cout << "To delete a student entry, type DELETE" << endl;
  cout << "To quit, type QUIT\n" << endl;

  while (run == true) { // while user has not quit yet
    cin >> response;
    if (strcmp(response, "ADD") == 0) { // if add a student, run add function
      add(list, fnameinput, lnameinput, idinput, gpainput);
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

// to add a student
void add (vector<student*>& list, char fnameinput[99], char lnameinput[99], int idinput,
          float gpainput) {
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
  s -> id = idinput;
  s -> gpa = gpainput;
  list.push_back(s);

  return;
}

// to print student list
void print (vector<student*>& list) {
  // run through vector list and print out student data
  for (vector<student*>::iterator p = list.begin(); p != list.end(); ++p) {
    cout << (*p)->fname << " " << (*p)->lname << ", ";
    cout << (*p)->id << ", ";

    // show gpa to only two decimal places
    cout.precision (2);
    cout.setf(ios::showpoint);
    cout << fixed << (*p)->gpa << endl;
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
    if ((*p)->id == input) { // if found, delete student data
      delete *p;
      list.erase(p);
      cout << "DELETED" << endl << endl;

      break;
    }
  }

  return;
}

