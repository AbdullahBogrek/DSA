#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void print(int arr[], int value){
    printf("Sorted Array: ");
    for(int i = 0; i < value; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

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
    int i, j, temp, flag = 0;
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

void insertionSort(int arr[], int value){
    int i, j, key;
    for (i = 1; i < value; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int value){
    int i, j, min, temp;
    for (i = 0; i < value-1 ; i++){
        min = i;
        for (j = i+1; j < value; j++){
            if (arr[j] < arr[min])
                min = j;
        }
        // swapping
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}