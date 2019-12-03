#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include "objects.h"

/*
 * Room header file
 */

using namespace std;

class room {
public: // public functions
  room(char* newName);
  char* getName();
  map<char*, room*> getNearRooms();
  vector<objects*>* getRoomObjects();
  void addRoom(char* direction, room* newRoom);
  void addO(objects* object);
  void removeO(objects* object);
  int numberOfObjects();

private: // private variables
  char* name;
  map<char*, room*> nearRooms;
  vector<objects*> *roomObjects;

};
