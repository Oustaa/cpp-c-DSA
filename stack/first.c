#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int size;
  int top;
  int *values;
};

void create(struct Stack *st) {
  printf("How many elements in the stack: ");
  scanf("%d", &st->size);
  st->values = (int *)malloc(sizeof(int) * st->size);
  st->top = -1;
}

void push(struct Stack *st, int value) {
  if (st->size - 1 == st->top) {
    printf("Stack Overflow\n");
  } else {
    st->values[++st->top] = value;
  }
}

int pop(struct Stack *st) {
  int deleted = -1;
  if (st->top == -1) {
    printf("Stack Underflow\n");
  } else {
    deleted = st->values[st->top--];
  }

  return deleted;
}

int main() {
  struct Stack *st;
  create(st);

  push(st, 1);
  push(st, 2);
  push(st, 3);
  push(st, 4);
}
