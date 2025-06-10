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

  Display(&linkedList);

  printf("number of items is: %d\n", nodesLenR(linkedList));
}
