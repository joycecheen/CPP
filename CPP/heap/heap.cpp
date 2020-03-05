#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

// i want to die ^.^

void heap(int * array, int len, int i);

int main() {
  char input[10];
  int num = 0;
  int * array = new int[100];
  char * arrayC = new char[500];
  bool run = true;

  while (run == true) {
    cout << "Type TYPE to input by terminal line" << endl;
    cout << "Type FILE to input by file" << endl;
    cout << "Type QUIT to quit" << endl;

    cin >> input;
    cin.ignore();

    if (strcmp(input, "TYPE") == 0) {
      cout << "Enter number of elements of array: ";
      cin >> num;
      cin.ignore();
      cout << "Enter each number followed with a space: ";
      cin.getline(arrayC, 500);

      cout << arrayC << endl;

      //parse
      int count;
      int exp;
      int num;
      int total;
      int j = 0;

      for (int i = 0; i < 100; i++) {
	//Null character
	if (arrayC[i] == '\0') {
	  i = 100;
	}
	//Single digit number
	else if (isdigit(arrayC[i]) && !isdigit(arrayC[i+1]) && arrayC[i] != '\0') {
	  array[i] = (int)arrayC[i] - 48;
	}
	//Multiple digit number
	else if (isdigit(arrayC[i]) && isdigit(arrayC[i+1])) {
	  //While input[i] isn't a space
	  while (isdigit(arrayC[i])) {
	    count++;
	    i++;
	  }
	  //If input[i] is a space
	  if (!isdigit(arrayC[i])) {
	    for (int j = count; j > 0; j--) {
	      num = input[i-j] - 48;
	      exp = pow(10, j-1);
	      total += num * exp;
	    }
	  }
	  array[i] = total;
	  total = count = 0;
	}
      }
      int * heaparr = new int[100];
      heaparr[0] = 0;
      //Place parsed values into another array with no zeros
      for (int i = 0; i < 100; i++) {
	if (array[i] != 0) {
	  heaparr[j] = array[i];
	  j++;
	  count++;
	}
      }

      /*
      //Construct the max heap
      buildHeap(heaparr, count);
      //Display heap
      displayVisual(heaparr, count);
      printHeap(heaparr, outputarr, count, o, h);
      */
      /*
      //parse
      int j = 0;
      int counter = 0;

      for (int i = 0; i < 500; i++) {
      if ((arrayC[i] != ' ') && ((arrayC[i] - '0') > 0) && ((arrayC[i] - '0') < 1000)) {
      array[j] = (arrayC[i] - '0');
      cout << "testC:" << arrayC[i] << endl;
      cout << "testI:" << array[j] << endl;

      j++;
      i++;
      }
      else if (arrayC[i] == ' '){
      i++;
      counter++;
      }
      }
      cout << counter;*/
    }
  
    /*else if (strcmp(input, "FILE") == 0) {
      char filename[20];
      cout << "Enter file name: ";
      cin.get(filename, 20);
      cin.ignore();

                                 
      ifstream file(filename);
      if (file.is_open) {
      while (getline (file, ))
      }
      }*/
  
    else if (strcmp(input , "QUIT") == 0) {
      return 0;
    }
  }

  return 0;
}
/*
void print(int * array, int depth) {
  if (array != NULL) {
    print(array -> right, depth++)
  }
  for(i < depth) {
    cout << '\t';
  }
  cout << array -> value;
  if (left != NULL) {
    print(array -> left, depth++);
  }
  }*/

void heap(int * array, int len, int i) {
  int max = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < len && array[left] > array[max]) {
    max = left;
  }
  if (right < len && array[right] > array[max]) {
    max = right;
  }
  if (max != i) {
    swap(array[i], array[max]);
    heap(array, len, max);
  }
}
