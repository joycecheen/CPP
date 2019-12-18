#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H

/*
 * Student header file
 */

class Student {
 public:
  Student(char* firstInput, char* lastInput, int IDInput, float GPAInput);
  ~Student();
  char* getFirst();
  char* getLast();
  int getID();
  float getGPA();
  void printStudent();

 private:
  char* firstName;
  char* lastName;
  int ID;
  float GPA;

};

#endif
