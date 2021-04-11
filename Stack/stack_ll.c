#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

Node * push(Node * root, char data[]){
    // if stack is empty
    if (root == NULL){
        root = (Node *)malloc(sizeof(Node));
        root -> data = data;
        root -> next = NULL;
        return root;
    }
    //if stack is not empty
    Node * iter = root;
    while (iter -> next != NULL)
        iter = iter -> next;
    Node * temp = (Node *)malloc(sizeof(Node));
    temp -> data = data;
    temp -> next = NULL;
    iter -> next = temp;
    return root;
}

char pop(Node * root){
    // if stack is empty
    if (root == NULL){
        printf("Stack is empty. You can't do this \n");
        return -1;
    }
    if (root -> next == NULL){
        char popped = root -> data;
        free(root);
        return popped;
    }    
    Node * iter = root;
    while (iter -> next -> next != NULL)
        iter = iter -> next;
    Node * temp = iter -> next;
    char popped = temp -> data;
    iter -> next = NULL;
    free(temp);
    return popped;
}

char top_value(Node * root){
    Node * iter = NULL;
    while (iter -> next != NULL)
        iter = iter -> next;
    return iter -> data;
}

void print_stack(Node * root){
    if (root == NULL){
        printf("Stack is empty. You can't print. \n");
    }
    else {
        Node * iter = root;
        while(iter != NULL){
            printf("%d <= ", iter -> data);
            iter = iter -> next;
        }
        printf("NULL\n");
   }
}

int empty(Node * root){
    if (root -> next == NULL)
        return 1;
    else
        return -1;
}