#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char** operators;
    int* operands;
    int size;
    int capacity;
}SequenceList;

void init_SequenceList(SequenceList* List){
    List -> capacity = 1;
    List -> size = 0;
    List -> operators = malloc(List -> capacity * sizeof(char*));
    List -> operands = malloc(List -> capacity * sizeof(int));
}

void add_operations(SequenceList* List, char* operator, int operand){
    if(List -> size == List -> capacity){
        List -> capacity *= 2;
        List -> operators = realloc(List -> operators, List -> capacity * sizeof(char*));
        List -> operands = realloc(List -> operands, List -> capacity * sizeof(int));
    }

    List -> operators[List -> size] = malloc(4* sizeof(char));
    strcpy(List -> operators[List -> size], operator);
    List -> operands[List -> size] = operand;
    List -> size++;
}

void free_SequenceList(SequenceList* List){
    for(int i = 0; i < List -> size; ++i)
        free(List -> operators[i]);

    free(List -> operators);
    free(List -> operands);
}

int main(int argc, char* argv[]){
    SequenceList sequence;
    init_SequenceList(&sequence);

    int N = atoi(argv[1]);

    char input[10];
    
    while(scanf("%s", input) != EOF){
        if(strcmp(input, "n") == 0){
            int next = N;

            for(int i = 0; i < sequence.size; ++i){
                if(strcmp(sequence.operators[i], "add") == 0)
                    next += sequence.operands[i];

                else if(strcmp(sequence.operators[i], "sub") == 0)
                    next -= sequence.operands[i];

                else if(strcmp(sequence.operators[i], "mul") == 0)
                    next *= sequence.operands[i];

                else if(strcmp(sequence.operators[i], "div") == 0)
                    next /= sequence.operands[i];
            }

            printf("%d\n", next);
            N = next;
        }
        
        else{
            int operand;
            scanf("%d", &operand);
            add_operations(&sequence, input, operand);
        }
    }

    free_SequenceList(&sequence);

    return 0;
}