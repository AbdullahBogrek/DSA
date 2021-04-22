#include <stdio.h>
#define MAX 16

int arr[MAX], i, value;

void print(int arr[], int value){
    printf("Sorted Array: ");
    for(i = 0; i < value; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertion(int arr[], int value){
    int j, key;
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

int main(){
    printf("Please enter the number of elements: ");
    scanf("%d", &value);
    
    for (i = 0; i < value; i++){
        printf("Please enter a element: ");
        scanf("%d", &arr[i]);
    }       

    insertion(arr, value);
    print(arr, value);
    return 0;
}