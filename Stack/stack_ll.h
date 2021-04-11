#ifndef stack_ll
#define stack_ll

typedef struct stringData {
    char *data;
    struct stringData *next;
}Node;

Node * push(Node *, char []);
char pop(Node *);
char top_value(Node *);
void print_stack(Node *);
int empty(Node *);

#endif 