#include <stdio.h>
#include <stdlib.h>

void max(int a[], int lenght){
  int max = a[0];
  for (int i = 1; i < lenght; i++){
    if (max < a[i]){
      max = a[i];
    }
  }
  printf("\n");
  printf("max: %d", max);
}

void min(int a[], int lenght){
  int min = a[0];
  int i;
  for (i = 1; i < lenght; i++){
    if (min > a[i]){
      min = a[i];
    }
  } 
  printf("\n");
  printf("min: %d", min);
}

void heap(int arry[], int lenght){
  int i, j, temp;
  for (i = 0; i < lenght-1; i++){
    for (j = 0; j < lenght-1; j++){
      if (arry[j] > arry[j+1]){
        temp = arry[j];
        arry[j] = arry[j+1];
        arry[j+1] = temp;
      }
    }    
  }
  printf("\n");
  for (i = 0; i < lenght; i++){
   printf("%d ", arry[i]); 
  }
}

int main(){
  int value;
  printf("Please enter a array lenght :");
  scanf("%d",&value);
  int arry[value];
  for (int i = 0; i < value; i++){
    int num = rand() % 100 + 1;
    arry[i] = num;
  }
  for (int i = 0; i < value; i++){
    printf("%d ", arry[i]);
  }

  max(arry, value);
  min(arry, value); 

  heap(arry, value);
  
  return 0;
}