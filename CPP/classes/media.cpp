#include <iostream>
#include "media.h"

/*
 * Media's (parent class) functions
 */

using namespace std;

media::media(char* titleinput, int yearinput) { // constructor
  title = titleinput;
  year = yearinput;
}
void media::print() { 
  cout << endl;
}

media::~media() { // media destructor

}

// getters
char* media::gettitle() { 
  return title;
}
int media::getyear() {
  return year;
}
int media::gettype() {
  return type;
}
