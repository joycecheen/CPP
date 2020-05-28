#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/* Name: Joyce Chen
 * Graph Creator: A program which can create graphs and search shortest path
 */

struct vertex {
  char * name;
  vector<vertex*> c;
  vector<int> weights; 
};

struct p {
  int length;
  vertex* nextV;
  vector<vertex*> beenTo;
};

vertex* getVertex(char* label, vector<vertex*> allV);
int contain(vertex* from, vertex* find);
void print(vector<vertex*> allV);
int djikstra(vector<p*> next, vertex* destination);

int main() {
  vector<vertex*> allV;
  
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
      cout << "input vertex label: ";
      vertex * temp = new vertex();
      temp -> name = new char(20);
      cin.getline(temp -> name, 20);
      allV.push_back(temp);
      print(allV);
    }
    else if (strcmp(input, "AE") == 0) {
      cout << "input first vertex label: ";
      char* first = new char(20);
      cin.getline(first, 20);
      cout << "input second vertex label: ";
      char* second = new char(20);
      cin.getline(second, 20);

      vertex* firstV = getVertex(first, allV);
      vertex* secondV = getVertex(second, allV);
      if (firstV == NULL || secondV == NULL) {
	cout << "error: node(s) not found" << endl;
	continue;
      }
      cout << "input edge weight: ";
      int weight = 0;
      cin >> weight;

      firstV -> c.push_back(secondV);
      firstV -> weights.push_back(weight);
      print(allV);
      
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

vertex* getVertex(char* label, vector<vertex*> allV) {
  for (int a = 0; a < allV.size(); a++) {
    if (strcmp(allV[a]->name, label) == 0) {
      return allV[a];
    }
  }
  return NULL;
}

int contain(vertex* from, vertex* find){
  for (int a = 0; a < from -> c.size(); a++) {
    if (from -> c[a] == find) {
      return a;
    }
  }
  return -1;
}

void print(vector<vertex*> allV) {
  cout << "adjacency matrix" << endl;
  cout << "\t";
  for (int a = 0; a < allV.size(); a++) {
    cout << allV[a] -> name << "\t";
  }
  cout << endl;
  for (int a = 0; a < allV.size(); a++) {
    cout << allV[a] -> name << "\t";
    for (int b = 0; b < allV.size(); b++) {

      if (contain(allV[a], allV[b]) != -1) {
	cout << allV[a] -> weights[contain(allV[a], allV[b])] << "\t";
      }
      else {
	cout << "_" << "\t";
      }
    }
    cout << endl;
  }
}
