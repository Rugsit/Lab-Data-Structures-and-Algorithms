#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *prev;
  struct node *next;
} Node;

Node *createNode(int data) {
  Node *newnode = (Node *) malloc(sizeof(Node));
  newnode->data = data;
  return newnode;
}

int main() {
  Node *first = createNode(3);
  Node *second = createNode(5);
  first->next = second;
  first->prev = NULL;
  second->next = NULL;
  second->prev = first;
  return 0;
}