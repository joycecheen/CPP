#include <iostream>
#include "media.h"

using namespace std;

class videogames : public media {

 public:
  videogames(char* titleinput, int yearinput, char* publisherinput, float ratinginput);
  char* getpublisher();
  float getrating();
  ~videogames();
  virtual void print();

 private:
  char* publisher;
  float rating; 
  
};
