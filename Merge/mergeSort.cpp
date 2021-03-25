#include <stdio.h>
#include <stdlib.h>

void merge(int arry[], int low, int high, int mid){
  if (low > high){
    
  }
  
}

void mergeSort(int arry[], int low, int high){
  if (low < high){
    int mid = (high+low)/2;
    mergeSort(arry, low, mid);
    mergeSort(arry, mid+1, high);
    merge(arry, low, high, mid);
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

  int low = 0;
  int high = value - 1;
  mergeSort(arry, low, high);


  printf("\n");
  for (int i = 0; i < value; i++){
   printf("%d ", arry[i]); 
  }

  return 0;
}