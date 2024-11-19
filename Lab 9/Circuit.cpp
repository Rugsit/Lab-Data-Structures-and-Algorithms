#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
  string gate;
  int data;
  struct node *leftChild = NULL;
  struct node *rightChild = NULL;
  struct node *parent = NULL;
}Node;

void postorder(Node *currentNode);
int main() {
  int totalBit;
  vector<Node*> tree; 
  cin >> totalBit;
  for (int i = 0; i < totalBit; i++) {
    int eachBit;
    cin >> eachBit;
    Node *newnode = new Node();
    newnode->data = eachBit;
    tree.push_back(newnode);
  }
  string gate;
  while(cin >> gate) {
    Node *newnode = new Node();
    newnode->gate = gate;
    int left, right;
    if (gate == "NOT") {
      cin >> left;
      newnode->leftChild = tree.at(left);
      tree.at(left)->parent = newnode;
    } else {
      cin >> left >> right;
      newnode->leftChild = tree.at(left);
      newnode->rightChild = tree.at(right);
      tree.at(left)->parent = newnode;
      tree.at(right)->parent = newnode;
    }
    tree.push_back(newnode);
  }
  postorder(tree.at(tree.size()-1));
  cout << tree.at(tree.size()-1)->data << endl;
  return 0;
}

void postorder(Node *currentNode) {
  if (currentNode->leftChild != NULL) {
    postorder(currentNode->leftChild);
  }
  if (currentNode->rightChild != NULL) {
    postorder(currentNode->rightChild);
  }
  if (currentNode->gate == "AND") {
    if (currentNode->leftChild->data == 1 && currentNode->rightChild->data == 1) {
      currentNode->data = 1;
    } else {
      currentNode->data = 0;
    }
  } else if (currentNode->gate == "OR") {
    if (currentNode->leftChild->data == 1 || currentNode->rightChild->data == 1) {
      currentNode->data = 1;
    } else {
      currentNode->data = 0;
    }
  } else if (currentNode->gate == "NOT") {
    if (currentNode->leftChild->data == 1) {
      currentNode->data = 0;
    } else {
      currentNode->data = 1;
    }

  }
}