#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "objects.h"

/* Zuul: A text-based adventure game with rooms and items
 * Author: Joyce Chen
 * Date: 12/2/19
 */

using namespace std;

// function prototypes
void printOps(room *current, vector<objects*> *inventory);
void printWelcome();

int main () {
  // create items
  objects *linen = new objects((char*)"Linen");
  objects *paletteKnife = new objects((char*)"Palette Knife");
  objects *oilPaint = new objects((char*)"Oil Paint");
  objects *linseedOil = new objects((char*)"Linseed Oil");
  objects *brushes = new objects((char*)"Brushes");
  objects *turpentine = new objects((char*)"Turpentine");
  
  // create rooms and add items to rooms
  room *lobby = new room((char*)"Lobby");
  room *library = new room((char*)"Library");
  room *archives = new room((char*)"Archives");
  archives -> addO(turpentine);
  room *store = new room((char*)"Store");
  room *restroom = new room((char*)"Restroom");
  restroom -> addO(linseedOil);
  room *modernAndContemporaryArt = new room((char*)"Modern and Contemporary Art");
  room *sculptures = new room((char*)"Sculptures");
  sculptures -> addO(paletteKnife);
  room *europeanArt = new room((char*)"European Art");
  europeanArt -> addO(oilPaint);
  room *specialExhibition = new room((char*)"Special Exhibition");
  room *photography = new room((char*)"Photography");
  room *medievalArt = new room((char*)"Medieval Art");
  room *mainEntrance = new room((char*)"Main Entrance");
  room *frenchImpressionism = new room((char*)"French Impressionism");
  frenchImpressionism -> addO(brushes);
  room *orientalArt = new room((char*)"Oriental Art");
  orientalArt -> addO(linen);
  room *studyGallery = new room((char*)"Study Gallery");
  room *romanCourt = new room((char*)"Roman Court");

  // add exits to maps of exits
  lobby -> addRoom((char*)"NORTH", modernAndContemporaryArt);
  lobby -> addRoom((char*)"EAST", store);
  lobby -> addRoom((char*)"SOUTH", mainEntrance);
  lobby -> addRoom((char*)"WEST", library);

  library -> addRoom((char*)"WEST", archives);
  library -> addRoom((char*)"EAST", lobby);

  archives -> addRoom((char*)"EAST", library);

  store -> addRoom((char*)"NORTH", europeanArt);
  store -> addRoom((char*)"EAST", restroom);
  store -> addRoom((char*)"WEST", lobby);

  restroom -> addRoom((char*)"NORTH", medievalArt);
  restroom -> addRoom((char*)"WEST", store);

  modernAndContemporaryArt -> addRoom((char*)"NORTH", sculptures);
  modernAndContemporaryArt -> addRoom((char*)"EAST", europeanArt);
  modernAndContemporaryArt -> addRoom((char*)"SOUTH", lobby);

  sculptures -> addRoom((char*)"EAST", specialExhibition);
  sculptures -> addRoom((char*)"SOUTH", modernAndContemporaryArt);

  europeanArt -> addRoom((char*)"NORTH", specialExhibition);
  europeanArt -> addRoom((char*)"EAST", medievalArt);
  europeanArt -> addRoom((char*)"SOUTH", store);
  europeanArt -> addRoom((char*)"WEST", modernAndContemporaryArt);

  specialExhibition -> addRoom((char*)"NORTH", photography);
  specialExhibition -> addRoom((char*)"WEST", sculptures);

  photography -> addRoom((char*)"SOUTH", specialExhibition);

  medievalArt -> addRoom((char*)"SOUTH", restroom);
  medievalArt -> addRoom((char*)"WEST", europeanArt);

  mainEntrance -> addRoom((char*)"NORTH", lobby);
  mainEntrance -> addRoom((char*)"SOUTH", frenchImpressionism);

  frenchImpressionism -> addRoom((char*)"NORTH", mainEntrance);
  frenchImpressionism -> addRoom((char*)"EAST", orientalArt);
  frenchImpressionism -> addRoom((char*)"SOUTH", studyGallery);
  
  orientalArt -> addRoom((char*)"SOUTH", romanCourt);
  orientalArt -> addRoom((char*)"WEST", frenchImpressionism);

  studyGallery -> addRoom((char*)"NORTH", frenchImpressionism);
  studyGallery -> addRoom((char*)"EAST", romanCourt);

  romanCourt -> addRoom((char*)"NORTH", orientalArt);
  romanCourt -> addRoom((char*)"WEST", studyGallery);
  
  // game starts at main entrance room
  room *current = mainEntrance;
  // users inventory, a vector of objects
  vector<objects*> *inventory = new vector<objects*>();

  bool run = true;
  char* input = new char(20);
  int c = 0;
  int hasknife = 0;

  // print game welcome text 
  printWelcome();
  
  while (run == true) { // if user has not quit yet

    if (inventory -> size() == 6) { // user wins if all 6 items are picked up
      cout << "+｡:.ﾟヽ(´∀`｡)ﾉﾟ.:｡+ﾟ YOU WON! ﾟ+｡:.ﾟヽ(*´∀`)ﾉﾟ.:｡+ﾟ" << endl;
      cout << "All 6 items were successfully picked up so you escaped the heavy fine" << endl;
      cout << endl << "G A M E   O V E R";
      run = false;
      return 0;
    }

    if ((current == archives) && (c == 0)) { // if user enters archives for the first time, ghost appears
      cout << "( ﾉ ಠдಠ)ﾉ  The rumored ghost appears!" << endl;
      if (inventory -> size() == 0) { // if inventory is empty, user loses
	cout << "You don't have anything to protect yourself with so the ghost eats you" << endl;
        cout << endl << "(╯︵╰,)  YOU LOST  (╯︵╰,)" << endl;
        cout << endl << "G A M E   O V E R";
        run = false;
	return 0;
      }
      for (int i = 0; i < inventory -> size(); i++) {
	if (strcmp((char*)"Palette Knife", inventory -> at(i) -> getName()) == 0) { // user survives if they have palette knife in inventory
	  cout << "You pull out the palette knife you picked up from the Sculptures Room" << endl;
	  cout << "ԅ(‹o›Д‹o›ԅ)  The ghost gets scared and runs away" << endl << endl;
	  hasknife++;
	}
      }
      if (hasknife == 0){ // if no palette knife, user loses
	  cout << "You don't have anything to protect yourself with so the ghost eats you" << endl;
	  cout << endl << "(╯︵╰,)  YOU LOST  (╯︵╰,)" << endl;
	  cout << "G A M E   O V E R";
	  run = false;
	  return 0;;
       }
      c++;
    }
    
    printOps(current, inventory); // print options
    cin.getline(input, 20); // read in users command

    if (strcmp("PICK", input) == 0) { // if user chooses to pick up an object
      char* objectPick = new char(20);
      int z = 0;
      
      if (current -> numberOfObjects() == 0) {
	cout << "Not a valid command" << endl;
      }
      else {
	cout << "Please input the name of the object you want to pick up: ";
	cin.getline(objectPick, 20);
	for (int i = 0; i < current -> numberOfObjects(); i++) { // run through room objects
	  if (strcmp(objectPick, current -> getRoomObjects() -> at(i) -> getName()) == 0) {
	    inventory -> push_back(current -> getRoomObjects() -> at(i)); // add object to user inv
	    current -> removeO(current -> getRoomObjects() -> at(i)); // remove from room
	    cout << "PICKED UP" << endl;
	    z++;
	    break;
	  }
	}
	if (z == 0) {
	  cout << "Object does not exist in this room" << endl;
	}
      }
    }
    
    else if (strcmp("DROP", input) == 0) { // if user wants to drop an object from inventory
      char* objectDrop = new char(20);
      int z = 0;
      
      if (inventory -> size() == 0) {
	cout << "Not a valid command" << endl;
      }
      else {
	cout << "Please input the name of the object you want to drop: ";
	cin.getline(objectDrop, 20);

	for (int i = 0; i < inventory -> size(); i++) { // run through user inventory
	  if (strcmp(objectDrop, inventory -> at(i) -> getName()) == 0) { // find match to input
	    current -> addO(inventory -> at(i)); // add object to room 
	    inventory -> erase(inventory -> begin() + i); // remove object from user inventory
	    cout << "DROPPED" << endl;
	    z++;
	    break;
	  }
	}
	if (z == 0) {
	  cout << "Object does not exist" << endl;
	}
      }
    }
    else if (strcmp("QUIT", input) == 0) { // if user wants to quit, stop running and return
      run = false;
      cout << endl << "G A M E   O V E R";
      return 0;
    }

    
    map<char*, room*> :: iterator iter = current -> getNearRooms().begin();

    // run through room exits  
    for (int i = 0; i < current -> getNearRooms().size(); i++) {
      if (strcmp(iter -> first, input) == 0) { // if input matches with an existing exit
	current = iter -> second; // move to chosen exit
	break;
      }
      iter++;
    }

    cout << endl << endl; 

  }
  
  return 0;
}

