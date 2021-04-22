#include <stdio.h>
#define MAX 16

int arr[MAX], i, value;

void print(int arr[], int value){
    printf("Sorted Array: ");
    for(i = 0; i < value; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selection(int arr[], int value){
    int j, min, temp;
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

int main(){
    printf("Please enter the number of elements: ");
    scanf("%d", &value);
    
    for (i = 0; i < value; i++){
        printf("Please enter a element: ");
        scanf("%d", &arr[i]);
    }       

    selection(arr, value);
    print(arr, value);
    return 0;
}