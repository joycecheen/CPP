#include <iostream>
#include <stdlib.h>
#include <time.h>

/* 
 * Computer picks a random number 0-100 and the user will try to guess the number.
 * Author: Joyce Chen
 * Date: 9/12/2019
 */

using namespace std;

int main() {

  // set random seed
  srand(time(NULL));

  bool game = true;
  char gameinput;
  int input;

  // loop for playing again
    while (game == true) {
      // create random number and reset counter to zero
      int random = rand() % 100 + 1;
      int counter = 0;
        // when user hasn't yet guessed the number
        while (input != random) {
	  // read in guess
	  cout << "please enter your guess: "; 
	  cin >> input;
	    // compare guess to random number
            if (input > random) {
	      cout << "too high!" << endl;
	      counter++;
            }
	    else if (input < random) {
	      cout << "too low!" << endl;
	      counter++;
	    }
	    else if (input == random) {
	      cout << "correct! it took you " << ++counter << " guesses" << endl;
	    }
      }
      // ask if user wants to play again
      cout << "play again? (y or n) " << endl;
      cin >> gameinput;
        // if yes, restart game
        if (gameinput == 'y') {
	  game = true;
        }
	// if no, exit
	else if (gameinput == 'n') {
	  game = false;
	}
    }
  
  return 0;
}