// function to print options
void printOps (room *current, vector<objects*> *inventory) {
  // print current room
  cout << "Currently, you are in " << current -> getName() << endl;

  // print objects in current room
  if (current -> numberOfObjects() == 0) { 
    cout << "There are no objects in this room" << endl;
  }
  else { 
    cout << "The objects in this room are: ";
    for (int i = 0; i < current -> numberOfObjects(); i++) {
      cout << current -> getRoomObjects() -> at(i) -> getName() << "   ";
    }
    cout << endl << endl;
  }

  // print user inventory
  cout << "┏ 　　　　　               ┐" << endl;
  cout << "     I N V E N T O R Y      " << endl;

  if (inventory -> size() == 0) {
    cout << "          empty             " << endl;
  }
  else {
    for (int i = 0; i < inventory -> size(); i++) {
      cout << inventory -> at(i) -> getName() << "   ";
    }
    cout << endl;
  }
  cout << "└ 　　　　　               ┛" << endl << endl;

  // print command options for user
  cout << "------------------------" << endl;
  cout << "C O M M A N D S" << endl;

  map<char*, room*> :: iterator iter = current -> getNearRooms().begin();
  for (int i = 0; i < current -> getNearRooms().size(); i++) { // print exits
    cout << "Type " << iter -> first << " to go to " << iter -> second -> getName() << endl;
    iter++;
  }
  cout << endl;
  
  if (current -> numberOfObjects() != 0) { // print pick up command if there are objects in room
    cout << "Type PICK to pick an object up from this room" << endl << endl;
  }
  if (inventory -> size() != 0) { // print drop command if inventory is not empty
    cout << "Type DROP to drop an object from your inventory" << endl << endl;
  }
  cout << "Type QUIT to quit game" << endl; // print quit command
  
  cout << "------------------------" << endl;
  
  return;
}

// function to print welcome text
void printWelcome () {
  cout << "        - WELCOME TO ZUUL -        " << endl;
  cout << "    a text based adventure game    " << endl;
  cout << "✧･ﾟ: *✧･ﾟ:* *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:**:" << endl << endl;
  cout << "You are in an Art Museum, but you tripped and ruined a painting..oops" << endl;
  cout << "There are 6 items scattered around the museum which are needed to fix it" << endl;
  cout << "Collect all 6 items to save yourself from paying a heavy fine!" << endl << endl;
  cout << "P.S. Be careful of the ghost in the Archives... hint: it is scared of palette knives" << endl;
  cout << "Good Luck! :)" << endl << endl;
  cout << "✧･ﾟ: *✧･ﾟ:* *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:**:" << endl << endl << endl;

  return;
}
