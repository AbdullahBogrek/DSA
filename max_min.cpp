#include <stdio.h>
#include <stdlib.h>

int max(int a[], int lenght){
  int max = a[0];
  for (int i = 1; i < lenght; i++){
    if (max < a[i]){
      max = a[i];
    }
  }
  printf("\n");
  printf("max: %d", max);
  return max;
}

int min(int a[], int lenght){
  int min = a[0];
  for (int i = 1; i < lenght; i++){
    if (min > a[i]){
      min = a[i];
    }
  } 
  printf("\n");
  printf("min: %d", min);
  return min;
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
  return 0;
}