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
    cout << "type 'Q' to quit" << endl;

    cin.getline(input, 10);

    if (strcmp(input, "AV") == 0) {
      vertex * temp = new vertex();
      
      cout << "input vertex label: ";
      temp -> name = new char(20);
      cin.getline(temp -> name, 20);
      allV.push_back(temp);
      print(allV);
    }
    else if (strcmp(input, "AE") == 0) {
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
    else if (strcmp(input, "RV") == 0) {
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
    else if (strcmp(input, "RE") == 0) {
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
    else if (strcmp(input, "FSP") == 0) {
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
    else if (strcmp(input, "Q") == 0) {
      return 0;
    }
    else {
      cout << "please input a valid command ^^" << endl;
    }
    cout << endl;
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

int djikstra(vector<p*> next, vertex* destination) {
  if (next.size() == 0) {
    return -1;
  }
  // find smallest path length
  p* smallest = next[0];
  for (int a = 0; a < next.size(); a++) {
    if (next[a] -> length < smallest -> length) {
      smallest = next[a];
    }
  }
  //removes priorty smallest from vertex
  for (int a = 0; a < next.size(); a++) {
    if (next[a] == smallest) {
      next.erase(next.begin() + a);
      break;
    }
  }

  //if you reached the destination, return path length
  if (smallest -> nextV == destination) {
    cout << "path: ";
    for (int a = 0; a < smallest -> beenTo.size(); a++) {
      cout << smallest -> beenTo[a] -> name << " ";
    }
    cout << destination -> name << endl;
    return smallest -> length;
  }

  //using current node, add priorities to next vertex
  for (int a = 0; a < smallest -> nextV -> c.size(); a++) {
    bool hasBeenTo = false;
    for (int b = 0; b < smallest -> beenTo.size(); b++) {
      if (smallest -> beenTo[b] == smallest -> nextV -> c[a]) {
	hasBeenTo = true;
	break;
      }
    }
    if (hasBeenTo) {
      continue;
    }
    p * temp = new p();
    temp-> nextV = smallest -> nextV -> c[a];
    temp -> length = smallest -> length + smallest -> nextV -> weights[a];
    for (int b = 0; b < smallest -> beenTo.size(); b++) {
      temp -> beenTo.push_back(smallest->beenTo[b]);
    }
    temp -> beenTo.push_back(smallest -> nextV);
    next.push_back(temp);
  }
  return djikstra(next, destination);
}
