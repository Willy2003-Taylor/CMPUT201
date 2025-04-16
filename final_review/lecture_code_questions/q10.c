#include<stdio.h>

int main(){
    int x;
    
    while(scanf("%d", &x) == 1)
        fprintf(stdout, "%d", x);

    fprintf(stdout, "\n");

    /*Assume we use gcc q10.c -o q10 to obtain q10 as the executable file
    
    The difference between writing to stdout and stderr
    can be illustrated by redirecting the output to different files
    
    1. Run the program with ./q10 > output_q10.txt, we will see nothing to output
    after entering the number because we use stdout buffer to ask the program to 
    redirect the output to a specific file.
    
    2. Run the program with ./q10 2> error_q10.txt, we will see the number is printed
    in the terminal but nothing shown in the specific file since we use stderr buffer
    to ask the program to redirect the output to a specific file. Since the parameter
    of fprintf is stdout instead of stderr, so nothing to be printed in the error_q10.txt */

    return 0;
}