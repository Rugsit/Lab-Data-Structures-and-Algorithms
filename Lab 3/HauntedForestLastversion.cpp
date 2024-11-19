#include <iostream>
#include <vector>
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
  vector<Node *> init_node;
  for (short i = 0; i < hero; i++) {
    Node *newnode = new Node();
    newnode->number = i;
    init_node.push_back(newnode);
  }

  for (short i = 0; i < hero; i++) {
    short left, right;
    cin >> left >> right;
    init_node.at(i)->next = init_node.at(left);
  }
  first = init_node.at(0);

  // for (Node *i = first; i; i = i->next) {
  //   cout << i->number << " ";
  // }

  for (short i = 0; i < survival; i++) {
    Node *iter_target = first;
    short survival_number;
    cin >> survival_number;
    while(iter_target) {
      if (iter_target->number == survival_number) {
        iter_target->target = true;
        break;
      }
      iter_target = iter_target->next;
    }
  }

  Node *start = NULL;
  short start_kill;
  cin >> start_kill;
  for (Node *i = first; i; i = i->next) {
    if (i->number == start_kill) {
      start = i;
      break;
    }
  }

  bool have_output_possible = false;
  short count_step = 0;
  short count_kill = 0;
  for (short i = 0; i <= 1000; i++) {
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

Node *resetLinkList(Node *start, short hero) {
  short number = 0;
  for (Node *i = start; i; i = i->next) {
    i->is_kill = false;
    if (number == hero - 1) break;
    number++;
  }
  return start;
}