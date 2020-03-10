#include <iostream>
#include <cstring>
#include <cstdlib>
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

// function prototypes
void remove(int * array, int * output, int o, int n); // remove elements and add to output
void buildheap(int * array, int n); // build max-heap from array
void visualize(int * array, int depth, int n); // horizontally print tree
void heap(int * array, int n, int x); // max heapify

int main() {
  char input[10];
  int array[100] = {};
  int output[100] = {};
  
  int n = 0; // track array pos / size
  int o = 0; // track output array pos
  int depth = 0; // track layer when visualizing tree 
  
  cout << "Type TYPE to input by terminal line" << endl;
  cout << "Type FILE to input by file" << endl;
  cin >> input;
  cin.ignore();

  if (strcmp(input, "TYPE") == 0) { // input through terminal
    array[100] = {}; // clear array
      
    cout << "enter number of inputs: "; // get number of items
    cin >> n;
    while (n > 100) {
      cout << "only up to 100 numbers can be stored: ";
      cin >> n;
    }
    
    for (int i = 0; i < n; i++) { // read in nums and add to int array
      cout << "add number " << i+1 << ": ";
      cin >> array[i];
    }

    // create heap, visualize tree, remove  
    buildheap(array, n);
    cout << endl;
    visualize(array, 0, 0);
    cout << endl;
    remove(array, output, o, n); 
  }
  
  else if (strcmp(input, "FILE") == 0) { // input through file
    char filename[20] = {};
    string line;
    char filedata[400] = {};
    array[100] = {};

    cout << "Enter file name: "; // get file name
    cin >> filename;
    cin.get();
      
    // open file and copy file data into char array
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

    // convert char array of num to int array of num
    for (int i = 0; i < 400; i++) {
      if (filedata[i] == 0) {
	break;
      }
      if (n < 100) { // up to 100 stored numbers
	if (filedata[i] >= 48 && filedata[i] <= 57) { // add to int array if char is a num
	  int num = filedata[i] - '0';

	  while(filedata[i+1] >= 48 && filedata[i+1] <= 57) { // multi digit num
	    int temp = filedata[i+1] - '0';
	    num = (num * 10) + temp;
	    i++;
	  }
	  
	  array[n] = num; // add
	  n++;
	}
      }
    }

    // create heap, visualize tree, remove
    buildheap(array, n);
    cout << endl;
    visualize(array, 0, 0);
    cout << endl;
    remove(array, output, o, n);
  }
  
  else {
    cout << "not a valid command!" << endl;
  }

  return 0;
}

void remove(int * array, int * output, int o, int n) {
  while (array[0] != 0) {
    int z = 0;
    
    for (int i = 0; i < 100; i++) { // get last num
      if (array[z+1] == 0) {
	break;
      }
      z++;
    }
    // swap w first (max) num
    int max = array[0]; 
    array[0] = array[z]; 
    array[z] = 0; // delete max
    output[o] = max; // add max to output
    n = 0;
    o++;

    // if heap is not sorted
    while ((array[(2*n)+1] > array[n] || array[(2*n)+2] > array[n]) && (array[n] != 0)) {
      int left = (2 * n) + 1;
      int right = (2 * n) + 2;
      int temp = 0;
      
      // sort array
      if (array[left] > array[right]) { // if left child is larger 
	temp = array[n];
	array[n] = array[left];
	array[left] = temp;
	n = left;
      }
      else if (array[right] > array[left]) { // if right child is larger
	temp = array[n];
	array[n] = array[right];
	array[right] = temp;
	n = right;
      }	
    }
  }

  // output (largest to smallest) 
  cout << "Output (Max -> Min): ";
  for (int j = 0; j < 100; j++) {
    if (output[j] != 0) {
      cout << output[j] << " ";
      output[j] = 0;
    } 
  }
  cout << endl;
}

void visualize(int * array, int depth, int n) {
  if (array[(2*n)+2] != 0){ //if right child is not null
    visualize(array, depth+1, (2*n)+2);
  }
  for (int i = 0; i < depth; i++){
      //print a 'tab' for every layer of the tree
      cout << '\t';
  }
  cout << array[n] << endl;
  if (array[(2*n)+1] != 0) { // if left child is not null
    visualize(array, depth+1, (2*n)+1);
  }
}

void buildheap(int * array, int n) { // build max heap from array
  for (int j = n / 2 - 1; j >= 0; j--) {
    heap(array, n, j);
  }
  
}

// heap function based on max heap function from
// https://www.geeksforgeeks.org/building-heap-from-array/ 
void heap(int * array, int n, int x) { // max heapify
  int max = x; // initialize largest as root
  int left = (2 * x) + 1;
  int right = (2 * x) + 2;

  if (left < n && array[left] > array[max]) { // if left child is larger than root
    max = left;
  }
  if (right < n && array[right] > array[max]) { // if right child is larger than "largest"
    max = right;
  }
  if (max != x) { // if largest is not root
    swap(array[x], array[max]); 
    heap(array, n, max); // recursively heapify 
  }
}
