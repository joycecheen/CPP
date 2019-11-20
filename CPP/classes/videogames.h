#include <iostream>
#include "media.h"

/*
 * Videogames header file
 */

using namespace std;

class videogames : public media { // child of media

 // public functions 
 public:
  videogames(char* titleinput, int yearinput, char* publisherinput, float ratinginput);
  char* getpublisher();
  float getrating();
  ~videogames();
  virtual void print();

 // private variables unique to videogames 
 private:
  char* publisher;
  float rating; 
  
};
