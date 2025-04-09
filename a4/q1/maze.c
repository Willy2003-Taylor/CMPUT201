#include "maze.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Maze{
    char** grid;
    int* tile_num;
    int rows;
    int cols;
    struct Pos current;
    struct Pos start;
    int exit_num;
};

struct Pos find_tile(struct Maze* maze, char tile){
    struct Pos pos = {-1, -1};

    for(int i = 0; i < maze->rows; ++i)
        for(int j = 0; j < maze->cols; ++j)
            if(maze->grid[i][j] == tile){
                pos.x = j;
                pos.y = i;
                
                return pos;
            }

    return pos;
}

int count_tile(struct Maze* maze, char tile){
    int result = 0;

    for(int i = 0; i < maze->rows; ++i)
        for(int j = 0; j < maze -> cols; ++j)
            if(maze -> grid[i][j] == tile)
                result++;

    return result;
}

struct Pos find_teleporter(struct Maze* m, int y, int x){
    char known_teleporter = m->grid[y][x];

    for(int i = 0; i < m->rows; ++i)
        for(int j = 0; j < m->cols; ++j)
            if(m->grid[i][j] == known_teleporter && (i != y || j != x)){
                struct Pos pos = {j, i};
                return pos;
            }

    struct Pos pos = {y, x};
    return pos;
}

struct Maze *readMaze(){
    int capacity = 4;
    char* input = malloc(capacity * sizeof(char));
    int rows = 0;
    int cols = 0;
    char** lines = NULL;
    
    if(!input){
        printf("Initialization Error\n");
        return NULL;
    }

    input[0] = '\0';

    //Reads the maze line by line until receiving blank line
    
    while(1){
        size_t current_length = strlen(input);

        if(!fgets(input + current_length,capacity - current_length, stdin)){
            if(feof(stdin)) break;

            free(input);

            if(lines){
                for(int i = 0; i < rows; ++i)
                    free(lines[i]);
                free(lines);
            }

            return NULL;
        }

        size_t length = strlen(input);

        /*Since we are not given the specific size of 
        the maze, suggesting we should dynamically expand
        the input if the length of given input exceeds
        the maximum current capacity*/

        if(input[length - 1] != '\n' && !feof(stdin)){
            capacity *= 2;

            char* expanded_input = realloc(input, capacity);

            if(!expanded_input){
                printf("Expansion Error\n");
                free(input);

                if(lines){
                    for(int i = 0; i < rows; ++i)
                        free(lines[i]);
                    free(lines);
                }
                return NULL;
            }

            input = expanded_input;
            continue; // To go back and read the remaining part of the input
        }

        /*If the first element is a newline character,
        indicating this is a blank line then break the loop
        */

        

        if(input[0] == '\n') break;

        if(length > 0 && input[length - 1] == '\n'){
            input[length - 1] = '\0';
            length--;
        }

        if(length > cols) cols = length;

        /*Extra one is reserved for the null-terminator*/

        char* line = strdup(input);

        if(!line){
            free(input);

            if(lines){
                for(int i = 0; i < rows; ++i)
                    free(lines[i]);
                free(lines);
            }
            return NULL;
        }

        char** expanded_lines = realloc(lines, (rows + 1) * sizeof(char*));

        if(!expanded_lines){
            free(line);
            free(input);
            if(lines) free(lines);

            return NULL;
        }

       lines = expanded_lines;
       lines[rows++] = line;
       
       input[0] = '\0'; //Reset for the next line
    }

    free(input); //Remember to free the input array when finishing reading the maze

