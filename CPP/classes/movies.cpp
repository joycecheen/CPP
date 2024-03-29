#include <iostream>
#include "movies.h"

/*
 * Movie (child) class and functions
 */

using namespace std;

// constructor
movies::movies(char* titleinput, char* directorinput, int yearinput, float durationinput, float ratinginput) : media(titleinput, yearinput) {
  type = 3;
  title = titleinput;
  director = directorinput;
  year = yearinput;
  duration = durationinput;
  rating = ratinginput;
}

// print function
void movies::print() { 
  cout << "Movie " << endl << "-------------" << endl;
  cout << "Title: " << title << endl;
  cout << "Director: " << director << endl;
  cout << "Year: " << year << endl;
  cout << "Duration: " << duration << endl;
  cout << "Rating: " << rating << endl;
  cout << endl;
}

// destructor
movies::~movies() {
  delete[] title;
  delete[] director;
  cout << "DELETED" << endl;
}

// getters
char* movies::getdirector() {
  return director;
}
float movies::getduration() {
  return duration;
}
float movies::getrating() {
  return rating;
}

