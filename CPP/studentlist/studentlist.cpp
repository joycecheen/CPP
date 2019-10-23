#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <string.h>

struct student {
  char fname[99] = {};
  char lname[99] = {};
  int id;
  float gpa;
};

using namespace std;

int main() {
  vector<student> list;
  
  char fnameinput[99] = {};
  char lnameinput[99] = {};
  int idinput;
  float gpainput;

  cout <<  endl << "Enter First Name: ";
  cin >> fnameinput;
  cout << "Enter Last Name: ";
  cin >> lnameinput;
  cout << "Enter ID: ";
  cin >> idinput;
  cout << "Enter gpa: ";
  cin >> gpainput;

  student s;
  strcpy(s.fname, fnameinput);
  strcpy(s.lname, lnameinput);
  s.id = idinput;
  s.gpa = gpainput;
  list.push_back(s);

  cout << gpainput;
  
  for (vector<student>::iterator p = list.begin(); p != list.end(); ++p) {
    cout << p->fname << " " << p->lname << endl;
    cout << p->id << " " << p->gpa << endl;
  }
  
  return 0;
}
