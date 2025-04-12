#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Practice Problem: Write a program that takes in any number of command line arguments
 that represent integers. Your program should multiply those numbers together
 and print out the result. 
 Remember your command line arguments are provided as strings!
 */

 int main(int argc, char* argv[]){
    int result = 1, power = 1;

    int is_negative = 0, end_index = 0;

    int capacity = 4, length = 0;
    
    int* num = malloc(capacity * sizeof(int));

    for(int i = 1; i < argc; ++i){
        if(length == capacity){
            int* tmp = malloc((capacity * 2) * sizeof(int));

            for(int i = 0; i < length; ++i)
                tmp[i] = num[i];

            free(num);
            num = tmp;

            capacity *= 2;
        }

        end_index = 0;
        is_negative = 0;
        power = 1;

        int arg_length = strlen(argv[i]);

        if(argv[i][0] == '-'){
            is_negative = 1;
            end_index = 1;
        }

        for(int j = arg_length - 1; j >= end_index; --j){
            num[length] += ((argv[i][j] - '0') * power);
            power *= 10;
        }

        if(is_negative) num[length] = -num[length];

        length++;
    }

    for(int i = 0; i < length; ++i)
        result *= num[i];

    printf("The result is: %d\n", result);

    free(num);

    return 0;
 }