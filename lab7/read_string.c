#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readString() {
    int length = 0;
    int capacity = 1;

    char* str = malloc(sizeof(char)* capacity);

    if(str == NULL) return NULL;

    char ch;

    for(ch = getchar(); (ch == ' ' || ch == '\n' || ch == '\r'); ch = getchar());

    if(ch == EOF){
        free(str);
        return NULL;
    }

    int quote = (ch == '\"');

    if(quote) ch = getchar();

    while(1){
        if(ch == EOF || ((!quote) &&(ch == ' ' || ch == '\n' || ch == '\r')))
            break;

        if(quote && ch == '\"') break;

        if(length == capacity){
            char* tmp = malloc(sizeof(char)* (capacity + 1));

            if(tmp == NULL){
                free(str);
                return NULL;
            }

            for(int i = 0; i < length; ++i)
                tmp[i] = str[i];

            free(str);
            str = tmp;

            capacity++;
        }

        str[length] = ch;
        length++;

        ch = getchar();
    }

    str[length] = '\0';

    if(quote && ch != '\"'){
        free(str);
        return NULL;
    }

    return str;

}

int main() {
    char *p;
    while (p=readString()) {
        printf("%s\n", p);
        free(p);
    }
}
