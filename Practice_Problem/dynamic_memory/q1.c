#include<stdio.h>
#include<stdlib.h>

/*Write a function void primes(int n) that takes as a
parameter one int and prints out (in order) all of the prime
numbers smaller than that int.*/

/*Use the sieve of Eratosthenes to find all the primes between 2 and n - 1

which is for each number x, k*x is definitely not a prime (k is integer)*/

void prime(int n){
    /*This function takes an integer n and prints out all the
 primes less than that number.*/
    int size = n - 2;
    int* arr = malloc(sizeof(int) * size);
    
    for(int i = 0; i < size; ++i)
        arr[i] = i + 2;
        //Start from 2
    
    int i = 0;
    while (i < size){
        printf("%d ", arr[i]);
    
        for(int j = i + arr[i]; j < size; j += arr[i])
            arr[j] = 0; //These are not primes, marking it to 0
        
        for(i = i + 1; i < size && !arr[i]; ++i);
    }
    printf("\n");
    free(arr);
}

int main(){
    int num;
    printf("Please input an integer: ");
    scanf("%d", &num);

    prime(num);
    
    return 0;
}