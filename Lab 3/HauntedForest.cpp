#include <iostream>
using namespace std;

typedef struct node {
  short number;
  bool target = false;
  bool is_kill = false;
  node *next = NULL;
} Node;

Node *resetLinkList(Node*, short);

int main() {
  short hero, survival;
  cin >> hero >> survival;
  Node *prev = NULL, *first = NULL;
  for (short i = 0; i < hero; i++) {
    Node *node = new Node();
    node->number = i;
    short left, right;
    cin >> left >> right;
    if (i == 0) {
      prev = node;
      first = node;
      continue;
    }
    prev->next = node;
    prev = node;
  }
  prev->next = first;


  Node *iter = first;
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

  for (Node *i = first; i; i = i->next) {
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
        if ()
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