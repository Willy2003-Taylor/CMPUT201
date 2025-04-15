#include<stdio.h>

/*Practice Problem: Implement your own strlen function called my strlen. You can not use character comparisons, but
are allowed to use the following functions: strcmp, strcpy, strcat.
(Note that you don’t have to use these functions.) According to the man page definition for strlen:

The strlen() function calculates the length of the string pointed to by s, 
excluding the terminating null byte (‘\0’).

You can not access individual characters of the string (using []),
but are allowed to use pointers to access sub-strings. */

size_t my_strlen(const char* s){
    size_t length = 0;

    while(*s != '\0'){
        length++;
        s++;
    }

    return length;
}

int main(){

    const char* s = "This is a string";

    printf("The given string is: %s\n", s);

    printf("The length of the given s is: %lu", my_strlen(s));

    printf("\n");

    return 0;
}