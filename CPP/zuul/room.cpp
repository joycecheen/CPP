#include <iostream>
#include "room.h"
#include <vector>
#include <map>
#include <cstring>

/*
 * Room class and functions
 */

room::room(char* newName) { // constructor
  name = newName;
  roomObjects = new vector<objects*>;
}

char* room::getName() { // get name function
  return name;
}

void room::addRoom(char* direction, room* nearRoom) { // add exits to room function
  nearRooms[direction] = nearRoom;
}

void room::addO(objects *object) { // add object to vector of objects in room
  roomObjects -> push_back(object);
}

void room::removeO(objects *object) { // remove object from vector of objects in room
  for (int i = 0; i < roomObjects -> size(); i++) {
    // check object exists in room
    if (strcmp(roomObjects -> at(i) -> getName(), object -> getName()) == 0) { 
      roomObjects -> erase(roomObjects -> begin() + i);
      break;
    }
  }
}

int room::numberOfObjects() { // return number of objects in room
  return roomObjects -> size();
}

vector<objects*>* room::getRoomObjects() { // return vector of objects in room
  return roomObjects;
}

map<char*, room*> room::getNearRooms() { // return map of exits of room
  return nearRooms;
}


