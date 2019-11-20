#include <iostream>

#ifndef MEDIA_H
#define MEDIA_H

/*
 * Media header file
 */

using namespace std;

class media { // variables passed down to child classes

 // public functions can be accessed anywhere outside the class within the program
 public:
  media(char* title, int year);
  virtual ~media();
  virtual void print();
  
  char* gettitle();
  int getyear();
  int gettype();

 // protected variables shared by all child classes, can be accessed in child classes  
 protected:
  char* title;
  int year;
  int type;

};
#endif
