#include<stdio.h>

/*Practice Problem: Write a function print binary that has one
unsigned int parameter and prints out the binary representation
of that number.*/

/*Method 1 */

void decimal_binary(unsigned int num){
    if(num == 0)
        printf("0");
    
    int power = 1;

    while (power <= num)
        power <<= 1;
    
    power >>= 1; 
    /*Since after the previous while loop ends,
    the value of power is out of num, which is not our target
    therefore, we need to divide it by 2 to make it inbound */

    while (power > 0){
        if(power <= num){
            printf("1");
            num -= power;
        }

        else printf("0");
        power >>= 1;
    }
    printf("\n");
}

int main(){
    unsigned int num;
    scanf("%u", &num);
    decimal_binary(num);

    return 0;
}