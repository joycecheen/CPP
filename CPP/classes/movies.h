#include <iostream>
#include "media.h"

using namespace std;

class movies : public media{
 public:
  movies(char* titleinput, char* directorinput, int year, float duration, float rating);
  char* getdirector();
  float getduration();
  float getrating();
  ~movies();
  virtual void print();

 private:
  char* director;
  float duration;
  float rating;
  
};
