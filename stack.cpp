#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct n{
  int x;
  n * next;
};
typedef n node;

void printStack(node * r){
  while (r != NULL)
  {
    printf("%d ", r -> x);
    r = r -> next;
  }
  
}
int pop(node * r){
  if (r == NULL){
    printf("Sayı bulunamadı.");
    return -1;
  }
  else if (r -> next == NULL){
    int rvalue = r -> x;
    free(r);
    return rvalue;
  }
  node * iter = r;
  while (iter -> next -> next != NULL){
    iter = iter -> next;
  }
  node * temp = (node *)malloc(sizeof(node));
  int rvalue = temp -> x;
  iter -> next = NULL;
  free(temp);
  return rvalue;
}
node * push(node * r, int x){
  if (r == NULL){
    node * temp = (node *)malloc(sizeof(node));
    temp -> x = x;
    temp -> next = NULL;
    r = temp;
    return temp;
  }
  else if (r -> next == NULL){
    node * temp = (node *)malloc(sizeof(node));
    temp -> next = NULL;
    temp -> x = x;
    r -> next = temp;
    return r;
  }
  node * iter = r;
  while (iter -> next != NULL){
    iter = iter -> next;
  }
  node * temp = (node *)malloc(sizeof(node));
  temp -> x = x;
  temp -> next = NULL;
  iter -> next = temp;
  return r;  
}
int main(){
  node * root;
  root = push(root,10);
  root = push(root,50);
  root = push(root,25);
  root = push(root,17);
  printStack(root);
  pop(root);
  printf("\n");
  printStack(root);

}