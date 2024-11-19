#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
  double data;
  string name;
  struct node *next;
}node;

node *addNode(node *, node *); 
int main() {
  string nameMono; double strength; double sum = 0;
  node *head = NULL;
  vector<string> nameMonoVector;
  cout << "Polymer Chain:" << endl;
  while(cin >> nameMono >> strength) {
    nameMonoVector.push_back(nameMono);
    node *newnode = new node();
    newnode -> data = strength;
    newnode -> name = nameMono;
    newnode -> next = NULL;
    sum += strength;
    head = addNode(head, newnode);
  }
  for (node *iter = head; iter; iter = iter->next) {
    cout << iter->name << " (" << iter->data << ") -> ";
  }
  cout << "None" << endl;
  cout << "Total Bond Strength: " << sum << " + x," << endl;
  cout << "when x is total bond strength in each monomers connected bonds" << endl;

  return 0; 
}
node *addNode(node *head, node *newnode) {
  node *prev = head;
  if (head == NULL) {
    head = newnode;
    return head;
  }
  if (head->data > newnode->data) {
    newnode->next = head;
    head = newnode;
    return head;
  }
  for (node *iter = head; iter; iter = iter -> next) {
    if (iter->data > newnode->data) {
      newnode->next = prev->next;
      prev->next = newnode;
      return head;
    }
   prev = iter;
  }
  prev->next = newnode;
  return head;
}