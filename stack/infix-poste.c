#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./stackll.h"

int isOperator(char c) {
  if(c == '+' || c == '-' || c == '/' || c == '*')
    return 1;
  return 0;
}

int getPre(char c){
  if (c == '-' || c == '+') return 1;
  return 2;
}

char* convert(char* expresion){
  char *converted = (char*)malloc(strlen(expresion) + 1); 
  struct Stack st;
  int convertedIndex = 0;
  
  for(int i = 0; expresion[i] != '\0'; i++) {
    if (isOperator(expresion[i]) == 1){
      if (getPre(expresion[i]) > getPre(peak(st))) {
        push(&st, expresion[i]);
      } else {
        while (st.top != NULL && getPre(expresion[i]) <= getPre(peak(st))){
          converted[convertedIndex++] = pop(&st);
        }
        push(&st, expresion[i]);
      }
    } else {
      converted[convertedIndex++] = expresion[i];
    }
  }

  while (st.top != NULL) {
    converted[convertedIndex++] = pop(&st);
  }
  
  return converted;
}

// void printString(char* str) {
//   for (int i = 0; str[i] != '\0'; i++){
//     printf("%c",str[i]); 
//   }
//   printf("\n");
// }

// int main () {
//   // char *converted= convert("a+b*c-d/e");
//   char *converted= convert("a+b+c*d");
//   printString(converted);
//
//   /* struct Stack st; */
//   /* push(&st, '+'); */
//   /* pop(&st); */
//   /**/
//   /* push(&st, '+'); */
//   /* push(&st, 'x'); */
//   /**/
//   /* display(st); */
//
//   return 0;
// }
