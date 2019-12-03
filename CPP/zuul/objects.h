#include <iostream>

#ifndef OBJECTS_H
#define OBJECTS_H

/*
 * Objects header file
 */

using namespace std;

class objects {
public: // public functions
  objects(char* newName);
  char* getName();
  ~objects();

private: // private variables
  char* name;

};
#endif
