#include <iostream>
#include "media.h"

/*
 * Music header file
 */

using namespace std;

class music : public media { // child of media

 // public functions 
 public: 
  music(char* titleinput, char* artistinput, int yearinput, float durationinput, char* publisherinputs);
  char* getartist();
  float getduration();
  char* getpublisher();
  ~music();
  virtual void print();

 // private variables individual to music
 private:
  char* artist;
  float duration;
  char* publisher;

};
