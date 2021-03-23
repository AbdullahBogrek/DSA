#include <stdio.h>
#include <stdlib.h>

typedef struct n{ 
    char data;
    Node * next;
    Node * prev;
}Node;

void printAll(Node * r){
    printf("Browsing History\n");
    while (r != NULL){
        printf(" - %d\n", r -> data);
        r = r -> next;
    }
    printf("\n");
}

void backward(){

}

void forward(){

} 

void addNode(Node * r, char * input){
    if (r == NULL){
       r = (Node *)malloc(sizeof(Node));
       r -> data = input;
       r -> next = NULL;
       r -> prev = NULL;  
    }
    Node * iter = r;
    while (iter -> next != NULL) iter = iter -> next;
       
    Node * temp = (Node *)malloc(sizeof(Node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> prev = iter;
    if (temp -> next != NULL) temp -> next -> prev = temp;    
    temp -> data = input;
}

int main(){
    Node * root;
    root = NULL; 

    char userInput[50];

    printf("Welcome\n\n");
    printf("Please enter a page: ");
    scanf("%s", userInput);

    addNode(root, userInput);

    printf("Please enter a page: ");
    scanf("%s", userInput);

    printAll(root);
}