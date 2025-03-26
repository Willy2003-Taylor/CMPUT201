#include<stdio.h>
#include<stdlib.h>

char** map_input(int width, int height){
    char** map = malloc(width* sizeof(char*));
    if(!map) return NULL;

    for(size_t i = 0; i < width; ++i){
        map[i] = malloc(height* sizeof(char));
        if(!map) return NULL;
    }

    for(size_t i = 0; i < width; ++i)
        for(size_t j = 0; j < height; ++i)
            scanf(" %c", &map[i][j]);

    return map;
}

int bomb_count(int x, int y, char** map, int width, int height){
    int result = 0;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < width && ny >= 0 && ny < height)
            if (map[nx][ny] == 'X')
                result++;
    }

    return result;
}

void map_print(){
    char** map = map_input(width, height);

    for(size_t i = 0; i < height; ++i)
        for(size_t j = 0; j < width; ++j)
            printf("%c ", map[i][j]);

        printf("\n");
}

int main(){
    int width, height, x, y;



    scanf("%d %d", &width, &height);

    char** map = map_input(width, height);

    while(scanf("%d %d", &x, &y) == 2){
        if(map[x][y] == 'X'){
            
            continue;
        }

        else if(map[x][y] == 'O'){
            printf();
        }
    }

    return 0;
}