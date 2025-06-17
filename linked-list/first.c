#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

void Display(struct Node **t) {
  while (*t != NULL) {
    printf("%d\n", (*t)->value);
    t = &((*t)->next);
  }
}

int nodesLen(struct Node *t) {
  int count = 0;

  while (t != NULL) {
    count++;
    t = t->next;
  }

  return count;
}

int nodesLenR(struct Node *t) {
  if (t != NULL) {
    return 1 + nodesLenR(t->next);
  }

  return 0;
}

struct Node *RSearch(struct Node *p, int value) {
  if (p == NULL) {
    return NULL;
  }
  if (p->value == value) {
    return p;
  }

  return RSearch(p->next, value);
}

struct Node *searchAnSwitch(struct Node *first, int value) {
  struct Node *q = NULL;
  struct Node *p = first;

  while (p != NULL) {
    if (p->value == value) {
      q->next = p->next;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}

void InsertNode(struct Node *p, int pos, int value) {
  for (int i = 0; i < pos && p; i++)
    p = p->next;

  if (p) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->value = value;
    n->next = p->next;
    p->next = n;
  }
}

void insertLast(struct Node *n, int value) {
  while (n && n->value < value)
    n = n->next;

  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  t->value = value;

  t->next = n->next;
  n->next = t;
}

int main() {
  struct Node *linkedList = (struct Node *)malloc(sizeof(struct Node));

  int value = 0;
  struct Node *prevNode = linkedList;

  for (int i = 0; i < 10; i++) {
    printf("Enter value number %d", i + 1);
    scanf("%d", &value);
    struct Node *current_node = (struct Node *)malloc(sizeof(struct Node));
    current_node->value = value;
    prevNode->next = current_node;
    prevNode = current_node;
  }

  InsertNode(linkedList, 8, 99999);

  Display(&linkedList);

  printf("number of items is: %d\n", nodesLenR(linkedList));
}
