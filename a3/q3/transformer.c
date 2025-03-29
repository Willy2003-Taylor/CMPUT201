#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int r, g, b;
}Pixel;

typedef struct{
    int width, height;
    Pixel** pixel;
}Image;

Image* read_image(){
    Image* IMG = malloc(sizeof(Image));
    char format[3];

    scanf("%2s", format);
    //Print size-two string, which is P3 in this question

    scanf("%d %d", &IMG -> width, &IMG -> height);

    int max_value;

    scanf("%d", &max_value);

    IMG -> pixel = malloc(IMG -> height * sizeof(Pixel*));
    for(int i = 0; i < IMG -> height; ++i)
        IMG -> pixel[i] = malloc(IMG -> width * sizeof(Pixel));

    for(int i = 0; i < IMG -> height; ++i){
        for(int j = 0; j < IMG -> width; ++j)
            scanf("%d %d %d", &IMG -> pixel[i][j].r, &IMG -> pixel[i][j].g, &IMG -> pixel[i][j].b);
    }

    return IMG;
}

void apply_sepia_filter(Image* IMG){
    for(int i = 0; i < IMG -> height; ++i){
        for(int j = 0; j < IMG -> width; ++j){
            Pixel pix = IMG -> pixel[i][j];

            int newR = (int)(pix.r * 0.393 + pix.g * 0.769 + pix.b * 0.189 + 0.5);
            int newG = (int)(pix.r * 0.349 + pix.g * 0.686 + pix.b * 0.168 + 0.5);
            int newB = (int)(pix.r * 0.272 + pix.g * 0.534 + pix.b * 0.131 + 0.5);

            IMG -> pixel[i][j].r = newR > 255 ? 255 : newR;
            IMG -> pixel[i][j].g = newG > 255 ? 255 : newG;
            IMG -> pixel[i][j].b = newB > 255 ? 255 : newB;
        }
    }
}

void flip_image(Image* IMG){
    for(int i = 0; i < IMG -> height; ++i){
        for(int j = 0; j < IMG -> width >> 1; ++j){
            Pixel tmp = IMG -> pixel[i][j];
            IMG -> pixel[i][j] = IMG -> pixel[i][IMG -> width - 1 - j];
            IMG -> pixel[i][IMG -> width - 1 - j] = tmp;
        }
    }
}

void print_image(Image* IMG){
    printf("P3\n%d %d\n255\n", IMG -> width, IMG -> height);

    for(int i = 0; i < IMG -> height; ++i){
        for(int j = 0; j < IMG -> width; j++){
            printf("%d %d %d", IMG -> pixel[i][j].r, IMG -> pixel[i][j].g, IMG -> pixel[i][j].b);

            if(j < IMG -> width - 1) printf(" ");
        }

        printf("\n");
    }
}

void free_image(Image* IMG){
    for(int i = 0; i < IMG -> height; ++i)
        free(IMG -> pixel[i]);

    free(IMG -> pixel);
    free(IMG);
}

int main(int argc, char* argv[]){
    int flip = 0, sepia = 0;

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-f") == 0) flip = 1;
        if(strcmp(argv[i], "-s") == 0) sepia = 1;
    }

    Image* IMG = read_image();

    if(flip) flip_image(IMG);
    if(sepia) apply_sepia_filter(IMG);

    print_image(IMG);
    free_image(IMG);

    return 0;
}