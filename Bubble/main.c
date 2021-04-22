#include <stdio.h>
#define MAX 16

int arr[MAX], i, value;

void max(int arr[], int value){
    int max = arr[0];
    for (int i = 1; i < value; i++){
        if (max < arr[i]){
            max = arr[i];
        }
    }
    printf("\n");
    printf("max: %d\n", max);
}

void min(int arr[], int value){
    int min = arr[0];
    int i;
    for (i = 1; i < value; i++){
        if (min > arr[i]){
            min = arr[i];
        }
    } 
    printf("\n");
    printf("min: %d\n", min);
}

void bubbleSort(int arr[], int value){
    int j, temp, flag = 0;
    for (i = 0; i < value-1; i++){
        for (j = 0; j < value-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }    
    }   
}

void print(int arr[], int value){
    printf("Sorted Array: ");
    for(i = 0; i < value; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    printf("Please enter the number of elements: ");
    scanf("%d", &value);
    
    for (i = 0; i < value; i++){
        printf("Please enter a element: ");
        scanf("%d", &arr[i]);
    }   

    max(arr, value);
    min(arr, value);
    bubbleSort(arr, value);
    print(arr, value);
    
    return 0;
}