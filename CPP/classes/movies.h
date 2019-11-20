#include <iostream>
#include "media.h"

/*
 * Movies header file
 */

using namespace std;

class movies : public media{ // child of media
 // public functions 
 public:  
  movies(char* titleinput, char* directorinput, int year, float duration, float rating);
  char* getdirector();
  float getduration();
  float getrating();
  ~movies();
  virtual void print();

 private: // private variables unqiue to movies
  char* director;
  float duration;
  float rating;
  
};
