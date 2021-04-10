#include <stdio.h>
#include <stdlib.h>
#include "stack_ll.h"

int main() {

   printf("---------------Stack--------------\n");
   
   push(10);
   push(20);
   push(30);
   push(40);
   push(50);

   print_stack();

   pop();

   print_stack();

   return 0;
}