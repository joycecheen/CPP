#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void heap(int * array, int len, int i);

int main() {
  char input[10];
  int num = 0;
  int * array = new int[100];
  char * arrayC = new char[500];
  
  cout << "Type TYPE to input by terminal line" << endl;
  cout << "Type FILE to input by file" << endl;
  cout << "Type QUIT to quit" << endl;

  cin >> input;
  cin.ignore();

  if (strcmp(input, "TYPE") == 0) {
    cout << "Enter number of elements of array: ";
    cin >> num;
    cout << "Enter each number followed with a space: ";
    cin.getline(arrayC, 500);

    cout << arrayC << endl;
    
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

  return 0;
}

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
