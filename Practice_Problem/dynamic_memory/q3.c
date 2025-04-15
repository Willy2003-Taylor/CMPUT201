#include<stdio.h>
#include<stdlib.h>

int count;

/*Practice Problem: You are given the main function below and are asked to implement 4 functions
 You must decide on the type of the parameters each function will take based on the following description and the main function
 code that shows how these functions will be used.
 
 You MUST NOT change the code in main: your implemented functions MUST work correctly with the function calls in main
 
 1. initArray takes (1) a POINTER to an array of integer pointers and
 (2) the numberof elements it should allocate. Each element should be initialized to 0. After calling initArray in
 the main function below, numbers will be the memory address of an array of integer pointers.
 
 2. addToArray takes (1) an array of integer pointers, (2) the number of elements in the array,
 and (3) an integer pointer. It finds the first available element in the array and makes it point to a
 dynamically allocated space that contains the value of the passed integer. If there are no available
 elements, it prints an error message to the correct output stream and returns.
 
 3. print takes an array of integer pointers and the number of elements n it should print.
 It then prints a comma separated list of the first n integers stored in the array. The last element is
 followed by a newline. If one of these elements is NULL, it skips over it.
 
 4. swap takes (1) an array of integer pointers, (2) an index i1, and (3) an index i2.
 It then swaps the integers at indices i1 and i2. You can assume that both indices are within the
 bounds of the array. You must implement swap WITHOUT allocating any new memory using
 malloc/calloc/realloc or creating a new array.*/

 void initArray(int*** arr, int n){
    *arr = malloc(n * sizeof(int*));

    if(!*arr){
        fprintf(stderr, "Initialization Failure.\n");
        return;
    }
    
    for(int i = 0; i < n; ++i){
        (*arr)[i] = malloc(n * sizeof(int));

        if(!(*arr)[i]){
            fprintf(stderr, "Initialization Error.\n");
            return;
        }
    }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            (*arr)[i][j] = 0;
 }

void addToArray(int** arr, int n, int* p){
    if(count < n) count++;
    for(int i = count - 1; i < count; ++i)
        for(int j = 0; j < n; ++j)
            if(!arr[i][j]) arr[i][j] = *p;
}

void print(int** arr, int n){
    for(int i = 0; i < n; ++i)
        if(arr[i] != NULL) printf("%d ", *arr[i]);

    printf("\n");
}

void swap(int** arr, int i1, int i2){
    int* tmp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = tmp;
}

void destroy(int*** arr, int n){
    for(int i = 0; i < n; ++i)
        free((*arr)[i]);

    free((*arr));
}

int main(){
    int** numbers;

    initArray(&numbers, 5);

    int a = 1, b = 2, c = 3, d = 4, e = 5;

    int* p = &a, *q = &b, *r = &c, *s = &d, *t = &e;

    addToArray(numbers, 5, p);
    addToArray(numbers, 5, q);
    addToArray(numbers, 5, r);
    addToArray(numbers, 5, s);
    addToArray(numbers, 5, t);

    print(numbers, 5);

    swap(numbers, 0, 1);

    print(numbers, 5);

    swap(numbers, 1, 3);

    print(numbers, 5);

    swap(numbers, 4, 0);

    print(numbers, 5);

    destroy(&numbers, 5);

    printf("Destroy successfully.\n");

    return 0;
}