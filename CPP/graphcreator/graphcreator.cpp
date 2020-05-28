#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/* Name: Joyce Chen
 * Graph Creator: A program which can create graphs and search shortest path
 */

struct vertex { // struct for vertex
  char * name;
  vector<vertex*> c; // connect to
  vector<int> weights; 
};

struct p { // struct for next node used in djikstras algorithm
  int length;
  vertex* nextV; 
  vector<vertex*> beenTo;
};

// function prototypes
vertex* getVertex(char* label, vector<vertex*> allV);
int contain(vertex* from, vertex* find);
void print(vector<vertex*> allV);
int djikstra(vector<p*> next, vertex* destination);

int main() {
  vector<vertex*> allV; // vertex of all verticies
  
  while (true) {
    char * input = new char(10);

    cout << "type 'AV' to add vertex" << endl;
    cout << "type 'AE' to add edge" << endl;
    cout << "type 'RV' to remove vertex" << endl;
    cout << "type 'RE' to remove edge" << endl;
    cout << "type 'FSP' to find shortest path" << endl;
    cout << "type 'Q' to quit" << endl;

    cin.getline(input, 10);

    if (strcmp(input, "AV") == 0) { // add vertex
      vertex * temp = new vertex();
      
      cout << "input vertex label: ";
      temp -> name = new char(20);
      cin.getline(temp -> name, 20);
      allV.push_back(temp);
      print(allV);
    }
    else if (strcmp(input, "AE") == 0) { // add edge
      char* first = new char(20);
      char* second = new char(20);
      int weight = 0;
      
      cout << "input first vertex label: ";
      cin.getline(first, 20);
      cout << "input second vertex label: ";
      cin.getline(second, 20);

      vertex* firstV = getVertex(first, allV);
      vertex* secondV = getVertex(second, allV);
      if (firstV == NULL || secondV == NULL) {
	cout << "node(s) not found" << endl;
	continue;
      }
      cout << "input edge weight: ";
      cin >> weight;
      cin.ignore();

      firstV -> c.push_back(secondV);
      firstV -> weights.push_back(weight);
      print(allV);
    }
    else if (strcmp(input, "RV") == 0) { // remove vertex
      char* label = new char(20);
      cout << "input label of vertex you want to remove: ";
      cin.getline(label, 20);
      
      vertex* deleteV = getVertex(label, allV);
      if (deleteV == NULL) {
	cout << "vertex not found" << endl;
	continue;
      }
      for (int a = 0; a < allV.size(); a++) {
	int index = contain(allV[a], deleteV);
	if (index != -1) {
	  allV[a] -> c.erase(allV[a] -> c.begin() + index);
	  allV[a] -> weights.erase(allV[a] -> weights.begin() + index);
	}
      }
      for (int a = 0; a < allV.size(); a++) {
	if (allV[a] == deleteV) {
	  allV.erase(allV.begin() + a);
	  delete deleteV;
	}
      }
      print(allV);
    }
    else if (strcmp(input, "RE") == 0) { // remove edge
      char* first = new char(20);
      char* second = new char(20);
      
      cout << "input first vertex label: ";
      cin.getline(first, 20);
      cout << "input second vertex label: ";
      cin.getline(second, 20);

      vertex* firstV = getVertex(first, allV);
      vertex* secondV = getVertex(second, allV);
      if (firstV == NULL || secondV == NULL) {
	cout << "vertex(es) not found" << endl;
	continue;
      }

      int index = contain(firstV, secondV);
      if (index == -1) {
	cout << "vertices are not connected" << endl;
	continue;
      }

      firstV -> c.erase(firstV -> c.begin() + index);
      firstV -> weights.erase(firstV -> weights.begin() + index);
      print(allV);
    }
    else if (strcmp(input, "FSP") == 0) { // find shortest path
      char* first = new char(20);
      char* second = new char(20);
      
      cout << "input first vertex label: ";
      cin.getline(first, 20);
      cout << "input second vertex label: ";
      cin.getline(second, 20);

      vertex* firstV = getVertex(first, allV);
      vertex* secondV = getVertex(second, allV);
      if (firstV == NULL || secondV == NULL) {
	cout << "error: vertex(es) not found" << endl;
      }

      vector<p*> next;
      for (int a = 0; a < firstV -> c.size(); a++) {
	p* temp = new p();
	temp -> length = firstV -> weights[a];
	temp -> nextV = firstV -> c[a];
	temp -> beenTo.push_back(firstV);
	next.push_back(temp);
      }
      int pathLength = djikstra(next, secondV);
      if (pathLength == -1) {
	cout << "no path exists" << endl;
      }
      else {
	cout << "shortest path length: " << pathLength << endl;
      }
    }
    else if (strcmp(input, "Q") == 0) { // quit
      return 0;
    }
    else {
      cout << "please input a valid command ^^" << endl;
    }
    cout << endl;
  }
  return 0;
}

// returns vertex given label
vertex* getVertex(char* label, vector<vertex*> allV) {
  for (int a = 0; a < allV.size(); a++) {
    if (strcmp(allV[a]->name, label) == 0) {
      return allV[a];
    }
  }
  return NULL;
}

// return index of vertex find if from vertex connects to find
int contain(vertex* from, vertex* find){
  for (int a = 0; a < from -> c.size(); a++) {
    if (from -> c[a] == find) {
      return a;
    }
  }
  return -1;
}

// print out adjacency table
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

// source: https://mycodecamp.blogspot.com/2019/04/program-to-implement-dijkstras.html
// dijkstra's algorithm to find shortest path
int djikstra(vector<p*> next, vertex* destination) {
  if (next.size() == 0) { // no path if nothing in next vertex
    return -1;
  }
  p* smallest = next[0];
  for (int a = 0; a < next.size(); a++) { // find smallest path length
    if (next[a] -> length < smallest -> length) {
      smallest = next[a];
    }
  }
  for (int a = 0; a < next.size(); a++) { // remove priority smallest from vertex
    if (next[a] == smallest) {
      next.erase(next.begin() + a);
      break;
    }
  }

  if (smallest -> nextV == destination) { // return path and length once destination is reached
    cout << "path: ";
    for (int a = 0; a < smallest -> beenTo.size(); a++) {
      cout << smallest -> beenTo[a] -> name << " ";
    }
    cout << destination -> name << endl;
    return smallest -> length;
  }

  for (int a = 0; a < smallest -> nextV -> c.size(); a++) { // add priorities to next v with current
    bool hasBeenTo = false;
    p * temp = new p();
    
    for (int b = 0; b < smallest -> beenTo.size(); b++) {
      if (smallest -> beenTo[b] == smallest -> nextV -> c[a]) {
	hasBeenTo = true;
	break;
      }
    }
    if (hasBeenTo) {
      continue;
    }
    temp -> nextV = smallest -> nextV -> c[a];
    temp -> length = smallest -> length + smallest -> nextV -> weights[a];
    for (int b = 0; b < smallest -> beenTo.size(); b++) {
      temp -> beenTo.push_back(smallest->beenTo[b]);
    }
    temp -> beenTo.push_back(smallest -> nextV);
    next.push_back(temp);
  }
  return djikstra(next, destination);
}
