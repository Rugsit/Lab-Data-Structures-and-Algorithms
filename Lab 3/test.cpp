#include <iostream>
using namespace std;

typedef struct node {
  short number;
  bool target = false;
  bool is_kill = false;
  node *next = NULL;
  node *next_ver = NULL;
} Node;

int main() {
  short hero, survival;
  cin >> hero >> survival;
  Node *prev = NULL, *first = NULL, *fist_person = NULL, *last_person = NULL;
  for (short i = 0; i < 10; i++) {
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    short left, right;
    cin >> left >> right;
    node1->number = right;
    node2->number = i;
    node3->number = left;
    if (i == 0) {
      fist_person = node1;
      node1->next = node2;
      node2->next = node3;
    } else if (first == NULL && i == 1) {
      node1->next_ver = node2;
      node2->next_ver = node3;
      first = node1;
      prev = node1;
      continue;
    } else if (i >= 2) {
      node1->next_ver = node2;
      node2->next_ver = node3;
      prev->next = node1;
      prev = node1;
    }
  }

  last_person = fist_person->next;
  while (last_person->next) {
    last_person = last_person->next;
    last_person->next = last_person->next_ver;
    Node *iter = first;
    while (!last_person->next) {
      if (iter->number == last_person->number) {
        last_person->next = iter->next_ver;
        break;
      }
      iter = iter->next;
      if (!iter) break;
    }
  }
  last_person->next = fist_person->next;

  for (Node *i = fist_person; i; i = i->next) {
    cout << i->number << " ";
  }

}