#include<stdio.h>

int blah(){
    int z;
    printf("z: %d\n", z);
}

int main(){
    blah();
    int x;

    printf("%d\n", x);

    int y;

    printf("%d\n", y);

    blah();

    return 0;
}
