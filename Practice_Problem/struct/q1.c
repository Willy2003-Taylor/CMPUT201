#include<stdio.h>
#include<stdlib.h>

/*Practice Problem: Create a struct to store our array of integers.
Update push and pop so that they work on the struct type.*/

struct array{
    size_t length;
    size_t capacity;
    int* data;
};

void printArray(struct array* arr){
    if(arr->length == 0) return;

    for(size_t i = 0; i < arr -> length - 1; ++i)
        printf("%d ", arr->data[i]);

    printf("%d\n", arr->data[arr->length - 1]);
}

void push(struct array* arr, int value){
    if(arr->length == arr->capacity){
        int* tmp = malloc((arr->capacity * 2) * sizeof(int));

        if(!tmp){
            fprintf(stderr, "Initialization error\n");
            return;
        }

        for(int i = 0; i < arr->length; ++i)
            tmp[i] = arr->data[i];

        free(arr->data);
        arr->data = tmp;
        arr->capacity *= 2;
    }

    arr->data[arr->length++] = value;
}

void pop(struct array* arr){
    if(arr->length > 0) arr->length--;
}

int main(){
    struct array arr;

    arr.length = 0;
    arr.capacity = 4;
    arr.data = malloc(arr.capacity * sizeof(int));

    if(!arr.data){
        fprintf(stderr, "Initialization failed\n");
        return 1;
    }

    while(!feof(stdin)){
        int x;
        int input_num = scanf("%d", &x);

        if(input_num == 1) push(&arr, x);
    }

    printf("\n");

    printf("After pushing the entries in the array are: ");

    size_t size = arr.length;

    printArray(&arr);

    while(arr.length > 0){
        pop(&arr);

        printf("Entries remaining after %ld popping: ", (size - arr.length));

        printArray(&arr);
    }

    printf("Popping is completed, now the array is empty.\n");

    free(arr.data);

    return 0;
}