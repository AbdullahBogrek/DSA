#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

// char popped = NULL;

struct Node * top = NULL;

void push(char data){
   struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
   temp -> value = data;
   // If stack is empty
   if(top == NULL){
      temp -> next = NULL;
   }
   temp -> next = top;
   top = temp;
}

void pop(){
   if(top != NULL){
      struct Node * temp = top;
      top = top->next;
      // popped = temp->value;
      free(temp);
   }
   else {
      printf("Stack is empty. You can't do this \n");
   }
}

char top_value(){
   return top -> value;
}

void print_stack(){
   if (top == NULL){
      printf("Stack is empty. You can't print. \n");
   }
   else {
      struct Node * iter = top;
      while(iter != NULL){
         printf("%d <= ", iter->value);
         iter = iter->next;
      }
      printf("NULL\n");
   }
}
