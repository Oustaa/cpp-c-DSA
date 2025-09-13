#include <stdio.h>
#include <stdlib.h>

struct Node {
  char value;
  struct Node *next;
};

struct Stack {
  struct Node *top;
};

void push(struct Stack *st, char value) {
  struct Node *temp = malloc(sizeof(struct Node));

  if (temp) {
    temp->value = value;
    temp->next = st->top;
    st->top = temp;
  }
}

char pop(struct Stack *st) {
  char deleted = '\0';

  if (st->top == NULL) {
    printf("Stack is empty\n");
  } else {
    deleted = st->top->value;
    st->top = st->top->next;
    // free(st->top);
  }

  return deleted;
}

char peak(struct Stack st) {
  if (st.top == NULL){
    return '\0';
  } 
  return st.top->value;
}

void display(struct Stack st) {
  struct Node *temp = st.top;
  while (temp) {
    printf("%c\n", temp->value);
    temp = temp->next;
  }
}

/* int main() { */
/* struct Stack *st = malloc(sizeof(struct Stack)); */
/*   struct Stack st = {.top = NULL}; */
/**/
/*   push(&st, 1); */
/*   push(&st, 2); */
/*   push(&st, 3); */
/**/
/*   printf("deleted value: %d\n", pop(&st)); */
/**/
/*   display(st); */
/**/
/*   return 0; */
/* } */
