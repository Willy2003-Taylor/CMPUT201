#include<stdio.h>

/*Write a function argmax that returns the index
of the maximal item in an array of integers. What parameters does
your function need to have? 

Assume the array size n cannot be larger than 100*/

/*Parameters you need for the function are the array num and its size n*/

int argmax(int* num, int n){
    if(n <= 0) return -1;

    int max_num = num[0];
    int max_arg = -1;
    for(int i = 0; i < n; ++i)
        if(max_num < num[i]){
            max_num = num[i];
            max_arg = i;
        }

    return max_arg;
}

int main(){
    printf("Input the array size (Cannot be larger than 100): ");
    int size;
    scanf("%d", &size);

    if(size <= 0 || size > 100){
        printf("Invalid array size. Size must be between 1 and 100.\n");
        return 1;
    }

    int num[size];

    printf("Input the values for the array: ");

    for(int i = 0; i < size; ++i)
        scanf("%d", &num[i]);

    printf("The index of the maximum value in the array is: %d\n",argmax(num, size));

    return 0;
}