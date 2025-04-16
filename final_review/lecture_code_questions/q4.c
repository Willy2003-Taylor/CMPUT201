#include<stdio.h>

void print_binary(unsigned int num){
    while(num != 0){
        if(num % 2) printf("1");

        else printf("0");

        num /= 2;
    }

    printf("\n");
}

int main(){
    unsigned int num;
    scanf("%u", &num);
    print_binary(num);

    return 0;
}