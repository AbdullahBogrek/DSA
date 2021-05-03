#include <stdio.h>
#include <stdlib.h>

struct n{
  int x;
  struct n * next;
  struct n * prev;
};

typedef struct n Node;

void display_list(Node * root) {
   while (root != NULL){
      printf("<- %d -> ", root->x);
      root = root->next;
   }
   printf("\n");
   printf("\n");
}

Node* addNodes(Node* r, int x){
  if (r == NULL){
    r = (Node*)malloc(sizeof(Node));
    r -> next = NULL;
    r -> prev = NULL;
    r -> x = x;
    return r;
  }
  if (r -> x > x){
      Node* temp = (Node*)malloc(sizeof(Node));
      temp -> x = x; 
      temp -> next = r;
      temp -> prev = NULL;
      r -> prev = temp;
      return temp;
  }
  Node* iter = r; 
  while (iter -> next != NULL && iter -> next -> x < x){
    iter = iter -> next;
  }
  Node* temp = (Node*)malloc(sizeof(Node));
  temp -> x = x;
  temp -> next = iter -> next;
  temp -> prev = iter;
  iter -> next = temp;
  if (iter -> next != NULL)
    iter -> next -> prev = temp;
  return r; 
}

Node* delNodes(Node* r, int x){
  Node* iter = r;
  Node* temp;
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

int main()
{
  int num, value;
  double n1, n2;

  Node * root;
  root = NULL;

  do
  {
    printf("-----Doubly Linked List-----\n");
    printf("1 - Add a node. \n");
    printf("2 - Delete a node.\n");
    printf("3 - Print nodes. \n");
    printf("4 - Quit. \n");
    printf("Please select an operation: ");
    scanf("%d", & num);

		while (num < 1 || num > 4)
		{
			printf("Please enter a valid num \n");
			printf("Enter 1, 2, 3, or 4: \n");
      scanf("%d", & num);
		}

    switch (num)
    { 
      case 1: 
        printf("Please enter the node value: ");
        scanf("%d", & value);
        root = addNodes(root, value);
        printf("\nNode added.\n");
        break;
      case 2: 
        printf("Please enter the value to be deleted: ");
        scanf("%d", & value);
        delNodes(root, value);
        printf("\nNode deleted.\n");
        break;
      case 3: 
        printf("List\n");
        display_list(root);
        break;
      case 4: 
        printf("Exiting....\n");
        break;
      default: 
        printf("Please select operator 1, 2 or 3.\n");
        break; 
    }
  } while (num <= 3 && num >= 1);
  return 0;
}