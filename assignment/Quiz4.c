#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct header {
  struct node* first;
  struct node* last;
} Header;

int main() {
  Header *head = (Header *) malloc(sizeof(Header));
  Node *firstNode = (Node *) malloc(sizeof(Node));
  Node *secondNode = (Node *) malloc(sizeof(Node));
  firstNode->data = 1;
  firstNode->next = secondNode;
  secondNode->data = 2;
  secondNode->next = NULL;
  head->first = firstNode;
  head->last = secondNode;
  return 0;
}