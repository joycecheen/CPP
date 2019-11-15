#include <iostream>

#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class media {

 public:
  media(char* title, int year);
  virtual ~media();
  virtual void print();
  
  char* gettitle();
  int getyear();
  int gettype();

 protected:
  char* title;
  int year;
  int type;

};
#endif
