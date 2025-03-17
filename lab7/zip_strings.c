#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char *zipStrings(const char *s1, const char *s2) {
    // Takes two string parameters s1 and s2 of the same length
    // and returns a new heap allocated string that is the result of
    // "zipping" the two strings together.
    // e.g. zipStrings("abc", "xyz") -> "axbycz"

    char* result = malloc(sizeof(char)* (2 * strlen(s1) + 1));

    for(int i = 0; i < strlen(s1); ++i){
        result[2 * i] = s1[i];
        result[2 * i + 1] = s2[i];
    }

    /*0 -> (0,1)
    1 -> (2, 3)
    2 -> (4, 5)
    3 -> (6, 7)

    k -> (2k, 2k + 1) (0 <= k <= n - 1)

    n - 1 -> (2n - 2, 2n - 1)*/

    result[2 * strlen(s1)] = '\0';
    return result;
}


int main() {
    char s1[256];
    char s2[256];
    scanf("%s", s1);
    scanf("%s", s2);

    char *p = zipStrings(s1, s2);

    printf("%s\n", p);
    free(p);
}