#include<stdio.h>

void lower_to_upper(char* ch){
    *ch = *ch + ('A' - 'a');
}

int main(){
    char ch;

    printf("Please enter a character: ");

    scanf("%c", &ch);

    lower_to_upper(&ch);

    printf("The corresponding uppercase letter is: %c\n", ch);

    return 0;
}