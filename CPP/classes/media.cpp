#include <iostream>
#include "media.h"

using namespace std;

media::media(char* titleinput, int yearinput) {
  title = titleinput;
  year = yearinput;
}
void media::print() {
  cout << endl;
}

media::~media() {

}

char* media::gettitle() {
  return title;
}
int media::getyear() {
  return year;
}
int media::gettype() {
  return type;
}
