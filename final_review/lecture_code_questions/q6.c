#include<stdio.h>

void times2(int x){
    x *= 2;

    /*The issue is that times2 just double the passed parameter
    when the function is being called and the doubled value will be vanished
    after the program finishes executing the function so it will not change
    the value of x in the main function*/
}

int main(){
    int x = 10;
    times2(x);

    return 0;
}