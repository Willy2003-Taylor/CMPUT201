#include<stdio.h>
#include<stdlib.h>

/*Practice Problem: Write a function pop that takes in an array of integers
and removes the last item from the array. The function should have a 
void return type and any changes it needs to make to the callers
data should be done through mutation. (You need to finish push and printArray functions before approaching this problem)*/

void printArray(int* arr, size_t* length){
    if(*length == 0) return;

    for(size_t i = 0; i < *length - 1; ++i)
        printf("%d ", arr[i]);

    printf("%d\n", arr[*length - 1]);
}

void push(int** arr, int value, size_t* length, size_t* capacity){
    if(*length == *capacity){
        int* tmp = malloc((*capacity * 2) * sizeof(int));
        
        for(int i = 0; i < *length; ++i)
            tmp[i] = (*arr)[i];

        free(*arr);
        *arr = tmp;
        *capacity *= 2;
    }

    (*arr)[(*length)++] = value;
}

void pop(int* arr, size_t* length){
    if(*length > 0) (*length)--;
}

int main(){
    int* arr = malloc(4 * sizeof(int));
    size_t length = 0, capacity = 4;

    while(!feof(stdin)){
        int x;
        int input_num = scanf("%d ", &x);

        if(input_num == 1) push(&arr, x, &length, &capacity);
    }

    printf("\n");

    printf("After pushing the entries in the array are: ");

    size_t size = length;

    printArray(arr, &length);

    while(length > 0){
        pop(arr, &length);

        printf("Entries remaining after %ld popping: ", (size - length));

        printArray(arr, &length);
    }

    printf("Popping is completed, now the array is empty.\n");

    free(arr);

    return 0;
}