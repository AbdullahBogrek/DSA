#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_ll.h"

const char * pop(struct Node * root){
   if (root == NULL){
      printf("Stack is empty. You cannot pop.");
      return "Error";
   }

   if (root -> next == NULL){
      char popped[MAX];
      strcpy(popped, root -> value);
      free(root);
      return popped;
   }
   
   struct Node * iter = root;
   while (iter -> next -> next != NULL){
      iter = iter -> next;
   }
   struct Node * temp = iter -> next;
   char popped[MAX];
   strcpy(popped, temp -> value);
  
   iter -> next = NULL;
   free(temp);
   return popped;   
}

struct Node * push(struct Node * root, char data[MAX]){
   if (root == NULL){
      root = (struct Node *)malloc(sizeof(struct Node));
      strcpy(root -> value, data);
      root -> next = NULL;
      return root;
   }
   struct Node * iter = root;
   while (iter -> next != NULL){
      iter = iter -> next;
   }
   struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
   strcpy(temp -> value, data);
   temp -> next = NULL;
   iter -> next = temp;
   return root;   
}

void display_list(struct Node * root) {
   while (root != NULL){
      printf("<- %s -> ", root->value);
      root = root->next;
   }
}

const char * top(struct Node * root){
   struct Node * iter = root;
   while (iter -> next != NULL)
      iter = iter -> next;
   return iter;
}

int empty(struct Node * root){
   if (root == NULL)
     return 1;
}