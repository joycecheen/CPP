#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H

/*
 * Student header file
 */

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
  char* fname;
  char* lname;
  int id;
  float gpa;
  
};

#endif
