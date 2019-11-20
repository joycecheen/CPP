#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

int main () {
  // create items
  Objects *linen = new Objects("Linen");
  Objects *paletteKnife = new Objects("Palette Knife");
  Objects *oilPaint = new Objects("Oil Paint");
  Objects *linseedOil = new Objects("Linseed Oil");
  Objects *brushes = new Objects("Brushes");
  Objects *turpentine = new Objects("Turpentine");

  // create rooms and add items to rooms
  Room *lobby = new Room("Lobby");
  Room *library = new Room("Library");
  Room *archives = new Room("Archives");
  archives -> addObject(turpentine);
  Room *store = new Room("Store");
  Room *restroom = new Room("Restroom");
  restroom -> addObject(linseedOil);
  Room *modernAndContemporaryArt = new Room("Modern and Contemporary Art";)
  Room *sculptures = new Room("Sculptures");
  sculptures -> addObject(paletteKnife);
  Room *europeanArt = new Room("European Art");
  europeanArt -> addObject(oilPaint);
  Room *specialExhibition = new Room("Special Exhibition");
  Room *photography = new Room("Photography");
  Room *medievalArt = new Room("Medieval Art");
  Room *mainEntrance = new Room("Main Entrance");
  Room *frenchImpressionism = new Room("French Impressionism");
  frenchImpressionism -> addObject(brushes);
  Room *asianArt = new Room("Asian Art");
  asianArt -> addObject(linen);
  Room *studyGallery = new Room("Study Gallery");
  Room *romanCourt = new Room("Roman Court");

  return 0;
}

void printOps () {

  return;
}

void printWelcome () {

  return;
}
