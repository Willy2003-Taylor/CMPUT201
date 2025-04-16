#include<stdio.h>

int main() {
    for (int i = 0; i < 10; ++i)
    printf("%d\n", i);

    int x;
    int y;

    for(int x = 0, y = 0; x*y < 100; x = x+2, y = y+3)
        printf("(%d, %d)\n", x, y);

    printf("x: %d, y: %d\n", x, y);
    printf("i: %d\n", i); // Will this compile? Why or why not?

    /*Variable i: will be vanished after the for loop is executed

    Variables x and y in for loop: will be printed 
    every time when for loop is being executed 
    and not be vanished after the whole for loop is ended

    since x = 0, y = 0 indicates x and y here are identical to the defined x and y
    in the main function.x

    If we change x = 0, y = 0 to int x = 0, y = 0 in for loop, they will be different
    from the x and y defined in the main function. 
    x and y printf("x: %d, y: %d\n", x, y); outside of for loop are still variables defined 
    in the main function, which may produce 'garbage' values.
    
    When printf("x: %d, y: %d\n", x, y); is executed,
    it will cause undefined behaviors since x and y in this
    statement are defined and uninitialized in main function but this line will pass
    compilation.
    
    The last one printf("i: %d\n", i); before return 0 will not compile since the
    compiler will detect that i is not defined in the main function, making a compilation error.*/

    return 0;
}