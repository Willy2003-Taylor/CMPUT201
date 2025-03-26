#include<stdio.h>
#include<stdlib.h>

char** map_input(int width, int height){
    char** map = malloc(height* sizeof(char*));
    if(!map) return NULL;

    for(size_t i = 0; i < height; ++i){
        map[i] = malloc(width* sizeof(char));
        if(!map[i]) return NULL;
    }

    for(size_t i = 0; i < height; ++i)
        for(size_t j = 0; j < width; ++j)
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

void map_print(char** map, int width, int height){
    for(size_t i = 0; i < height; ++i){
        for(size_t j = 0; j < width; ++j)
            printf("%c", map[i][j]);

        printf("\n");
    }
}

void free_map(char** map, int height){
    for(int i = 0; i < height; ++i)
        free(map[i]);

    free(map);
}

int main(){
    int width, height, x, y;

    scanf("%d %d", &width, &height);

    char** map = map_input(width, height);

    if(!map){
        fprintf(stderr, "Memory Allocation Failed\n");
        return 1;
    }

    map_print(map, width, height);

    while(scanf("%d %d", &y, &x) == 2){
        if(map[x][y] == 'X') printf("BOMB!\n");

        else{
            int count = bomb_count(x, y, map, width, height);

            printf("%d bombs\n", count);
        }
    }

    free_map(map, height);
    return 0;
}