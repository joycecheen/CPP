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
void remove(int * array, int * output, int o, int n);
void buildheap(int * array, int n);
void visualize(int * array, int depth, int n);
void heap(int * array, int n, int x);

int main() {
  char input[10];
  bool run = true;
  
  int array[100] = {};
  int output[100] = {};
  int n = 0;
  int b = 0;
  int o = 0;
  int depth = 0;
  
  while (run == true) { // while user has not quit
    cout << "Type TYPE to input by terminal line" << endl;
    cout << "Type FILE to input by file" << endl;
    cout << "Type QUIT to quit" << endl;

    cin >> input;
    cin.ignore();

    if (strcmp(input, "TYPE") == 0) { // input through terminal
      array[100] = {};
      
      cout << "enter number of inputs: ";
      cin >> n;
      for (int i = 0; i < n; i++) {
	cout << "add number " << i+1 << ": ";
	cin >> array[i];
      }
      buildheap(array, n);

      cout << "maxheap: ";
      for (int i = 0; i < n; i++) {
	cout << array[i] << endl;
      }

      cout << endl;

      visualize(array, 0, 0);
      remove(array, output, o, n);
    }
  
    else if (strcmp(input, "FILE") == 0) {
      char * filename = new char[20];
      string line;
      char filedata[400] = {};
      
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

      cout << "filedata: " << filedata << endl;
      int n = 0; // keep track of array pos

      for (int i = 0; i < 400; i++) {
	if (filedata[i] == '\0') {
	  break;
	}
	if (n < 100) {
	  if (filedata[i] >= 48 && filedata[i] <= 57) {
	    cout << "char " << i << ": "<< filedata[i] << endl;
	    int num = filedata[i] - '0';
	    cout << "int: " << num << endl;

	    while(filedata[i+1] >= 48 && filedata[i+1] <= 57) { // multi digit num
	      cout << "multi";
	      int temp = filedata[i+1] - '0';
	      num = (num * 10) + temp;
	      i++;
	    } 
	    
	    array[n] = num;
	    n++;
	  }
	}
      }

      for (int i = 0; i < n; i++) {
	cout << array[i] << " ";
      }

      buildheap(array, n);

      visualize(array, 0, 0);
      
      cout << endl;
      remove(array, output, o, n);
      cout << endl;
    }
  
    else if (strcmp(input , "QUIT") == 0) {
      run = false;
    }
  }

  return 0;
}

void remove(int * array, int * output, int o, int n) {
  int left = (2 * n) + 1;
  int right = (2 * n) + 2;
  
  while (array[0] != 0) {
    int z = 0;
    
    for (int i = 0; i < 100; i++) { // get last num
      if (array[z+1] == 0) {
	break;
      }
      z++;
    } // swap w first (max) num
    int max = array[0];
    array[0] = array[z];
    array[z] = 0;
    output[o] = max;
    n = 0;
    o++;
    
    while ((array[n] < array[left] || array[n] < array[right]) && (array[n] != 0)) {
      //sort array
      if (array[right] < array[left]) {
	//if the left child is larger, swap
	int temp = array[n];
	array[n] = array[left];
	array[left] = temp;
	n = left;
      }
      else if (array[left] < array[right]) {
	//if the right child is larger, swap
	int temp = array[n];
	array[n] = array[right];
	array[right] = temp;
	n = right;
      }	
    }
  }

  int p = 0;
  while (output[p] != 0){
    cout << output[p] << " ";
    output[p] = 0;
    p++;
  }
  cout << endl;  
}

void visualize(int * array, int depth, int n) {
  /*if (depth == 3) {
    return;
  }
  if (array[(2*n)+1] != 0) {
    visualize(array, depth++, (2*n)+1);
  }
  for (int i = 0; i < depth; i++) {
    cout << '\t';
  }
  cout << array[n] << endl;
  if (array[(2*n)] != 0) {
    visualize(array, depth++, n*2);
  }*/
  //depth+ = COUNT;
  if (array[(2*n)+2] != 0){ //if right child is not null
    visualize(array, depth+1, (2*n)+2);
  }
  for (int i = 0; i < depth; i++){
      //print a 'tab' for every layer of the tree
      cout << '\t';
  }
  cout << array[n] << endl;
  if (array[(2*n)+1] != 0){ // if left child is not null
    visualize(array, depth+1, (2*n)+1);
  }
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
