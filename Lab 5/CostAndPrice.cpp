#include <iostream>
#include <vector>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

typedef struct node {
  int data;
  struct node *next;
} Node;

int main() {
  string line;
  vector<int> beforeSort; vector<int> afterSort; vector<Node*> hashTable;
  vector<int> countLength;
  getline(cin, line);
  stringstream s(line); string eachNumStr; 
  while (s >> eachNumStr) {
    beforeSort.push_back(stod(eachNumStr));
  }
  afterSort = beforeSort;
  sort(afterSort.begin(), afterSort.end());
  int key = afterSort.at(((afterSort.size() + 1) / 2) - 1);
  for (int i = 0; i < key; i++) {
    Node *newnode = NULL;
    hashTable.push_back(newnode);
    countLength.push_back(0);
  }
  for (int i = 0; i < beforeSort.size(); i++) {
    Node *newnode = new Node();
    newnode->data = beforeSort.at(i);
    newnode->next = NULL;
    if (hashTable.at(beforeSort.at(i) % key) == NULL) hashTable.at(beforeSort.at(i) % key) = newnode;
    else {
      newnode->next = hashTable.at(beforeSort.at(i) % key);
      hashTable.at(beforeSort.at(i) % key) = newnode;
    }
    countLength.at(beforeSort.at(i) % key) += 1;
    
  }
  int max = -1;
  for (int num : countLength) if (num >= max) max = num;
  for (int i = 0; i < countLength.size(); i++) {
    if (countLength.at(i) == max) {
      for (Node *iter = hashTable.at(i); iter; iter = iter->next) {
        cout << iter->data << " ";
      }
      cout << endl;
    }
  }
  return 0;
}