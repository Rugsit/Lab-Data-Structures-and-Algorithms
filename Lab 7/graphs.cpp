#include <iostream>
#include <string>
#include <vector>
using namespace std;
void createMatrixGraph(vector<vector<int>> &, int);
void printMatrixGraph(vector<vector<int>>, vector<int>);
void printListGraph(vector<vector<int>>, vector<int>);
void createListVertex(vector<int>&, int);
void createEdgeMatrix(vector<vector<int>>);
void findInOutDegreeListGraphAndPrint(vector<vector<int>>, vector<int>);
void findInOutDegreeMatrixGraphAndPrint(vector<vector<int>>, vector<int>);
int findIndexOfVertex(vector<int> , int );

int main() {
  int startSizeGraph; char command; int vertexA, vertexB, index;
  string typeOfGraph;
  vector<int> listVertex; 
  cin >> typeOfGraph >> startSizeGraph;
  createListVertex(listVertex, startSizeGraph);
  if (typeOfGraph == "List") {
    vector<int> eachListGraph;
    vector<vector<int>> listGraph(startSizeGraph, eachListGraph);
    while(true) {
      int j;
      vector<int> newEachlist;
      cin >> command;
      if (command == 'q') {
        findInOutDegreeListGraphAndPrint(listGraph, listVertex);
        break;
      }
      switch (command) {
        case 'e':
          cin >> vertexA >> vertexB;
          listGraph[findIndexOfVertex(listVertex, vertexA)].push_back(vertexB);
          break;
        case 'r':
          cin >> vertexA >> vertexB;
          for (int i = 0; i < listGraph.at(vertexA).size(); i++) {
            if (listGraph[findIndexOfVertex(listVertex, vertexA)][i] == vertexB) {
              index = i; break;
            }
          }
          listGraph.at(findIndexOfVertex(listVertex, vertexA)).erase(listGraph.at(findIndexOfVertex(listVertex, vertexA)).begin() + index);
          break;
        case 'v':
          listGraph.push_back(newEachlist);
          listVertex.push_back(listVertex.at(listVertex.size() - 1) + 1);
          break;
        case 'u':
          j = 0;
          cin >> vertexA;
          for (int i = 0; i < listVertex.size(); i++) {
            if (listVertex.at(i) == vertexA) {
              index = i; break;
            }
          }
          listVertex.erase(listVertex.begin() + index);
          listGraph.erase(listGraph.begin() + index);
          for (int i = 0; i < listGraph.size(); i++) {
            while (true) {
              if (j >= listGraph.at(i).size()) {
                break;
              }
              if (listGraph[i][j] == vertexA) {
                listGraph.at(i).erase(listGraph.at(i).begin() + j);
              } else {
                j++;
              }
            }
          }
          break;
        case 'p':
          printListGraph(listGraph, listVertex);
          break;
      }
    }
  } else if (typeOfGraph == "Matrix") {
    vector<vector<int>> matrixGraph; 
    createMatrixGraph(matrixGraph, startSizeGraph);
    while(true) {
      vector<int> newEachlist;
      cin >> command;
      if (command == 'q') {
        findInOutDegreeMatrixGraphAndPrint(matrixGraph, listVertex);
        break;
      }
      switch (command) {
        case 'e':
          cin >> vertexA >> vertexB;
          vertexA = findIndexOfVertex(listVertex, vertexA);
          vertexB = findIndexOfVertex(listVertex, vertexB);
          matrixGraph[vertexA][vertexB] = 1;
          break;
        case 'r':
          cin >> vertexA >> vertexB;
          vertexA = findIndexOfVertex(listVertex, vertexA);
          vertexB = findIndexOfVertex(listVertex, vertexB);
          matrixGraph[vertexA][vertexB] = 0;
          break;
        case 'v':
          matrixGraph.push_back(newEachlist);
          listVertex.push_back(listVertex.at(listVertex.size() - 1) + 1);
          for (int i = 0; i < listVertex.size(); i++) {
            while (matrixGraph.at(i).size() != listVertex.size()) {
              matrixGraph.at(i).push_back(0);
            }
          }
          break;
        case 'u':
          cin >> vertexA;
          for (int i = 0; i < listVertex.size(); i++) {
            if (listVertex.at(i) == vertexA) {
              index = i; break;
            }
          }
          listVertex.erase(listVertex.begin() + index);
          matrixGraph.erase(matrixGraph.begin() + index);
          for (int i = 0; i < matrixGraph.size(); i++) {
            matrixGraph.at(i).erase(matrixGraph.at(i).begin() + index);
          }
          break;
        case 'p':
          printMatrixGraph(matrixGraph, listVertex);
          break;
      }
    }
  }


}
void createListVertex(vector<int> &listVertex, int size) {
  for (int i = 0; i < size; i++) {
    listVertex.push_back(i);
  }
}

