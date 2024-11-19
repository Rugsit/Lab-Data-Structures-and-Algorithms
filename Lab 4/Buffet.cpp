#include <iostream>
using namespace std;

typedef struct node {
  string name;
  short hurryNumber;
  struct node *next; 
} Node;

Node *addNode(Node *, Node *);

int main() {
  short amountCustomer, amountTable;
  cin >> amountCustomer >> amountTable;
  Node *head = NULL;
  for (int i = 0; i < amountCustomer; i++) {
    short hurryRate;
    string nameCustomer;
    cin >> hurryRate >> nameCustomer;
    Node *newnode = new Node();
    newnode->hurryNumber = hurryRate;
    newnode->name = nameCustomer;
    newnode->next = NULL;
    if (head == NULL) {
      head = newnode;
      continue;
    }
    head = addNode(head, newnode);
  }

  for (short i = 0; i < amountTable; i++) {
    cout << head->name << endl;
    head = head->next;
    if (head == NULL) break;
  }
}

Node *addNode(Node *head, Node *newnode) {
  Node *prev = head;
  if (head->hurryNumber < newnode->hurryNumber) {
    newnode->next = head;
    head = newnode;
    return head;
  }
  for (Node *i = head; i; i = i->next) {
    if (i->hurryNumber < newnode->hurryNumber) {
     newnode->next = prev->next;
     prev->next = newnode; 
     return head;
    }
    prev = i;
  }
  prev->next = newnode;
  return head;
}