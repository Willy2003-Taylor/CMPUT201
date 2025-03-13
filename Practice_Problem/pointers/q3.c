#include<stdio.h>

/* Write the function str replace as described
below.
int str_replace(char *s, char find, char repl);
str_replace replaces every instance of find in string s with the
character repl and returns the number of instances replaced.*/

/*Assume the array size is not larger than 100*/

int str_replace(char* s, char find, char repl){
    int count = 0;

    for(int i = 0; s[i] != '\0'; ++i)
        if(s[i] == find){
            s[i] = repl;
            ++count;
        }
    
    return count;
}

int main(){
    printf("Input the array size (Cannot be larger than 100): ");
    int size;
    scanf("%d", &size);

    if(size <= 0 || size > 100){
        printf("Invalid array size. Size must be between 1 and 100.\n");
        return 1;
    }

    char s[size + 1], find, repl;

    printf("Input the values for the array: ");

    for(int i = 0; i < size; ++i)
        scanf(" %c", &s[i]);
    
    s[size + 1] = '\0';

    while(getchar() != '\n');

    printf("Input the \"find\" and the character you want to replace the \"find\" with: ");

    char input[size + 1];

    if(fgets(input, sizeof(input), stdin) != NULL)
        if(sscanf(input, " %c %c", &find, &repl) != 2){
            printf("Invalid Input!\n");
            return 1;
        }

    printf("The number of instances replaced is %d\n", str_replace(s, find, repl));

    printf("The replaced array is: ");

    for(int i = 0; i < size; ++i)
        printf("%c", s[i]);
    
    printf("\n");
    return 0;
}