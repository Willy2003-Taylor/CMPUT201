#include<stdio.h>
#include<limits.h>

void sort_file(char* filename){
    FILE* file = fopen(filename, "r");

    if(!file){
        printf("File reading error.");
        return;
    }

    int min = INT_MAX;
    int max = INT_MIN;
    int current;

    while(fscanf(file, "%d", &current) == 1){
        if(current < min) min = current;
        if(current > max) max = current;
    }

    for(int i = min; i <= max; ++i){
        rewind(file);

        while(fscanf(file, "%d", &current) == 1){
            if(current == i) printf("%d ", i);
        }
    }

    printf("\n");

    fclose(file);
}

int main(){
    char filename[256];
    scanf("%255s", filename);

    sort_file(filename);

    return 0;
}