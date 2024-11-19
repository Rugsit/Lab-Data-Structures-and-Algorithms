#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct node {
  int number;
  int soldier;
  int treasure;
  int lost;
  int receive;
  struct node *parent = NULL;
  struct node *leftChild = NULL;
  struct node *sibling = NULL;
}Node;

void preorder(Node *root, int allSolider);
vector<vector<int>> storeAllPath;
vector<int> storeEachPath;
int main() {
  int startSoldier, amountTown;
  cin >> startSoldier >> amountTown;
  Node *storeNode[amountTown + 1];
  Node *newnode = new Node();
  newnode->number = 0;
  storeNode[0] = newnode;
  for (int i = 1; i <= amountTown; i++) {
    int solider, treasure, lost, receive;
    cin >> solider >> treasure >> lost >> receive;
    Node *newnode = new Node();
    newnode->number = i;
    newnode->soldier = solider;
    newnode->treasure = treasure;
    newnode->lost = lost;
    newnode->receive = receive;
    storeNode[i] = newnode;
  }
  int a, b;
  while (cin >> a >> b) {
    if (storeNode[b]->leftChild == NULL) storeNode[b]->leftChild = storeNode[a];
    else {
      Node *iter;
      for (iter = storeNode[b]->leftChild; iter->sibling; iter = iter->sibling);
      iter->sibling = storeNode[a];
    }
  }
  preorder(storeNode[0], startSoldier);
  for (vector<int> each : storeAllPath) {
    for (int num : each) {
      cout << num << " "; 
    } 
    cout << endl;  
  }
  cout << endl;
}

void preorder(Node *root, int allSolider, int allTreasure) {
  // cout << root->number << " ";

  Node *leftChild = root->leftChild;
  while (leftChild) {
    double radioLost = allSolider * ((leftChild->lost) / 100.0);
    if ( allSolider - radioLost > leftChild->soldier) {
      double radioAdd = leftChild->soldier * ((leftChild->receive) / 100.0);
      storeEachPath.push_back(leftChild->number);
      preorder(leftChild, allSolider + radioAdd - radioLost, allTreasure + leftChild->treasure);
    } else {
      storeAllPath.push_back(storeEachPath);
      storeEachPath.clear();
      return;
    }
    leftChild = leftChild->sibling;
  }
  if (storeEachPath.size() != 0) storeAllPath.push_back(storeEachPath);
  storeEachPath.clear();
}