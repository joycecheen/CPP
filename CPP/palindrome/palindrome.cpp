#include <iostream>
#include <stdlib.h>
#include <cstring>

/*
 * A program that reads a series of characters, removes non-letters,
 * and checks to see if it is a palindrome 
 * 
 * Author: Joyce Chen
 * Date: 9/16/2019
 *
 */

using namespace std;

int main() {

  // char arrays + variables
  char input[80] = {};
  char output[80] = {};
  int index = 0;
  bool check; 

  // read in users word/phrase
  cout << "Input: ";
  cin.get(input, 80);

  // take all chars that are letters and put into new array  
  for (int i = 0; i < 80; i++) {
    if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
      output[index] = input[i];
      index++;
    }
  }

  // add in null character at the end of new array
  output[index] = '\0';

  // to check if its a palindrome
  // compare first to last char, then second to second to last, etc.
  for (int j = 0; j < index; j++) {
    // set to uppercase
    output[j] = toupper( output[j] );
    output[index - 1] = toupper( output[index - 1] );
    if (output[j] == output[index - 1]) {
      check = true;
      index--;
    } 
    else {
      check = false;
      break;
    }
  }
  
  // print whether or not it is a palindrome based on check
  if (check == true) {
    cout << "Palindrome" << endl;
  }
  else if (check == false) {
    cout << "Not a palindrome" << endl;
  }
  
  return 0;
}
