#include <stdio.h>
#include "sort.h"
#define MAX 16
    
int main(){

    int arr[MAX], i, value;
    char o;

    printf("-----Sorting Algorithms: -----\n");
    printf("---- Selection sort == 's' .\n");
    printf("---- Insertion sort == 'i' .\n");
    printf("------- Bubble sort == 'b' .\n");
    printf("Select an sorting algorithm: ");
    scanf("%c", &o);

    printf("Please enter the number of elements: ");
    scanf("%d", &value);
    
    for (i = 0; i < value; i++){
        printf("Please enter a element: ");
        scanf("%d", &arr[i]);
    }       

    switch(o){
        case 's':
            selectionSort(arr, value);
            print(arr, value);
            break;

        case 'i':
            insertionSort(arr, value);
            print(arr, value);
            break;

        case 'b':
            bubbleSort(arr, value);
            print(arr, value);
            break;

        default:
            printf("Error! Operator is not correct");
    }
    return 0;
}