#include<stdio.h>

/*Write a function replace which takes in an
array and is parameterized by two integers tar and repl and
replaces every instance of tar in the given array with repl */

/*Assume the array size is not larger than 100*/

void replace(int* num, int n, int tar, int repl){
    for(int i = 0; i < n; ++i)
        if(num[i] == tar)
            num[i] = repl;

    for(int i = 0; i < n; ++i)
        printf("%d ", num[i]);
    
    printf("\n");
}

int main(){
    printf("Input the array size (Cannot be larger than 100): ");
    int size;
    scanf("%d", &size);

    if(size <= 0 || size > 100){
        printf("Invalid array size. Size must be between 1 and 100.\n");
        return 1;
    }

    int num[size], tar, repl;

    printf("Input the values for the array: ");

    for(int i = 0; i < size; ++i)
        scanf("%d", &num[i]);
    
    printf("Input the target and the character you want to replace the target with: ");

    if(scanf("%d%d", &tar, &repl) != 2){
        printf("Invalid Input!\n");
        return 1;
    }

    printf("The array whose %d is replaced by %d is: ", tar, repl);

    replace(num, size, tar, repl);
    
    return 0;
}
