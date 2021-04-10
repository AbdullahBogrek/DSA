#ifndef stack_ll
#define stack_ll

struct Node{
   char value;
   struct Node * next;
};

void push(char data);
void pop();
char top_value();
void print_stack();

#endif 
