#include <iostream>
#include <vector>
#include <cstring>
#include "videogames.h"
#include "music.h"
#include "movies.h"
#include "media.h"

using namespace std;

void addM(vector<media*> *medialist);
void searchM(vector<media*> *medialist);
void deleteM(vector<media*> *medialist);

int main() {
  vector<media*>* medialist = new vector<media*>();
  char *response = new char(10);
  bool run = true;

  cout << "To add a media, type ADD" << endl;
  cout << "To search for a media, type SEARCH" << endl;
  cout << "To delete a media, type DELETE" << endl;
  cout << "To quit, type QUIT\n" << endl;
  
  while (run == true) {
    cin >> response;
    if (strcmp(response, "ADD") == 0) {
      addM(medialist);
      medialist -> at(medialist -> size() - 1) -> print();
    }
    else if (strcmp(response, "SEARCH") == 0) {
      searchM(medialist);
    }
    else if (strcmp(response, "DELETE") == 0) {
      deleteM(medialist);
    }
    else if (strcmp(response, "QUIT") == 0) {
      run = false;
    }
    else {
      cout << "Please enter a valid command (look above ^^)" << endl << endl;
    }
    
  }
  
  return 0;
}

void addM (vector<media*> *medialist) {
  int type;

  cout << "To add a video game, type 1" << endl;
  cout << "To add music, type 2" << endl;
  cout << "To add a movie, type 3" << endl;
  cin >> type;
  cin.ignore();

  if (type == 1) { // videogame
    char* title = new char(100);
    int year = 0;
    char* publisher = new char(100);
    float rating = 0;

    cout << "Enter Video Game Title: ";
    cin.getline(title, 100);
    cout << "Enter Video Game Year: ";
    cin >> year;
    cin.ignore();
    cout << "Enter Video Game Publisher: ";
    cin.getline(publisher, 100);
    cout << "Enter Video Game Rating: ";
    cin >> rating;
    cin.ignore();
    cout << endl;

    videogames *s = new videogames(title, year, publisher, rating);
    medialist -> push_back(s);

    return; 
  }
  else if (type == 2) { // music
    char* title = new char(100);
    char* artist = new char(100);
    int year = 0;
    float duration = 0;
    char* publisher = new char(100);

    cout << "Enter Music Title: ";
    cin.getline(title, 100);
    cout << "Enter Music Artist: ";
    cin.getline(artist, 100);
    cout << "Enter Music Year: ";
    cin >> year;
    cout << "Enter Music Duration: ";
    cin >> duration;
    cin.ignore();
    cout << "Enter Music Publisher: ";
    cin.getline(publisher, 100);
    cout << endl;

    music *s = new music(title, artist, year, duration, publisher);
    medialist -> push_back(s);

    return;
  }
  else if (type == 3) { // movies
    char* title = new char(100);
    char* director = new char(100);
    int year = 0;
    float duration = 0;
    float rating = 0;

    cout << "Enter Movie Title: ";
    cin.getline(title, 100);
    cout << "Enter Movie Director: ";
    cin.getline(director,100);
    cout << "Enter Movie Year: ";
    cin >> year;
    cout << "Enter Movie Duration: ";
    cin >> duration;
    cout << "Enter Movie Rating: ";
    cin >> rating;
    cout << endl;

    movies *s = new movies(title, director, year, duration, rating);
    medialist -> push_back(s);

    return;
  }
  return;
}

void searchM(vector<media*> *medialist) {
  char response[10];
  
  cout << "To search by title, type TITLE" << endl;
  cout << "To search by year, type YEAR" << endl;

  cin >> response;

  if (strcmp(response, "TITLE") == 0) {
    cout << "Input Title: ";
    char* title = new char(100);
    cin.getline(title, 100);
    
    for (int i = 0; i < medialist -> size(); i++) {
      if (strcmp(medialist -> at(i) -> gettitle(), title) == 0) {
	medialist -> at(i) -> print();
      }
      else {
	cout << "NOTHING FOUND" << endl;
      }
    }
    
  }
  else if (strcmp(response, "YEAR") == 0) {
    cout << "Input Year: ";
    int year;
    cin >> year;

    for (int i = 0; i < medialist -> size(); i++) {
      if (medialist -> at(i) -> getyear() == year) {
	medialist -> at(i) -> print();
      }
      else {
	cout << "NOTHING FOUND" << endl;
      }
    }
  }
  else {
    cout << "To search, please type TITLE or YEAR" << endl;
  }
  
  return;
}

void deleteM(vector<media*> *medialist) {
  char response[10];

  cout << "To delete by title, type TITLE" << endl;
  cout << "To delete by year, type YEAR" << endl;

  cin >> response;

  if (strcmp(response, "TITLE") == 0) {
    char response;
    char* title = new char(100);

    cout << "Input Title: ";
    cin.getline(title, 100);

    for (int i = 0; i < medialist -> size(); i++) {
      if (strcmp(medialist -> at(i) -> gettitle(), title) == 0) {
	cout << "Are you sure you want to delete , y/n: " << endl;
	cin >> response;
	if (response == 'y') {
	  delete medialist -> at(i);
	  medialist -> erase(medialist -> begin() + i);
	  i--;
	}
	else if (response == 'n') {
	  cout << "DELETION CANCELLED" << endl;
	}
      }
      else {
	cout << "NOTHING FOUND" << endl;
      }
    }
  }
  else if (strcmp(response, "YEAR") == 0) {
    int year;
    char response;

    cout << "Input Year: ";
    cin >> year;

    for (int i = 0; i < medialist -> size(); i++) {
      if (medialist -> at(i) -> getyear() == year) {
	cout << "Are you sure you want to delete, y/n: " << endl;
	cin >> response;
	if (response == 'y') {
	  delete medialist -> at(i);
	  medialist -> erase(medialist -> begin() + i);
	  i--;
	}
	else if (response == 'n') {
	  cout << "DELETION CANCELLED" << endl;
	}
      }
      else {
	cout << "NOTHING FOUND" << endl;
      }
    }
  }  
  else {
    cout << "To delete, please type TITLE or YEAR" << endl;
  }
  
  return;
}

