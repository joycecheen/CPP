#include <iostream>
#include <vector>
#include <cstring>
#include "videogames.h"
#include "music.h"
#include "movies.h"
#include "media.h"

/* Name: Joyce Chen
 * Date: 11/18/19
 * Classes- Create a database that includes video games, music, and movies  
 */

using namespace std;

// function prototypes
void addM(vector<media*> *medialist);
void searchM(vector<media*> *medialist);
void deleteM(vector<media*> *medialist);

int main() {
  vector<media*>* medialist = new vector<media*>();
  char *response = new char(10);
  bool run = true;

  // give user instructions
  cout << "To add a media, type ADD" << endl;
  cout << "To search for a media, type SEARCH" << endl;
  cout << "To delete a media, type DELETE" << endl;
  cout << "To quit, type QUIT\n" << endl;

  while (run == true) { // while user has not quit yet
    cin >> response;
    if (strcmp(response, "ADD") == 0) { // if add media, run add function
      addM(medialist);
      medialist -> at(medialist -> size() - 1) -> print();
    }
    else if (strcmp(response, "SEARCH") == 0) { // if search media, run search function
      searchM(medialist);
    }
    else if (strcmp(response, "DELETE") == 0) { // if delete media, run delete function
      deleteM(medialist);
    }
    else if (strcmp(response, "QUIT") == 0) { // if quit, set run to false
      run = false;
    }
    else { // if not valid command, tell user
      cout << "Please enter a valid command (look above ^^)" << endl << endl;
    }
  }
  return 0;
}

void addM (vector<media*> *medialist) { // to add a media
  int type;

  // ask and get media type
  cout << "To add a video game, type 1" << endl;
  cout << "To add music, type 2" << endl;
  cout << "To add a movie, type 3" << endl;
  cin >> type;
  cin.ignore();

  if (type == 1) { // add videogame
    char* title = new char(100);
    int year = 0;
    char* publisher = new char(100);
    float rating = 0;

    // ask and get videogame info
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

    // add videogame to vector medialist
    videogames *s = new videogames(title, year, publisher, rating);
    medialist -> push_back(s);
    cout << "ADDED..." << endl;

    return; 
  }
  else if (type == 2) { // add music
    char* title = new char(100);
    char* artist = new char(100);
    int year = 0;
    float duration = 0;
    char* publisher = new char(100);

    // ask and get music info
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

    // add music to vector medialist
    music *s = new music(title, artist, year, duration, publisher);
    medialist -> push_back(s);

    return;
  }
  else if (type == 3) { // add movie
    char* title = new char(100);
    char* director = new char(100);
    int year = 0;
    float duration = 0;
    float rating = 0;

    // ask and get movie info
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

    // add movie to vector medialist
    movies *s = new movies(title, director, year, duration, rating);
    medialist -> push_back(s);

    return;
  }
  return;
}

void searchM(vector<media*> *medialist) { // to search for a media
  char response[10];
  int z = 0;

  // tell user directions to search 
  cout << "To search by title, type TITLE" << endl;
  cout << "To search by year, type YEAR" << endl;

  cin >> response;
  cin.ignore();

  if (strcmp(response, "TITLE") == 0) { // if search by title
    cout << "Input Title: ";
    char* title = new char(100); 
    cin.getline(title, 100); // get title
    
    for (int i = 0; i < medialist -> size(); i++) { // run through media list and search for matching title
      if (strcmp(medialist -> at(i) -> gettitle(), title) == 0) {
	medialist -> at(i) -> print();
	z++; // add to found counter
      }
    }
    
  }
  else if (strcmp(response, "YEAR") == 0) { // if search by year  
    cout << "Input Year: ";
    int year;
    cin >> year; // get year

    for (int i = 0; i < medialist -> size(); i++) { // run through media list and search for matching year
      if (medialist -> at(i) -> getyear() == year) {
	medialist -> at(i) -> print();
	z++; // add to found counter
      }
    }
  }
  else { // if user does not type TITLE or YEAR, tell them
    cout << "To search, please type TITLE or YEAR" << endl;
  }

  if (z == 0) { // if found counter is zero, so nothing found, tell user
    cout << "NOTHING FOUND\n" << endl;
  }
  
  return;
}

void deleteM(vector<media*> *medialist) { // to delete a media
  char response[10];

  // tell user directions to delete
  cout << "To delete by title, type TITLE" << endl;
  cout << "To delete by year, type YEAR" << endl;

  cin >> response;
  cin.ignore();

  if (strcmp(response, "TITLE") == 0) { // if delete by title
    char response;
    char* title = new char(100);
    int z = 0;

    cout << "Input Title: ";
    cin.getline(title, 100); // get title

    for (int i = 0; i < medialist -> size(); i++) { // run through media list and search for matching title
      if (strcmp(medialist -> at(i) -> gettitle(), title) == 0) {
	cout << "Are you sure you want to delete ... " << endl; // ask user to confirm deletion
	medialist -> at(i) -> print();
	cout << "(y/n): ";
	cin >> response;
	if (response == 'y') { // if yes, procede with deletion
	  delete medialist -> at(i);
	  medialist -> erase(medialist -> begin() + i);
	  break;
	}
	else if (response == 'n') { // if no, cancel deletion
	  cout << "DELETION CANCELLED" << endl;
	}
	z++; // add to found counter
      }
      if (z == 0) { // if found counter is zero, nothing was found and tell user
	cout << "NOTHING FOUND\n" << endl;
      }
    }
  }
  else if (strcmp(response, "YEAR") == 0) { // if delete by year
    int year;
    char response;
    int z = 0;

    cout << "Input Year: "; 
    cin >> year; // get year

    for (int i = 0; i < medialist -> size(); i++) { // run through media list and search for matching year
      if (medialist -> at(i) -> getyear() == year) {
	cout << "Are you sure you want to delete ... " << endl << endl; // ask user to confirm deletion
	medialist -> at(i) -> print();
	cout << "(y/n): ";
	cin >> response;
	if (response == 'y') { // if yes, procede with deletion
	  delete medialist -> at(i);
	  medialist -> erase(medialist -> begin() + i);
	  break;
	}
	else if (response == 'n') { // if no, cancel deletion
	  cout << "DELETION CANCELLED" << endl;
	}
	z++; // add to found counter
      }
      if (z == 0) { // if found counter is zero, nothing was found and tell user
	cout << "NOTHING FOUND\n" << endl;
      }
    }
  }  
  else { // if user doesn't type TITLE or YEAR, tell user
    cout << "To delete, please type TITLE or YEAR" << endl;
  }
  
  return;
}

