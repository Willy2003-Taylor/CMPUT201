#include<stdio.h>

/*Practice Problem: Implement the following function (using this exact function prototype):
unsigned int rotate_right(unsigned int i, int n);

rotate_right returns the result of shifting the bits in i to the right by n places, with the bits that were
“shifted off” moved to the left end of i. For example, the call rotate right(0x12345678, 4) must
return 0x81234567 and the call rotate right(0xc2345678, 2) must return 0x308d159e. You MUST
use bitwise operators to implement this function. You will not get any marks if you implement it in another
way. Your code must run correctly on any machine, regardless of how many bits it uses to
store an unsigned int.*/

unsigned int rotate_right(unsigned int i, int n){\
    for(int t = 1; t <= n; ++t)
        i >>= 1;

    return i;
}

int main(){
    printf("Enter the operand i and the corresponding parameter n: ");

    unsigned int i;
    int n;

    scanf("%d %d", &i, &n);

    unsigned int result = rotate_right(i, n);

    printf("The result after shifting is: %u\n", result);

    return 0;
}