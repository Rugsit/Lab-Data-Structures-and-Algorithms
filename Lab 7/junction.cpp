#include <iostream>
#include <vector>
using namespace std;

void printEdge(vector<int>);
int main() {
  int totalVertex, totalEdge;
  cin >> totalVertex >> totalEdge;
  vector<int> eachLineVertex;
  vector<vector<int>> storeVertex(totalVertex, eachLineVertex);
  for (int i = 0; i < totalEdge; i++) {
    int vertexA, vertexB;
    cin >> vertexA >> vertexB;
    storeVertex.at(vertexA - 1).push_back(i + 1);
    storeVertex.at(vertexB - 1).push_back(i + 1);
  }
  for (int i = 0; i < totalVertex; i++) {
    if (storeVertex.at(i).size() == 0) cout << "v" << i+1 << ": Isolated";
    else if (storeVertex.at(i).size() == 1) {
      cout << "v" << i+1 << ": Impasse coming from ";
      printEdge(storeVertex.at(i));
    } else if (storeVertex.at(i).size() == 2) {
      cout << "v" << i+1 << ": Corner connecting ";
      printEdge(storeVertex.at(i));
    } else if (storeVertex.at(i).size() >= 3) {
      cout << "v" << i+1 << ": Junction of ";
      printEdge(storeVertex.at(i));
    }
    cout << endl;
  }
}

void printEdge(vector<int> storeEdge) {
  for (int i = 0; i < storeEdge.size(); i++) {
    cout << "e" << storeEdge.at(i) << " ";
  }
}