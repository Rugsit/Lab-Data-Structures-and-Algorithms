#include <iostream>
using namespace std;

typedef struct node {
  short number;
  bool target = false;
  bool is_kill = false;
  node *next = NULL;
  node *next_ver = NULL;
} Node;

Node *resetLinkList(Node*, short);

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


  Node *iter = fist_person;
  for (int i = 0; i < survival; i++) {
    short survival_number;
    cin >> survival_number;
    while(iter) {
      if (iter->number == survival_number) {
        iter->target = true;
        break;
      }
      iter = iter->next;
    }
  }
  Node *start = NULL;
  short step_kill;
  cin >> step_kill;

  for (Node *i = fist_person; i; i = i->next) {
    if (i->number == step_kill) {
      start = i;
      break;
    }
  }

  bool have_output_possible = false;
  short count_step = 0;
  short count_kill = 0;
  for (int i = 1; i < 1000; i++) {
    Node *iter = start;
    count_step = 0; count_kill = 0;
    while (hero - count_kill != survival) {
      if (count_step == (i % (hero - count_kill))) {
        if (iter->target) {
          break;
        }
        else if (!iter->is_kill) {
          iter->is_kill = true;
          count_kill++;
          count_step = 0;  
        }
      }
      if (!iter->is_kill) count_step++;
      iter = iter->next;
    }
    if (hero - count_kill == survival && count_kill != 0) {
      have_output_possible = true;
      cout << i << endl;
    }
    start = resetLinkList(start, hero);
  }
  if (!have_output_possible) cout << "NOT POSSIBLE";
}

Node *resetLinkList(Node *list, short hero) {
  short number = 0;
  for (Node *i = list; i; i = i->next) {
    i->is_kill = false;
    if (number == hero - 1) break;
    number++;
  }
  return list;
}