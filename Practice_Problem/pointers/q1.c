#include<stdio.h>

/*Practice Problem: Write a C program that mimics the behaviour of the wc tool we've
used when learning about the shell. For now only worry about the
behaviour of wc when it receives no command-line arguments.*/

void wc_function(int* lines, int* words, int* bytes, char* argv[]){
    FILE* file;
    char ch;
    int in_word = 1;
    
    file = fopen(argv[1], "r");

    if(file == NULL){
        printf("File reading error.\n");
        return;
    }

    while((ch = fgetc(file)) != EOF){
        (*bytes)++;

        if(ch == '\n') (*lines)++;

        if((ch == ' ') || (ch == '\t') || (ch == '\n'))
            in_word = 0;
        
        else if(!in_word){
            (*words)++;
            in_word = 1;
        }
    }

    if(*bytes > 0 && ch != '\n') (*lines)++;

    fclose(file);
}

int main(int argc, char* argv[]){
    int lines = 0, words = 0, bytes = 0;

    if(argc <= 1){
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    wc_function(&lines, &words, &bytes, argv);

    printf(" %d %d %d\n", lines, words, bytes);

    return 0;
}