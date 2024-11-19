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
      target_number = number_data;
      check_status = isEqual(number_data, main_prev_node);
      if (!check_status) {
        Node *newnode = new Node();
        if (bottom == NULL) bottom = newnode;
        newnode->data = number_data;
        newnode->prev = prev;
        prev = newnode;
      } 
    }
    if (check_status) {
      for (Node *iter =  main_prev_node; iter; iter = iter->prev) {   
        if (prev == NULL) break;
        if (iter->data == target_number) {
          bottom->prev = iter->prev;
          iter->prev = prev;
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