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

void insertionSort(int arry[], int lenght){
  int i, j, key;
  for (i = 1; i < lenght; i++){
    key = arry[i];
    j = i-1; 
    while (j >= 0 && arry[j] > key){
      arry[j+1] = arry[j];
      j--;
    }
    arry[j+1] = key;
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

  insertionSort(arry, value);
  
  return 0;
}