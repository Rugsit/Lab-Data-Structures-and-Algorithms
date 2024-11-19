#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef struct node {
  int numberNode;
  struct node *parent = NULL;
  struct node *leftChild = NULL;
  struct node *sibling = NULL;
}Node;
void BFS (unordered_map<int, Node *> &tree, int currentNode, int totalNode, unordered_map<int, bool> &havePass);
vector<vector<int>> groupOutput;
int main() {
  unordered_map<int, bool> havePass;
  unordered_map<int, Node *> tree;
  int totalNode, parentNode, childNode, firstTouch;
  int numberRootNode;
  cin >> totalNode;
  cin >> numberRootNode;
  Node *rootNode = new Node();
  rootNode->numberNode = numberRootNode;
  tree[numberRootNode] = rootNode;
  havePass[numberRootNode] = false;
  for(int i = 0; i < totalNode - 1; i++) {
    cin >> parentNode >> childNode;
    node *newnode = new node();
    newnode->numberNode = childNode;
    newnode->parent = tree[parentNode];
    tree[childNode] = newnode;
    havePass[childNode] = false;
      // cout <<  parentNode << " " << tree[parentNode]->leftChild << endl;
    if (!tree[parentNode]->leftChild) {
      tree[parentNode]->leftChild = newnode;
    } else {
      Node *iter = tree[parentNode]->leftChild;
      for (iter;iter->sibling; iter = iter->sibling);
      iter->sibling = newnode;
    }
  }
  cin >> firstTouch;
  cout << firstTouch << endl;
  BFS(tree, firstTouch, totalNode, havePass);
  for (int i = 0; i < groupOutput.size(); i++) {
    // sort(groupOutput.at(i).begin(), groupOutput.at(i).end());
    for (int j = 0; j < groupOutput.at(i).size(); j++) {
      cout << groupOutput[i][j] << " ";
    }
    cout << endl;
  }

}

void BFS (unordered_map<int, Node *> &tree, int currentNode, int totalNode, unordered_map<int, bool> &havePass) {
  queue<int> storeNode;
  storeNode.push(currentNode);
  while(!storeNode.empty()) {
    vector<int> output;
    int size = storeNode.size();
    for (int i = 0; i < size; i++) {
      int targetNode = storeNode.front();
      havePass[targetNode] = true; 
      storeNode.pop();
      Node *child = tree[targetNode]->leftChild;
      if (tree[targetNode]->parent && !havePass[tree[targetNode]->parent->numberNode]) {
        output.push_back(tree[targetNode]->parent->numberNode);
        storeNode.push(tree[targetNode]->parent->numberNode);
      }
      while(child) {
        if (!havePass[child->numberNode]) {
          output.push_back(child->numberNode);
          storeNode.push(child->numberNode);
        }
        child = child->sibling;
      }
    }
  groupOutput.push_back(output);
  }
}
