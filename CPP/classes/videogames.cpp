#include <iostream>
#include "videogames.h"

/*
 * Videogames (child) class and functions
 */

using namespace std;

// constructor
videogames :: videogames(char* titleinput, int yearinput, char* publisherinput, float ratinginput) : media(titleinput, yearinput) {
  type = 1;
  title = titleinput;
  year = yearinput;
  publisher = publisherinput;
  rating = ratinginput;
}

// print function
void videogames::print() {
  cout << "Video Game " << endl << "------------" << endl;
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Rating: " << rating << endl;
  cout << endl;
}

// destructor
videogames::~videogames() {
  delete[] title;
  delete[] publisher;
  cout << "DELETED\n" << endl;
}

// getters
char* videogames::getpublisher() {
  return publisher;
}
float videogames:: getrating() {
  return rating;
}
