#include<stdio.h>

/*Write a function int str_to_int(char *s) that
takes in a string texttts that is a numeric only string and
returns the integer that string represents.*/

/*Assume the string length is not greater than 100*/

int str_to_int(char* s){
    int result = 0;
    
    while (*s != '\0'){
        result = result * 10 + (*s - '0');
        s++;
    }

    return result;
}

int main(){
    char s[100];
    printf("Input a string that is a numerical only: ");
    
    scanf("%s", s);
    
    printf("The corresponding integer that the string represents is: %d\n", str_to_int(s));

    return 0;
}