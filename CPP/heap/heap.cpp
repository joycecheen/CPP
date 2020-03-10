#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

/* Heap: Create a program that creates a heap. You should be able to enter a series of numers OR 
 *       enter a filename, which contains a space-separated list of numbers, then the heap should 
 *       then be able to remove each element in order from the heap, adding them to the output. 
 *       The output will be from largest to smallest, since this is a max heap. Finally, you have a 
 *       visual way to display your tree when it is full. 
 * Name: Joyce Chen
 * Date: 3/1/2020
 */

// i want to die ^.^

void buildheap(int * array, int n);
//void visualize(int * array, int layer, int b);
void heap(int * array, int n, int x);

int main() {
  char input[10];
  bool run = true;

  int array[100];
  int n = 0;

  while (run == true) { // while user has not quit
    cout << "Type TYPE to input by terminal line" << endl;
    cout << "Type FILE to input by file" << endl;
    cout << "Type QUIT to quit" << endl;

    cin >> input;
    cin.ignore();

    if (strcmp(input, "TYPE") == 0) { // input through terminal
      
      cout << "enter number of inputs: ";
      cin >> n;
      for (int i = 0; i < n; i++) {
	cout << "add number " << i+1 << ": ";
	cin >> array[i];
      }
      buildheap(array, n);

      for (int i = 0; i < n; ++i) {
	cout << array[i] << " ";
       }
    }
  
    else if (strcmp(input, "FILE") == 0) {
      char * filename = new char[20];
      string line;
      char * filedata = new char[400];
      
      cout << "Enter file name: ";
      cin >> filename;
      cin.get();


      // copy file data into char array
      ifstream file (filename);
      if (file.is_open()) {
	while (getline (file, line)) {
	  int a = 0;
	  while (line[a] != 0) {
	    filedata[a] = line[a];
	    a++;
	  }
	}
	file.close();
      }
      else {
	cout << "cannot open file" << endl;
      }

      int b = 0;
      for (int i = 0; i < 400; i++) {
	if ((filedata[i] != '\0') && (filedata[i] != ' ')) {
	  int num = filedata[i] - '0';
	  while ((filedata[i+1] != '\0') && (filedata[i+1] != ' ')) {
	    int temp = filedata[i+1] - '0';
	    num = (num * 10) + temp;
	    i++;
	  }
	  array[b] = num;
	  while (b > 1 && array[b] > array[(b/2)]){
	    //swap b and b/2
	    int swap = array[b];
	    array[b] = array[(b/2)];
	    array[(b/2)] = swap;
	    b = (b/2);
          }
	  
	  b++;
	  i++;
	}
	else {
	  i++;
	}
      }
      cout << array;
    }
  
    else if (strcmp(input , "QUIT") == 0) {
      run = false;
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

void buildheap(int * array, int n) {
  for (int j = n / 2 - 1; j >= 0; j--) {
    heap(array, n, j);
  }

  
  /*for (int j = n - 1; j >= 0; j--) {
    swap(array[0], array[j]);
    heap(array, j, 0);
  }*/
  
}

void heap(int * array, int n, int x) {
  int max = x;
  int left = 2 * x + 1;
  int right = 2 * x + 2;

  if (left < n && array[left] > array[max]) {
    max = left;
  }
  if (right < n && array[right] > array[max]) {
    max = right;
  }
  if (max != x) {
    swap(array[x], array[max]);
    heap(array, n, max);
  }
}
