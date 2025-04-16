#include<stdio.h>

void print_binary(unsigned int num){
    while(num != 0){
        if(num % 2) printf("1");

        else printf("0");

        num /= 2;
    }

    printf("\n");

    /*The issue existed in the function is the algorithm will
    reversely print all the digits of the correct binary number*/
}

int main(){
    unsigned int num;
    scanf("%u", &num);
    print_binary(num);

    return 0;
}