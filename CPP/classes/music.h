#include <iostream>
#include "media.h"

using namespace std;

class music : public media {

 public:
  music(char* titleinput, char* artistinput, int yearinput, float durationinput, char* publisherinputs);
  char* getartist();
  float getduration();
  char* getpublisher();
  ~music();
  virtual void print();

 private:
  char* artist;
  float duration;
  char* publisher;

};
