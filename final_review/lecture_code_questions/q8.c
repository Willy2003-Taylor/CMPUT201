#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("We received %d cmd line arguments\n", argc);

    for (int i = 0; i < argc; ++i) 
        printf("argv[%d]: %s\n", i, argv[i]);
}

/*Let's assume that we use gcc q8.c -o q8 to obtain an executable
file q8 and type ./q8 <arg1> <arg2> ... (also we can ignore arg mentioned above
and just run the program with ./q8)

After typing enter, the program will record the number of line arguments and obtain
the value of argc, which will be passed to main function then.

Subsequently, the program will print "We received # of line arguments cmd line arguments" with an extra newline
and for loop will be executed for 0 to argc - 1 considering the property of array and all the line
arguments will be printed in the process.*/ 