#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

set<set<int>> storeAllCycle;
vector<int> startCollect;
vector<vector<int>> realStoreAllCycle;
void DFS (int currentNode, vector<vector<int>> &graph, set<int> storeNodeCycle, vector<int> realStoreNodeCycle, vector<bool> &havePass, int parentNode, int startNode);
void foundCircle(set<int> storeNodeCycle, vector<int> realStoreNodeCycle);
int main() {
  vector<int> eachGraph;
  int totalNode, totalEdge;
  cin >> totalNode >> totalEdge;
  vector<vector<int>> graph(totalNode+1, eachGraph);
  vector<bool> havePass(totalNode+1, false);
  int aNode, bNode;
  while (cin >> aNode >> bNode) {
    graph.at(aNode).push_back(bNode);
    graph.at(bNode).push_back(aNode);
  }
  for (int i = 0; i < graph.size(); i++) {
    sort(graph.at(i).begin(), graph.at(i).end());
  }
  
  set<int> storeNodeCycle;
  vector<int> realStoreNodeCycle;
  for (int i = 1; i <= totalNode; i++) {
    DFS(i, graph, storeNodeCycle, realStoreNodeCycle, havePass, i, i);
  }
  if (storeAllCycle.size() == 0) {
    cout << "Is a tree" << endl;
    return 0;
  } else {
    cout << "Is not a tree" << endl;
  }
}

void DFS (int currentNode, vector<vector<int>> &graph, set<int> storeNodeCycle, vector<int> realStoreNodeCycle, vector<bool> &havePass, int parentNode, int startNode) {
  havePass[currentNode] = true;
  storeNodeCycle.insert(currentNode);
  realStoreNodeCycle.push_back(currentNode);

  for (int number : graph.at(currentNode)) {
    if (!havePass.at(number)) {
      DFS(number, graph, storeNodeCycle, realStoreNodeCycle, havePass, currentNode, startNode);
    } else if (havePass.at(number) && number == startNode && number != parentNode) {
      foundCircle(storeNodeCycle, realStoreNodeCycle);
    }
  }
  havePass[currentNode] = false;
}

void foundCircle(set<int> storeNodeCycle, vector<int> realStoreNodeCycle) {
  for (set<int> eachSet : storeAllCycle) {
    if (storeNodeCycle == eachSet) return;
  }
  storeAllCycle.insert(storeNodeCycle);
  cout << "Cycle exists with vertex ";
  for (int number : realStoreNodeCycle) {
    cout << number << " ";
  }
  cout << endl;
}