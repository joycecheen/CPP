#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

struct student {
  char fname[99];
  char lname[99];
  int id;
  float gpa;
};

using namespace std;

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

  cout << "To create a new entry for a student, type ADD" << endl;
  cout << "To see all students currently stored, type PRINT" << endl;
  cout << "To delete a student entry, type DELETE" << endl;
  cout << "To quit, type QUIT\n" << endl;
  
  while (run == true) {
    cin >> response;
    if (strcmp(response, "ADD") == 0) {
      add(list, fnameinput, lnameinput, idinput, gpainput);
    }
    else if (strcmp(response, "PRINT") == 0) {
      print(list);
    }
    else if (strcmp(response, "DELETE") == 0) {
      deletestudent(list);
    }
    else if (strcmp(response, "QUIT") == 0) {
      run = false;
    }
    else {
      cout << "Please enter a valid command (look above ^^)" << endl << endl;
    }
    
  }
  
  return 0;
}

void add (vector<student*>& list, char fnameinput[99], char lnameinput[99], int idinput,
	  float gpainput) {
  cout << "Enter First Name: ";
  cin >> fnameinput;
  cout << "Enter Last Name: ";
  cin >> lnameinput;
  cout << "Enter ID: ";
  cin >> idinput;
  cout << "Enter gpa: ";
  cin >> gpainput;
  cout << "ADDED" << endl << endl;

  student *s = new student();
  strcpy(s -> fname, fnameinput);
  strcpy(s -> lname, lnameinput);
  s -> id = idinput;
  s -> gpa = gpainput;
  list.push_back(s);

  return;
}

void print (vector<student*>& list) {
  for (vector<student*>::iterator p = list.begin(); p != list.end(); ++p) {
    cout << (*p)->fname << " " << (*p)->lname << ", ";
    cout << (*p)->id << ", ";

    cout.precision (3);
    cout.setf(ios::showpoint);
    cout << (*p)->gpa << endl;
  }
    cout << "PRINTED" << endl << endl;

  return;
}

void deletestudent (vector<student*>& list) {
  int input;
  
  cout << "Please enter ID of student to delete: ";
  cin >> input;
  
  for (vector<student*>::iterator p = list.begin(); p != list.end(); ++p) {
    if ((*p)->id == input) {
      delete *p;
      list.erase(p);
      cout << "DELETED" << endl << endl;
      
      break;
    }
    else {
      cout << "STUDENT DOES NOT EXIST" << endl << endl;
    }
  }

  

  return;
}
