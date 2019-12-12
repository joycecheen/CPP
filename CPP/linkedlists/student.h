#include <iostream>
#include <string.h>

#ifndef STUDENT_H
#define STUDENT_H

/*
 * Student header file
 */

using namespace std;

class student {
 public:
  student(char* fnameinput, char* lnameinput, int idinput, float gpainput);
  ~student();
  char* getfname();
  char* getlname();
  int getid();
  float getgpa();
  void printstudent();
  
 private:
  char* fname[99];
  char* lname[99];
  int id;
  float gpa;
  
}; #endif
