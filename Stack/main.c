#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_ll.h"

#define MAX 32

char current_url[MAX];
struct Node * forward = NULL;
struct Node * backward = NULL;

void newURL(char url[MAX]){
  if (current_url != "\0"){
    backward = push(backward, current_url);
  }
  strcpy(current_url, url);
}

void forwardButton(){
  if (empty(forward) || current_url == top(forward)){
    printf("Link not available.\n");
    return;
  }
  else{
    backward = push(backward, current_url);
    strcpy(current_url, top(forward));
    pop(forward);
  }
}

void backwardButon(){
  if (empty(backward) || current_url == top(backward)){
    printf("Link not available.\n");
    return;
  }
  else{
    forward = push(forward, current_url);
    strcpy(current_url, top(backward));
    pop(backward);
  }
}

int main(){

  char str[MAX];

  printf("Enter a string: ");
  scanf("%s", str);
  newURL(str);

  printf("Current url is: %s \n", current_url);

  printf("Enter a string: ");
  scanf("%s", str);
  newURL(str);

  printf("Current url is: %s \n", current_url);

  backwardButon();
  printf("Current URL is: %s \n", current_url);

  forwardButton();  
  printf("Current URL is: %s \n", current_url);

  printf("Enter a string: ");
  scanf("%s", str);
  newURL(str);

  printf("Current url is: %s \n", current_url);

  forwardButton();
  printf("Current URL is: %s \n", current_url);

  backwardButon();
  printf("Current URL is: %s \n", current_url);

  return 0;
}