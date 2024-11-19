#include <iostream>
using namespace std;

typedef struct node{
  short data;
  node *prev;
} Node;

bool isEqual(short, Node*);

int main() {
  bool check_status = false;
  short number;
  cin >> number;
  short number_data, target_number = -1;
  Node *main_bottom = NULL;
  Node *main_prev_node = NULL;


  while (true) {
    cin >> number_data;
    if (number_data == 0) break;
    Node *main_newnode = new Node();
    if (main_bottom == NULL) main_bottom = main_newnode;
    main_newnode->data = number_data;
    main_newnode->prev = main_prev_node;
    main_prev_node = main_newnode; 
  }

  for (int i = 0; i < number - 1; i++) {
    Node *bottom = NULL;
    Node *prev = NULL;
    while (true) {
      cin >> number_data;
      if (number_data == 0) break;
      Node *newnode = new Node();
      if (bottom == NULL) bottom = newnode;
      newnode->data = number_data;
      newnode->prev = prev;
      prev = newnode;
    }
    if (prev != NULL && isEqual(prev->data, main_prev_node)) {
      Node *target_node = NULL;
      for (Node *iter =  main_prev_node; iter; iter = iter->prev) {   
        if (iter->data == prev->data) {
          target_node = iter;
          prev = prev->prev;
          break;
        } 
      }
      Node *i = prev; 
      while (i && prev != NULL) { 
        if (!isEqual(i->data, main_prev_node)) {
          Node *temp = i->prev;
          i->prev = target_node->prev;
          target_node->prev = i;
          target_node = i;
          i = temp;
        }else {
          i = i->prev;
        }
      }
    }
  }

  for (Node *i = main_prev_node; i; i = i->prev ) {
    cout << i->data << " "; 
  } 
}

bool isEqual(short number, Node *head) {
  for (Node *iter = head; iter; iter = iter->prev) {
    if (iter->data == number) return true; 
  }
  return false;
}