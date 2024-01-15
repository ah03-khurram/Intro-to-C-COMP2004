/*
  Created & Modefied by "Khurram Ahmed..."
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

typedef struct node {
  int value;
  struct node *next;
  struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;

void printNode(node *n) { printf("\tValue: %d\n", n->value); }

void printLinkedList(node *n) {
  printf("Printing Linked-list\n");
  while (n != NULL) {
    printNode(n);
    n = n->next;
  }
}

static node *init_node(node *n, int x) {
  n->value = x;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

static void insert(int x) {
  node *num = (node *)malloc(sizeof(node));
  num = init_node(num, x);

  if (size == 0) {
    head = num;
    tail = num;
  } else {
    node *temp = tail;
    temp->next = num;
    tail = num;
    tail->prev = temp;
  }
  size++;
}

void delete (node *n) {

  if (n == tail) {
    n->prev->next = n->next;
    tail = n->prev;
  } else if (n == head) {
    n->next->prev = n->prev;
    head = n->next;
  } else {
    n->prev->next = n->next;
    n->next->prev = n->prev;
  }
  size--;
}

int main() {

  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50);
  printLinkedList(head);
  printf("The size of the Linked-list is: %d\n", size);

  delete (tail);

  printLinkedList(head);
  printf("The size of the Linked-list is: %d\n", size);
}