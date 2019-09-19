#include <iostream>
#include <stdlib.h>
#include <cstring>

/*
 * A program that reads a series of characters and checks to see if it is a palindrome 
 * Author: Joyce Chen
 * Date: 9/16/2019
 *
 */

using namespace std;

int main() {

  char input[80];
  char output[80];
  int index = 0;

  cin.get(input, 80);
  
  for (int i = 0; i < 80; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') {
      output[index] = input[i];
      index++;
    }
  }

  output[index] = '\0';
  
  /*for (int j = 0; j < 80; j++) {
    if (!(output[j] >= 'a' && output[j] <= 'z' && output[j] >= 'A' && output[j] <= 'Z')) {
	output[j] = '\0';
    }
  }*/

  

  cout << output << endl;

  return 0;
}
