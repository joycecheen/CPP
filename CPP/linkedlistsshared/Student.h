#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H

// Student header file

class Student {
public: // public functions
  Student(char* firstInput, char* lastInput, int IDInput, float GPAInput); // student constructor
  ~Student(); // destructor
  char* getFirst(); // get first name
  char* getLast(); // get last name
  int getID(); // get student ID
  float getGPA(); // get student GPA
  void printStudent(); // print all student info

private: // private variables
  char* firstName;
  char* lastName;
  int ID;
  float GPA;

};

#endif
