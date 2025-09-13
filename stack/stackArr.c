#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int *values;
  int top;
  int size;
};

void create(struct Stack *st) {
  printf("enter the size of the stack: ");
  scanf("%d", &st->size);

  st->top = -1;
  st->values = (int *)malloc(sizeof(int) * st->size);
}

void push(struct Stack *st, int value) {
  if (st->top == st->size - 1) {
    printf("Stack Overflow\n");
    return;
  }

  st->values[++st->top] = value;
}

int pop(struct Stack *st) {
  int deleted = -1;

  if (st->top == -1) {
    printf("stack is  empty\n");
  } else {
    deleted = st->values[st->top--];
  }

  return deleted;
}

void display(struct Stack st) {
  for (int i = 0; i <= st.top; i++) {
    printf("%d", st.values[i]);
    if (i < st.top)
      printf(", ");
    else
      printf(".\n");
  }
}

/* int main() { */
/*   struct Stack *st; */
/**/
/*   create(st); */
/**/
/*   push(st, 1); */
/*   push(st, 2); */
/*   push(st, 3); */
/*   push(st, 4); */
/*   push(st, 5); */
/**/
/*   printf("deleted value: %d\n", pop(st)); */
/**/
/*   display(*st); */
/**/
/*   return 0; */
/* } */
