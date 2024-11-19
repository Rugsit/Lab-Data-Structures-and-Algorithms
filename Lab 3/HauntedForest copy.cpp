#include <iostream>
using namespace std;

typedef struct node {
  short number;
  bool target = false;
  node *next = NULL;
} Node;

typedef struct nodeStore {
  node* first;
  node* last;
} NodeStore;

nodeStore *restoreLinkList(Node*, Node*, short, short);

int main() {
  short hero, survival;
  cin >> hero >> survival;
  Node *prev = NULL, *first = NULL, *last = NULL, *prev_start = NULL;
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
  last = prev;
  last->next = first;

  for (int i = 0; i < survival; i++) {
    Node *iter = first;
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

  for (Node *i = head; i; i = i->next) {
    if (i->number == step_kill) {
      start = i;
      break;
    }
    prev_start = i;
  }

  short count_step = 0;
  short count_kill = 0;
  for (int i = 4; i < 5; i++) {
    Node *iter = start;
    count_kill = 0;
    while (hero - count_kill != survival) {
      if (count_step == i) {
        if (iter->target) {
          break;
        } else {
          if (iter == bottom) bottom = prev_start;
          Node *temp = iter;
          prev_start->next = iter->next;
          iter = iter->next;
          delete(temp);
          count_kill++;
          count_step = 0;
        } 
      } else {
        prev_start = iter;
        iter = iter->next; 
        count_step++;
        }
    }
    if (hero - count_kill == survival) cout << i << endl;
  } 

}

NodeStore *restoreLinkList(Node *list,Node *last_node, short hero, short step_kill) {
  
}