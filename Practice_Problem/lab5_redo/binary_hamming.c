#include<stdio.h>

int binary_hamming_dis(unsigned x, unsigned y){
    int distance = 0;
    
    unsigned flag = x ^ y;

    while (flag != 0){
        distance += flag & 1;
        flag >>= 1;
    }

    return distance;
}

int main(){
    unsigned x, y;
    scanf("%u%u", &x, &y);

    printf("%d\n", binary_hamming_dis(x, y));

    return 0;
}