#include <iostream>
using namespace std;

typedef struct node {
  int data;
  node *next;
} Node;

bool checkInLinkList(Node *, int);

int main() {
  int number;
  Node *head = NULL, *prev = NULL;
  while (true) {
    cin >> number;
    if (number == 0) break;
    if (checkInLinkList(head, number)) continue;
    Node *newnode = new Node();
    newnode->data = number;
    newnode->next = NULL;
    if (head == NULL) {
      head = newnode;
      prev = newnode;
      continue;
    }
    prev->next = newnode;
    prev = newnode;
  }

  for (Node *i = head; i; i = i->next) {
    cout << i->data << " ";
  }
}

bool checkInLinkList(Node *head, int number) {
  bool check = false;
  for (Node *i = head; i; i = i->next) {
    if (i->data == number) return true; 
  }
  return false;
}