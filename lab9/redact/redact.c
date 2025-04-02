#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void redact_file(const char* filename, char** redact_strings, int count){
    FILE* target = fopen(filename, "r");

    if(!target){
        printf("Reading target file error\n");
        return;
    }

    FILE* output = fopen("temp.txt", "w");

    if(!output){
        printf("Reading output file error\n");
        fclose(target);
        return;
    }

    char line[1024];

    while(fgets(line, sizeof(line), target)){
        for(int i = 0; i < count; ++i){
            char* pos = line;
            while((pos = strstr(pos, redact_strings[i])) != NULL){
                memset(pos, 'X', strlen(redact_strings[i]));

                pos += strlen(redact_strings[i]);
            }
        }

        fputs(line, output);
    }

    fclose(target);
    fclose(output);

    remove(filename);
    rename("temp.txt", filename);
}

int main(int argc, char* argv[]){
    char* redact_strings[10];
    int count = 0;    
    char input[256];

    while(count < 10 && fgets(input, sizeof(input), stdin)){
        input[strcspn(input, "\n")] = '\0';

        redact_strings[count] = strdup(input);
        count++;
    }

    redact_file(argv[1], redact_strings, count);

    for(int i = 0; i < count; ++i)
        free(redact_strings[i]);

    return 0;
}