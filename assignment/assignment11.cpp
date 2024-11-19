// 6610402205 นายรักษิต รุ่งรัตนไชย
#include <iostream>
using namespace std;

typedef struct node {
  string filename;
  struct node *parent = NULL;
  struct node *leftChild = NULL;
  struct node *sibling = NULL;
  int size = 0;
}Node;

Node *createNode(string currentNode, Node *parentNode, int size);
void preorderFindSize(Node *rootNode);
void postorder(Node *rootNode);
void preorder(Node *rootNode);
int main() {
  Node *node1 = createNode("/user/rt/courses", NULL, 1000);
  Node *node2 = createNode("cs016/", node1, 2000);
  Node *node3 = createNode("cs252/", node1, 1000);
  Node *node4 = createNode("grades", node3, 3000);
  Node *node5 = createNode("grades", node2, 8000);
  Node *node6 = createNode("homeworks/", node2, 1000);
  Node *node7 = createNode("programs/", node2, 1000);
  Node *node8 = createNode("projects/", node3, 1000);
  Node *node9 = createNode("hw1", node6, 3000);
  Node *node10 = createNode("hw2", node6, 2000);
  Node *node11 = createNode("hw3", node6, 4000);
  Node *node12 = createNode("pr1", node7, 57000);
  Node *node13 = createNode("pr2", node7, 97000);
  Node *node14 = createNode("pr3", node7, 74000);
  Node *node15 = createNode("papers/", node8, 1000);
  Node *node16 = createNode("demos/", node8, 1000);
  Node *node17 = createNode("buylow", node15, 26000);
  Node *node18 = createNode("sellhigh", node15, 55000);
  Node *node19 = createNode("market", node16, 4786000);
  preorderFindSize(node1);
  cout << "Preorder: " << endl;
  preorder(node1);
  cout << endl;
  cout << "--------------------" << endl;
  cout << "Postorder: " << endl;
  postorder(node1);
  return 0;
}

Node *createNode(string currentNode, Node *parentNode, int size) {
  Node *newnode = new Node();
  newnode->filename = currentNode;
  newnode->size = size;
  if (parentNode == NULL) return newnode;
  newnode->parent = parentNode;
  if (parentNode->leftChild == NULL) {
    parentNode->leftChild = newnode;
  } else {
    Node *iter;
    for (iter = parentNode->leftChild; iter->sibling ; iter = iter->sibling);
    iter->sibling = newnode;
  } 
  return newnode;
}

void preorderFindSize(Node *rootNode) {
  Node *leftChild = rootNode->leftChild;
  while(leftChild) {
    preorderFindSize(leftChild);
    leftChild = leftChild->sibling;
  }
  if (rootNode->parent != NULL) rootNode->parent->size += rootNode->size;
}

void preorder(Node *rootNode) {
  cout << rootNode->filename << ": " << rootNode->size << endl;

  Node *leftChild = rootNode->leftChild;
  while(leftChild) {
    preorder(leftChild);
    leftChild = leftChild->sibling;
  }
}

void postorder(Node *rootNode) {
  Node *leftChild = rootNode->leftChild;
  while(leftChild) {
    postorder(leftChild);
    leftChild = leftChild->sibling;
  }

  cout << rootNode->filename << ": " << rootNode->size << endl;
}