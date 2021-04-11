#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_ll.h"

Node * backward = NULL; // backward stack
Node * forward = NULL;  // forward stack
 
void new_url(char * url){
    ////////// p0 olma durumunda hata veririse 0 değerine bak
    if (url[0] != '\0'){
        backward = push(backward, url);
    }
}   

void forward_btn(char * p){
    if (empty(forward) == 1 || p == top_value(forward)){
        printf("The site is not available.");
    }
    else{
        push(backward, p);
        p = top_value(forward);
        pop(forward);
    }
}

void backward_btn(char * p){
    if (empty(backward) == 1 || p == top_value(backward)){
        printf("The site is not available.");
    }
    else{
        push(forward, p);
        p = top_value(backward);
        pop(backward);
    }
}

int main(){
    //Create a linked list that type is 'Node *'
    //struct Node * backward = NULL; <== like this
    //You can use functions is;
    //push(root, data) , pop(root), print_stack(root) and tochar current_url[16]; // string 

    char current_url[16]; // string 

    printf("Please enter a website: ");
    scanf("%s", current_url); // youtube
    new_url(current_url);
    printf("Current url is: %s ", current_url);

    printf("\nPlease enter a another website: ");
    scanf("%s", current_url); // google
    new_url(current_url);
    printf("Current url is: %s ", current_url);

    backward_btn(current_url);
    printf("Current url is: %s ", current_url);
    
    forward_btn(current_url);
    printf("Current url is: %s ", current_url);

    printf("Please enter a another website: ");
    scanf("%s", current_url); // github
    new_url(current_url);
    printf("Current url is: %s ", current_url);

    forward_btn(current_url);
    printf("Current url is: %s ", current_url);

    backward_btn(current_url);
    printf("Current url is: %s ", current_url);

    return 0;
}
