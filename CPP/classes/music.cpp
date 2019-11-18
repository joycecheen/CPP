#include <iostream>
#include "music.h"

using namespace std;

music::music(char* titleinput, char* artistinput, int yearinput, float durationinput, char* publisherinput) : media(titleinput, yearinput) {
  type = 2;
  title = titleinput;
  artist = artistinput;
  year = yearinput;
  duration = durationinput;
  publisher = publisherinput;
}

void music::print() {
  cout << "Music" << endl << "------------" << endl;
  cout << "Title: " << title << endl;
  cout << "Artist: " << artist << endl;
  cout << "Year: " << year << endl;
  cout << "Duration: " << duration << endl;
  cout << "Publisher: " << publisher << endl;
  cout << endl;
}

music::~music() {
  delete[] title;
  delete[] publisher;
  delete[] artist;
  cout << "DELETED\n" << endl;
}

char* music::getartist() {
  return artist;
}
float music::getduration() {
  return duration;
}
char* music::getpublisher() {
  return publisher;
}


