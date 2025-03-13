#include<stdio.h>

int decimal_hamming_dis(unsigned x, unsigned y){
    int distance = 0;

    while (x != 0){
        if (x % 10 != y % 10) distance++;

        x /= 10; y /= 10;
    }

    return distance;
}

int main(){
    unsigned x, y;

    scanf("%u%u", &x, &y);

    printf("%d\n", decimal_hamming_dis(x, y));

    return 0;
}