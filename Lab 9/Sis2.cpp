#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
  int data;
  struct node *parent = NULL;
  struct node *leftChild = NULL;
  struct node *rightChild = NULL;
}Node;
void postorder(Node *currentNode);
vector<int> accumulateNum;
int main() {
  vector<Node *> tree(1, NULL);
  int totalNode;
  cin >> totalNode;
  Node *root = new Node();
  root->data = 1;
  tree.push_back(root);
  for (int i = 2; i <= totalNode; i++) {
    Node *newnode = new Node();
    newnode->data = i;
    newnode->parent = tree.at(i/2);
    tree.push_back(newnode);
    if (tree.at(i/2)->leftChild == NULL) {
      tree.at(i/2)->leftChild = newnode;
    } else {
      tree.at(i/2)->rightChild = newnode;
    }
  }
  postorder(tree.at(1));
  int sum = 0;
  for (int i = 0; i < accumulateNum.size(); i++) {
    if (i % 2 == 0) {
      sum += accumulateNum.at(i);
    } else {
      sum -= accumulateNum.at(i);
    }
  }
  cout << sum << endl;
}

void postorder(Node *currentNode) {
  if (currentNode->leftChild != NULL) {
    accumulateNum.push_back(currentNode->data);
    postorder(currentNode->leftChild);
  }
  if (currentNode->rightChild != NULL) {
    accumulateNum.push_back(currentNode->data);
    postorder(currentNode->rightChild);
  }
  accumulateNum.push_back(currentNode->data);
}