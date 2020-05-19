#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct edge {
  char * name;
  vector<edge*> c;
  vector<int> weights; 
};

int main() {
  while (true) {
    char * input = new char(10);

    cout << "type 'AV' to add vertex" << endl;
    cout << "type 'AE' to add edge" << endl;
    cout << "type 'RV' to remove vertex" << endl;
    cout << "type 'RE' to remove edge" << endl;
    cout << "type 'FSP' to find shortest path" << endl;
    cout << "type 'Q' to quit" << endl << endl;

    cin.getline(input, 10);

    if (strcmp(input, "AV") == 0) {

    }
    else if (strcmp(input, "AE") == 0) {

    }
    else if (strcmp(input, "RV") == 0) {

    }
    else if (strcmp(input, "RE") == 0) {

    }
    else if (strcmp(input, "FSP") == 0) {

    }
    else if (strcmp(input, "Q") == 0) {
      return 0;
    }
    else {
      cout << "please input a valid command ^^" << endl;
    }
  }
  return 0;
}
