#include <iostream>
#include "videogames.h"

using namespace std;

videogames :: videogames(char* titleinput, int yearinput, char* publisherinput, float ratinginput) : media(titleinput, yearinput) {
  type = 1;
  title = titleinput;
  year = yearinput;
  publisher = publisherinput;
  rating = ratinginput;
}

void videogames::print() {
  cout << "Video Game " << endl << "------------" << endl;
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Rating: " << rating << endl;
  cout << endl;
}

videogames::~videogames() {
  delete[] title;
  delete[] publisher;
  cout << "DELETED\n" << endl;
}

char* videogames::getpublisher() {
  return publisher;
}
float videogames:: getrating() {
  return rating;
}
