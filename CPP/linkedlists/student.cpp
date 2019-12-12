#include <iostream>
#include <string.h>
#include "student.h"

using namespace std;

student::student(char* fnameinput, char* lnameinput, int idinput, float gpainput) {
  fname = fnameinput;
  lname = lnameinput;
  id = idinput;
  gpa = gpainput;
}
student::~student() {
  delete fname;
  delete lname;
}
char* student::getfname() {
  return fname;
}
char* student::getlname() {
  return lname;
}
int student::getid() {
  return id;
}
float student::getgpa() {
  return gpa;
}
void student::printstudent() {
  cout << "Name: " << fname << lname << endl;
  cout << "ID: " << id << endl;

  cout.precision (2);
  cout.setf(ios::showpoint);
  cout << "GPA: " << fixed << gpa << endl;
				     
}
