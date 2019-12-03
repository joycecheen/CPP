#include <iostream>
#include "objects.h"

/*
 * Object class and functions
 */

objects::objects(char* newName) { // object constructor
  name = newName;
}

char* objects::getName() { // get object name
  return name;
}