void createMatrixGraph(vector<vector<int>> &matrixGraph, int size) {
  for (int i = 0; i < size; i++) {
    vector<int> eachMatrixGraph; 
    matrixGraph.push_back(eachMatrixGraph);
    for (int j = 0; j < size; j++) {
      matrixGraph.at(i).push_back(0);
    }
  }
}

void printMatrixGraph(vector<vector<int>> matrixGraph, vector<int> listVertex) {
  cout << "  ";
  for (int i = 0; i < matrixGraph.size(); i++) {
    cout << listVertex.at(i) << " "; 
  }
  cout << endl;
  for (int i = 0; i < matrixGraph.size(); i++) {
    cout << listVertex.at(i) << " ";
    for (int j = 0; j < matrixGraph.size(); j++) {
      cout << matrixGraph[i][j] << " ";
    }
    cout << endl;
  }
  cout << "====================" << endl;
}

void printListGraph(vector<vector<int>> listGraph, vector<int> listVertex) {
  for (int i = 0; i < listGraph.size(); i++) {
    cout << "[" << listVertex.at(i) << "]" << " -> ";
    for (int j = 0; j < listGraph.at(i).size(); j++) {
      cout << listGraph[i][j] << " -> ";
    }
    cout << "NULL" << endl;
  }
  cout << "====================" << endl;
}

void findInOutDegreeListGraphAndPrint(vector<vector<int>> listGraph, vector<int> listVertex) {
  vector<int> storeAllIndegree(listVertex.size(), 0);
  for (int i = 0; i < listGraph.size(); i++) {
    for (int j = 0; j < listGraph.at(i).size(); j++) {
      for (int k = 0; k < listVertex.size(); k++) {
        if (listVertex.at(k) == listGraph[i][j]) storeAllIndegree[k]++;
      }
    }
  }
  int max = -1;
  int index = 0;
  for (int i = 0; i < storeAllIndegree.size(); i++) {
    if (storeAllIndegree.at(i) > max) {
      max = storeAllIndegree.at(i); 
      index = i;
    }
  }
  cout << "Maximum In-Degree : Vertex " << listVertex.at(index) << " " << max << endl; 
  max = -1;
  index = 0;
  for (int i = 0; i < listGraph.size(); i++) {
    if ((int)listGraph.at(i).size() > max) {
      max = (int)listGraph.at(i).size();
      index = i;
    }
  }
  cout << "Maximum Out-Degree : Vertex " << listVertex.at(index) << " " << max << endl; 
}

void findInOutDegreeMatrixGraphAndPrint(vector<vector<int>> matrixGraph, vector<int> listVertex) {
  vector<int> inDegree(listVertex.size(), 0);
  for (int i = 0; i < matrixGraph.size(); i++) {
    for (int j = 0; j < matrixGraph.size(); j++) {
      if (matrixGraph[j][i] == 1) {
        inDegree.at(i)++;
      }
    }
  }
  int max = -1;
  int index;
  for (int i = 0; i < inDegree.size(); i++) {
    if (inDegree.at(i) > max) {
      max = inDegree.at(i);
      index = i;
    }
  }
  cout << "Maximum In-Degree : Vertex " << listVertex.at(index) << " " << max << endl;

  vector<int> outDegree(listVertex.size(), 0);
  for (int i = 0; i < matrixGraph.size(); i++) {
    for (int j = 0; j < matrixGraph.size(); j++) {
      if (matrixGraph[i][j] == 1) {
        outDegree.at(i)++;
      }
    }
  }
  max = -1;
  for (int i = 0; i < outDegree.size(); i++) {
    if (outDegree.at(i) > max) {
      max = outDegree.at(i);
      index = i;
    }
  }
  cout << "Maximum Out-Degree : Vertex "<< listVertex.at(index) << " " << max << endl;
}

int findIndexOfVertex(vector<int> listVertex, int vertex) {
  for (int i = 0; i < listVertex.size(); i++) {
    if (listVertex.at(i) == vertex) return i;
  }
  return 0;
}