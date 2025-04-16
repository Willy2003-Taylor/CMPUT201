#include<stdio.h>

void print_binary(unsigned int num){
    int power = 1;

    if(num == 0){
        printf("0");
        return;
    }

    while(power <= num)
        power *= 2;

    power /= 2;

    while(power > 0){
        if(power <= num){
            printf("1");

            num -= power;
        }

        else printf("0");

        power /= 2;
    }

    printf("\n");
    
}

int main(){
    printf("Enter an unsigned integer: ");

    unsigned int num;
    scanf("%u", &num);

    printf("The corresponding binary number is: ");

    print_binary(num);

    return 0;
}