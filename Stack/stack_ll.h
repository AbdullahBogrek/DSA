#ifndef stack_ll
#define stack_ll

#define MAX 32

struct Node {
	char value[MAX];
   struct Node * next;
};

const char * pop(struct Node * root);
struct Node * push(struct Node * root, char data[MAX]);
void display_list(struct Node * root);
const char * top(struct Node * root);
int empty(struct Node * root);

#endif 
