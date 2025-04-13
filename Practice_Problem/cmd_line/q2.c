#include<stdio.h>
#include<string.h>

/*Practice Problem: Update the word count program we wrote earlier to mimic
support of the -l, -w, and -c flags that the built-in wc command provides*/

void wc_function(int* lines, int* words, int* bytes, char* filename){
    FILE* file;
    char ch;
    int in_word = 1;
    file = fopen(filename, "r");

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

    int option_start = 1;

    if(argc <= 1){
        printf("Usage: %s [OPTION] <filename> ([OPTION] is not mandatory)\n", argv[0]);
        return 1;
    }

    if(argc > 2 && (strcmp(argv[1], "-l") == 0) ||(strcmp(argv[1], "-w") == 0) || (strcmp(argv[1], "-c") == 0)) 
        option_start = 2;

    wc_function(&lines, &words, &bytes, argv[option_start]);

    if(argc == 2) printf(" %d %d %d\n", lines, words, bytes);

    else if(strcmp(argv[1], "-l") == 0) printf("%d\n", lines);

    else if(strcmp(argv[1], "-w") == 0) printf("%d\n", words);

    else if(strcmp(argv[1], "-c") == 0) printf("%d\n", bytes);

    return 0;
}