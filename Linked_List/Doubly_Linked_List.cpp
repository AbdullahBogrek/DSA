#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct n{
  int x;
  n * next;
  n * prev;
};

typedef n node;

void printNodes(node * r){
  while (r != NULL){
    printf("%d ",r -> x);
    r = r -> next;
  }
  printf("\n");
}

node * addNodes(node * r, int x){
  if (r == NULL){
    r = (node *)malloc(sizeof(node));
    r -> next = NULL;
    r -> prev = NULL;
    r -> x = x;
    return r;
  }
  if (r -> x > x){
      node * temp = (node *)malloc(sizeof(node));
      temp -> x = x; 
      temp -> next = r;
      temp -> prev = NULL;
      r -> prev = temp;
      return temp;
  }
  node * iter = r; 
  while (iter -> next != NULL && iter -> next -> x < x){
    iter = iter -> next;
  }
  node * temp = (node *)malloc(sizeof(node));
  temp -> x = x;
  temp -> next = iter -> next;
  temp -> prev = iter;
  iter -> next = temp;
  if (iter -> next != NULL)
    iter -> next -> prev = temp;
  return r; 
}

node * delNodes(node * r, int x){
  node * iter = r;
  node * temp;
  if (r -> x == x){
    temp = r;
    r = r ->next;
    r -> next -> prev = NULL;
    free(temp);
    return r;
  }
  while (iter -> next != NULL && iter -> next -> x != x){
    iter = iter -> next;
  }
  if (iter -> next == NULL){
    printf("Sayı Bulunamadı ");
    return r;
  }
  temp = iter -> next;
  iter -> next = iter -> next -> next;
  if (iter -> next != NULL)
    iter -> next -> prev = iter;
  free(temp);
  return r;
}  

int main(){
  node * root;
  root = NULL;
  root = addNodes(root, 600);
  root = addNodes(root, 100);
  root = addNodes(root, 200);
  root = addNodes(root, 400);
  root = addNodes(root, 300);
  root = addNodes(root, 500);
  printNodes(root);

  delNodes(root, 300);
  printNodes(root);

  delNodes(root, 600);
  printNodes(root);
  
  delNodes(root, 1000);
  printNodes(root);

  delNodes(root, 400);
  printNodes(root);
  return 0;
};  