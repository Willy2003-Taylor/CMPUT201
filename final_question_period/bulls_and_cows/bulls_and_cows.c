#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  const char *code = argv[1];
  int len = strlen(code);
  char guess[11];
  int usedLetters[10];
  int count = 0;
  while (count < 6) {
    int cows = 0, bulls = 0;
    for (int i = 0; i < len; ++i) usedLetters[i] = 0;
    scanf("%10s", guess);
    for (int i = 0; i < len; ++i) {
      if (code[i] == guess[i]) {
        ++bulls;
        usedLetters[i] = 1;
      }
    }
    for (int i = 0; i < len; ++i) {
      if (code[i] == guess[i]) continue;
      for (int j = 0; j < len; ++j) {
        if (code[j] == guess[i] && !usedLetters[j]) {
          usedLetters[j] = 1;
          ++cows;
        }
      }
    }
    printf("%d bulls, %d cows\n", bulls, cows);
  }
}
