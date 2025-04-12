int main(int argc, char **argv) {
  int x;
  int sum = 0;
  if (argc != 2) return 0;
  char *s = argv[1];
  while (*s) {
    sum = sum*10 + *s-'0';
    ++s;
  }
  return 2*sum;
}