    struct Maze* maze = malloc(sizeof(struct Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->grid = malloc(rows * sizeof(char*));
    maze->tile_num = malloc(rows * sizeof(int));

    //tile_num[i] is used to record the number of tiles in each row (excluding the invisible walls)

    //Record the length before setting the invisible wall can resolve 'invisible wall' problem

    for(int i = 0; i < rows; ++i){
        maze->tile_num[i] = strlen(lines[i]);
        maze->grid[i] = malloc((cols + 1) * sizeof(char));
        strcpy(maze->grid[i], lines[i]);

        /*We choose the maximum value of number of elements among all rows
        as the number of columns of the maze
        
        There may exist a case where the border of the tile in some row 
        does not touch the border of column of the maze
        
        So we need to set walls from the border of the tile to
        the border of the maze*/

        int row_length = strlen(lines[i]);

        for(size_t j = row_length; j < cols; ++j)
            maze->grid[i][j] = 'X';

        maze->grid[i][cols] = '\0';
    }

    for(int i = 0; i < rows; ++i)
        free(lines[i]);

    free(lines);

    maze->start = find_tile(maze, 'S');
    maze->exit_num = count_tile(maze, 'G');

    if(maze->start.x == -1 || maze->start.y == -1 || maze->exit_num < 1){
        destroyMaze(maze);
        return NULL;
    }

    maze->current = maze->start;

    return maze;
    
}

struct Pos makeMove(struct Maze *m, char dir){
    struct Pos current_pos = m->current;

    int dx = 0, dy = 0;
    
    switch(dir){
        case 'n': dy = -1; break;
        case 's': dy = 1; break;
        case 'e': dx = 1; break;
        case 'w': dx = -1; break;

        default: return current_pos;
    }

    current_pos.x += dx;
    current_pos.y += dy;

    //Check bounds (Starting tile is always in the first quadrant)

    if(current_pos.x < 0 || current_pos.y < 0 || current_pos.x >= m->cols || current_pos.y >= m->rows)
        return m->current;

    //Check walls

    if(m->grid[current_pos.y][current_pos.x] == 'X')
        return m->current;

    //Check Teleporter

    if(m->grid[current_pos.y][current_pos.x] >= '0' && m->grid[current_pos.y][current_pos.x] <= '9'){
        //Check if we can find the paired teleporter in the grid

        struct Pos paired_teleporter = find_teleporter(m, current_pos.y, current_pos.x);

        current_pos = paired_teleporter;
    }

    while(m->grid[current_pos.y][current_pos.x] == 'I'){
        current_pos.x += dx;
        current_pos.y += dy;

        if (current_pos.x < 0 || current_pos.x >= m->cols || current_pos.y < 0 || current_pos.y >= m->rows){
            current_pos.x -= dx;
            current_pos.y -= dy;
            break;
        }

        if(m->grid[current_pos.y][current_pos.x] == 'X'){
            current_pos.x -= dx;
            current_pos.y -= dy;
            break;
        }

        if(m->grid[current_pos.y][current_pos.x] >= '0' && m->grid[current_pos.y][current_pos.x] <= '9'){
            //Check if we can find the paired teleporter in the grid
    
            struct Pos paired_teleporter = find_teleporter(m, current_pos.y, current_pos.x);
    
            current_pos = paired_teleporter;
            break;
        }
    }

    //Check if reaching the exit

    if(m ->grid[current_pos.y][current_pos.x] == 'G'){
        m->current = current_pos;

        struct Pos exit = {-1, -1};

        return exit;
    }

    //Update the current position

    if(m ->grid[current_pos.y][current_pos.x] == 'O' || 
    m->grid[current_pos.y][current_pos.x] == 'S' || m ->grid[current_pos.y][current_pos.x] == 'I' || (m->grid[current_pos.y][current_pos.x] >= '0' && m->grid[current_pos.y][current_pos.x] <= '9'))
        m->current = current_pos;

    return current_pos;
}

void reset(struct Maze *m){
    m->current = m->start;
}

void printMaze(struct Maze *m){
    //Top border
    for(int i = 0; i < m->cols + 2; ++i)
        printf("-");

    printf("\n");

    //Maze content

    for(int i = 0; i < m->rows; ++i){
        printf("|");

        for(int j = 0; j < m->tile_num[i]; ++j){
            if(i == m->current.y && j == m->current.x)
                printf("P");

            else printf("%c", m->grid[i][j]);
        }

        printf("|\n");
    }

    //Bottom border

    for(int i = 0; i < m->cols + 2; ++i)
        printf("-");

    printf("\n");
}

struct Maze *destroyMaze(struct Maze *m){
    if(m == NULL) return NULL;

    if(m->grid != NULL)
        for(int i = 0; i < m->rows; ++i)
            free(m->grid[i]);

        free(m->grid);

    if(m->tile_num != NULL) free(m->tile_num);

    free(m);
    return NULL;
}