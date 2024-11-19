#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> havePass(20, false);
vector<int> eachGraph;
vector<vector<int>> graph(20, eachGraph);
void addEdge(int a, int b); 
void BFS(int S, int F);
int main() {
  addEdge(0,1);
  addEdge(0,2);
  addEdge(1,2);
  addEdge(2,7);
  addEdge(2, 3);
  addEdge(3, 6);
  addEdge(3, 5);
  addEdge(3, 4);
  addEdge(7, 8);
  addEdge(8, 10);
  addEdge(8, 9);
  addEdge(10, 12);
  addEdge(10, 11);
  addEdge(10,13);
  addEdge(13, 14);
  addEdge(13, 15);
  addEdge(15, 16);
  addEdge(15, 17);
  addEdge(15, 18);
  addEdge(15, 19);

  BFS(0, 19);
  return 0;
}


void addEdge(int a, int b) {
  graph.at(a).push_back(b);
  graph.at(b).push_back(a);
}

void BFS(int S, int F) {
  queue<int> storeNode;
  storeNode.push(S);

  while (!storeNode.empty()) {
    int currentNode = storeNode.front();
    havePass.at(currentNode) = true;
    storeNode.pop();
    for (int i = 0; i < graph.at(currentNode).size(); i++) {
      if (graph.at(currentNode).at(i) == F) {
        cout << "YES" << endl;
        return;
      }
      if(!havePass.at(graph.at(currentNode).at(i))) storeNode.push(graph.at(currentNode).at(i));
    }
  }
  cout << "NO" << endl;
  return;
}